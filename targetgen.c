#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_LINE_LEN 256
#define MAX_TEXT_LEN 8192

char *vars[MAX_VARS];
int var_count = 0;

int is_declared(const char *v) {
    for (int i = 0; i < var_count; ++i)
        if (strcmp(vars[i], v) == 0) return 1;
    return 0;
}

void declare(FILE *data, const char *v) {
    if (!is_declared(v)) {
        fprintf(data, "%s: dq 0\n", v);
        vars[var_count++] = strdup(v);
    }
}
void generate_target_code(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    FILE *data = fopen("data.tmp", "w+");  

    if (!in || !out || !data) {
        fprintf(stderr, "File error: in = %p, out = %p, data = %p\n", in, out, data);
        perror("fopen");
        exit(1);
    }

    char line[256];
    char all_text[8192] = "";

    // Assembly header
    fprintf(out, "; Generated x86-64 NASM code\n");
    fprintf(out, "global main\n");

    while (fgets(line, sizeof(line), in)) {
        char lhs[32], rhs1[32], rhs2[32], op[4];

        if (sscanf(line, "%s = %s %s %s", lhs, rhs1, op, rhs2) == 4) {
            declare(data, lhs);
            declare(data, rhs1);
            declare(data, rhs2);

            sprintf(line, "    mov rax, [%s]\n", rhs1); strcat(all_text, line);

            if (strcmp(op, "+") == 0)
                sprintf(line, "    add rax, [%s]\n", rhs2);
            else if (strcmp(op, "-") == 0)
                sprintf(line, "    sub rax, [%s]\n", rhs2);
            else if (strcmp(op, "*") == 0)
                sprintf(line, "    imul rax, [%s]\n", rhs2);
            else if (strcmp(op, "/") == 0) {
                strcat(all_text, "    xor rdx, rdx\n");
                sprintf(line, "    div qword [%s]\n", rhs2);
            }
            strcat(all_text, line);

            sprintf(line, "    mov [%s], rax\n", lhs); strcat(all_text, line);

        } else if (sscanf(line, "%s = %s", lhs, rhs1) == 2) {
            declare(data, lhs);
            if (isdigit(rhs1[0]) || (rhs1[0] == '-' && isdigit(rhs1[1])))
                sprintf(line, "    mov rax, %s\n    mov [%s], rax\n", rhs1, lhs);
            else {
                declare(data, rhs1);
                sprintf(line, "    mov rax, [%s]\n    mov [%s], rax\n", rhs1, lhs);
            }
            strcat(all_text, line);
        } else if (strstr(line, "return")) {
            char ret[32];
            sscanf(line, "return %s", ret);
            declare(data, ret);
            sprintf(line, "    mov rax, [%s]\n    ret\n", ret);
            strcat(all_text, line);
        }
    }

    // Write final output
    fprintf(out, "section .text\nmain:\n");
    fputs(all_text, out);

    fprintf(out, "section .data\n");
    rewind(data);
    while (fgets(line, sizeof(line), data))
        fputs(line, out);

    fclose(in);
    fclose(out);
    fclose(data);
}
