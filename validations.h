/* 
 * File:   validations.h
 *
 * Created on 12 de Junho de 2010, 13:21
 */

#ifndef _VALIDATIONS_H
#define	_VALIDATIONS_H

/***********************************
 * External Function References
 ************************************/

/* Valida um float capturado da entrada padrão. */
extern int validate_number_float(char *input);
/* Valida um integer capturado da entrada padrão. */
extern int validate_number_int(char *input);
/* Valida um número ID natural capturado da entrada padrão. */
extern int validate_id(char *input);

#endif	/* _VALIDATIONS_H */

