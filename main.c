/* 
 * File:   main.c
 *
 * Created on 26 de Abril de 2010, 14:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>        
#include "strings.h"
#include "status.h"
#include "exceptions.h"

/*
Copyright (C) 2013 Samir C. Costa <samirfor@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

char * get_usuario() {
    char *str = getenv("USER");
    return str;
}

char * get_maquina() {
    char *str = input_malloc();
    strcpy(str, "localhost");
    gethostname(str, 25);
    return str;
}

char * get_caminho_inicial() {
    char *str = getenv("PWD");
    return str;
}

char * get_caminho_atual() {
    //    char *str = get_current_dir_name();
    char *str = getcwd(NULL, 0);
    return str;
}

void limpar_tela() {
    system("clear");
}

int do_cd(char * comando) {
    char* caminho;
    int cod_retorno;

    strtok(comando, " ");
    caminho = strtok(NULL, " ");
    //    printf("%s\n", caminho);
    cod_retorno = chdir(caminho);
    if (cod_retorno == -1) {
        printf("Ops, diretorio nao encontrado.\n");
        //        printf("\t+ Erro: %s\n", strerror();
        return 0;
    }
    return 1;
}

int regexp_match(char *pattern, char *string) {
    regex_t regex;
    int ret;
    char msgbuf[100];

    /* Compile regular expression */
    ret = regcomp(&regex, pattern, 0);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        return FALSE;
    }

    /* Execute regular expression */
    ret = regexec(&regex, string, 0, NULL, 0);
    if (!ret) {
        return TRUE; // match!
    } else if (ret == REG_NOMATCH) {
        return FALSE; // no match :(
    } else {
        regerror(ret, &regex, msgbuf, sizeof (msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return FALSE;
    }

    /* Free compiled regular expression if you want to use the regex_t again */
    regfree(&regex);
}

int main(int argc, char *argv[]) {
    printf("::: S@mirforShell :::\n\n");
    printf(">>> Criado por Samir <samirfor@gmail.com>\n");
    printf("Este programa esta sob a GNU General Public License v3 <http://www.gnu.org/licenses/>\n");
    printf("Para finalizar o programa use o comando \"sair\"\n\n");

    char * input;
    char * usuario;
    char * caminho_atual;
    char * maquina;

    usuario = get_usuario();
    caminho_atual = get_caminho_inicial();
    maquina = get_maquina();
    input = input_malloc();
    do {
        printf("+%s em %s::%s$ ", usuario, maquina, caminho_atual);
        read_string(input);

        //        if (strstr(input, "cd ")) {
        if (regexp_match("^cd ", input)) {
            // Manipula no caso do comando cd
            do_cd(input);
            caminho_atual = get_caminho_atual();
        } else if (!strcasecmp(input, "limpar")) {
            // Manipula o comando limpar
            limpar_tela();
        } else {
            // Outros comandos, cria um subprocesso para executar
            system(input);
        }
    } while (strcmp(input, "sair"));
    return EXIT_SUCCESS;
}
