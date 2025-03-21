#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "include/warmup_solver.h"

const char FILE_PREFIX[] = "instance_";

int main() {
    DIR *dir;
    FILE *fptr;
    int success, total_success, total_failures;
    struct dirent *str_dir;
    char input_dir[200], file_path[200];


    //Caminho completo até a pasta input
    strcpy(input_dir, "C:\\Users\\Remakker\\OneDrive\\Área de Trabalho\\AritmeticaMorse\\programacao-avancada\\warmup\\02-aritmetica-morse\\input\\");

    printf("Tentando abrir o diretório: %s\n", input_dir);

    dir = opendir(input_dir);

    if (dir == NULL) {
        printf("Erro ao abrir o diretório '%s'. Verifique o caminho e as permissões.\n", input_dir);
        return 1;
    }

    printf("Diretório aberto com sucesso.\n");

    int prefix_length = strlen(FILE_PREFIX);
    total_success = total_failures = 0;

    printf("Iniciando processamento dos arquivos...\n");

    while ((str_dir = readdir(dir)) != NULL) {
        if (strncmp(str_dir->d_name, FILE_PREFIX, prefix_length)) {
            continue;
        }

        printf("Processando arquivo: %s\n", str_dir->d_name);

        file_path[0] = '\0';
        strcat(file_path, input_dir);
        strcat(file_path, str_dir->d_name);

        fptr = fopen(file_path, "r");
        if (fptr == NULL) {
            printf("Erro ao abrir o arquivo '%s'.\n", file_path);
            return 1;
        }

        printf("Resolvendo o arquivo: %s\n", str_dir->d_name);
        solve_warmup(fptr, str_dir->d_name, "02-aritmetica-morse");

        printf("Verificando a solução do arquivo: %s\n", str_dir->d_name);
        success = check_warmup_solution(str_dir->d_name, "02-aritmetica-morse");

        printf("Test %s %s.\n", str_dir->d_name, success ? "SUCCESS" : "FAILURE");

        if (success) {
            total_success++;
        } else {
            total_failures++;
        }

        fclose(fptr);
    }

    printf("Total de Sucessos: %d\n", total_success);
    printf("Total de Falhas: %d\n", total_failures);

    closedir(dir);

    return 0;
}
