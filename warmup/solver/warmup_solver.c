#include "../include/warmup_solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char OUTPUT_DIR[] = "output/";
const char SOLUTION_FILE[] = "solution.txt";

int morse_to_value(char c) {
    switch (c) {
        case '.': return 1;
        case '-': return 5;
        case ':': return 2;
        case '=': return 10;
        default: return 0;
    }
}

int parse_morse_number(const char* morse) {
    int value = 0;
    for (int i = 0; morse[i] != '\0'; i++) {
        value += morse_to_value(morse[i]);
    }
    return value;
}

int evaluate_expression(int values[], char operators[], int n) {
    int result = values[0];
    for (int i = 0; i < n; i++) {
        if (operators[i] == '+') {
            result += values[i + 1];
        } else if (operators[i] == '*') {
            result *= values[i + 1];
        }
    }
    return result;
}

int solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {
    FILE *fwsolptr;
    int n;
    char expression[100][10];

    if (fscanf(ptr_in_file, "%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < 2 * n + 1; i++) {
        if (fscanf(ptr_in_file, "%s", expression[i]) != 1) {
            return 0;
        }
    }

    int values[n + 1];
    char operators[n];

    for (int i = 0; i < 2 * n + 1; i++) {
        if (i % 2 == 0) {
            values[i / 2] = parse_morse_number(expression[i]);
        } else {
            operators[i / 2] = expression[i][0];
        }
    }

    int result = evaluate_expression(values, operators, n);

    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        return 0;
    }

    fprintf(fwsolptr, "%d\n", result);
    fclose(fwsolptr);

    return 1; // sucesso
}
