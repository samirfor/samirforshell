/* 
 * File:   main.h
 *
 * Created on 21 de Maio de 2010, 15:25
 */

#ifndef _MAIN_H
#define	_MAIN_H

/***********************************
 * External Function References
 ************************************/

/* Returns the current user */
extern char * get_usuario();
/* Returns the local hostname */
extern char * get_maquina();
/* Returns the initial working directory */
extern char * get_caminho_inicial();
/* Returns the current working directory */
extern char * get_caminho_atual();
/* Clears the screen */
extern void * limpar_tela();
/* Handler for cd command */
extern int do_cd(char * comando);
/* Allows use of regular expressions in C.
 * Returns TRUE if the pattern match.
 * Returns FALSE if the pattern does not match. */
extern int regexp_match(char *pattern, char *string);
/* Strip whitespace from the beginning and end of a string */
extern void trim(char * str);

#endif	/* _MAIN_H */

