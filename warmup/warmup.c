#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "include/warmup_solver.h"

const char WARMUP_INSTANCE[] = "02-aritmetica-morse/";
const char INPUT_DIR[] = "input/";
const char FILE_PREFIX[] = "instance_";

int main() {
    DIR *dir;
    FILE *fptr;
    int total_success = 0, total_failures = 0;
    struct dirent *str_dir;
    char input_dir[200], file_path[200];

    input_dir[0] = '\0';
    strcat(input_dir, WARMUP_INSTANCE);
    strcat(input_dir, INPUT_DIR);

    dir = opendir(input_dir);

    if (dir) {
        int prefix_length = strlen(FILE_PREFIX);

        while ((str_dir = readdir(dir)) != NULL) {
            if (strncmp(str_dir->d_name, FILE_PREFIX, prefix_length) != 0) {
                continue;
            }

            file_path[0] = '\0';
            strcat(file_path, input_dir);
            strcat(file_path, str_dir->d_name);

            fptr = fopen(file_path, "r");
            if (fptr == NULL) {
                printf("Erro ao abrir o arquivo '%s'\n", file_path);
                total_failures++;
                continue;
            }

            printf("Resolvendo: %s\n", str_dir->d_name);

            if (solve_warmup(fptr, str_dir->d_name, WARMUP_INSTANCE)) {
                total_success++;
            } else {
                total_failures++;
            }

            fclose(fptr);
        }


        printf("Total de sucessos: %d\n", total_success);
        printf("Total de falhas: %d\n", total_failures);

        closedir(dir);
    } else {
        printf("Erro ao abrir o diretório: %s\n", input_dir);
    }

    return 0;
}
