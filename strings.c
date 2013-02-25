/* 
 * File:   strings.c
 *
 * Created on 26 de Maio de 2010, 14:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "strings.h"
#include "exceptions.h"
#include "status.h"
#include "validations.h"

/*
 * String module
 */

char *read_string(char *str) {
    __fpurge(stdin);
    *str = NON_EXIST;
    gets(str);
    if (!strcasecmp(str, "sair")) {
        printf("Finalizando o programa a pedido do usuario.\n");
        exit(EXIT_SUCCESS);
    }
}

char * input_malloc() {
    char *input = malloc(200 * sizeof (char));

    if (!input) {
        printf(ALLOC_ERROR, __FILE__);
        exit(1);
    }
    strcpy(input, "");
    return input;
}

int check_by_name(char *input) {
    printf("Qual nome? ");
    read_string(input);

    if (strlen(input) < 2) {
        printf("%s: Nao ha caracteres suficientes para a pesquisa.\n", __FILE__);
        return FALSE;
    }
    return TRUE;
}

int be_sure(char *input) {
    do {
        printf("Digite [s] para confirmar ou [n] abortar: ");
        read_string(input);
    } while (*input != 's' && *input != 'n' && *input != 'S' && *input != 'N');
    if (*input == 's' || *input == 'S') {
        return TRUE;
    } else {
        return FALSE;
    }
}

int input_overflow(char *string, char *input) {
    if (strlen(input) > strlen(string))
        return TRUE;
    else
        return FALSE;
}
