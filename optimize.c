#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_VARS 1000

char lines[MAX_LINES][256];
int used[MAX_LINES];
int line_count = 0;

int is_number(const char *s) {
    if (*s == '-' || *s == '+') s++;
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

char *get_lhs(const char *line) {
    static char lhs[32];
    sscanf(line, "%31s =", lhs);
    return lhs;
}
int var_used_in_line(const char *line, const char *var) {
    return strstr(line, var) && (strstr(line, var) != line); 
}

void optimize_tac(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        perror("Cannot open input TAC file");
        exit(1);
    }

    // Load all lines
    while (fgets(lines[line_count], sizeof(lines[0]), in)) {
        used[line_count] = 0;
        line_count++;
    }
    fclose(in);

    // Phase 1: constant folding
    for (int i = 0; i < line_count; i++) {
        char lhs[32], op1[32], op2[32], op[4];
        if (sscanf(lines[i], "%s = %s %s %s", lhs, op1, op, op2) == 4) {
            if (is_number(op1) && is_number(op2)) {
                int result = 0;
                int n1 = atoi(op1), n2 = atoi(op2);
                if (strcmp(op, "+") == 0) result = n1 + n2;
                else if (strcmp(op, "-") == 0) result = n1 - n2;
                else if (strcmp(op, "*") == 0) result = n1 * n2;
                else if (strcmp(op, "/") == 0) result = (n2 != 0) ? n1 / n2 : 0;

                sprintf(lines[i], "%s = %d\n", lhs, result);
            }
        }
    }

    // Phase 2: usage analysis
    for (int i = line_count - 1; i >= 0; i--) {
        char lhs[32];
        strcpy(lhs, get_lhs(lines[i]));

        // If it's a return or assignment to a real variable, mark as used
        if (strstr(lines[i], "return") || (lhs[0] != 't')) {
            used[i] = 1;
            continue;
        }

        // If lhs is used in any later line, mark it as used
        for (int j = i + 1; j < line_count; j++) {
            if (var_used_in_line(lines[j], lhs)) {
                used[i] = 1;
                break;
            }
        }
    }

    // Write optimized output
    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("Cannot open output TAC file");
        exit(1);
    }

    fprintf(out, "# Optimized TAC\n");
    for (int i = 0; i < line_count; i++) {
        if (used[i] || strstr(lines[i], "return")) {
            fputs(lines[i], out);
        }
    }

    fclose(out);
}
