#ifndef WORD_GEN_H
#define WORD_GEN_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Callback à invoquer lorsqu'un nouveau mot à été généré.
 *
 * @param[in] word le nouveau mot alloué dynamiquement.
 * @param[in] params les paramètres du callback.
 * @return @c true si un autre mot doit être généré sinon @c false.
 *
 * @note penser à désallouer le mot transmis lorsque celui-ci devient inutile.
 */
typedef bool (*callback_t)(char* word, void* params);

/**
 * Génére (algorithme séquentiel) tous les mots d'une longueur particulière à 
 * partir d'un alphabet et invoque un callback pour chaque mot généré (alloué 
 * dynamiquement).
 *
 * @param[in] charset l'alphabet.
 * @param[in] how_many la longueur des mots à générer.
 * @param[in] cb le callback à invoquer.
 * @param[in] cb_params les paramètres du callback.
 */
void word_gen_generate(char* charset,
		       int how_many,
		       callback_t cb,
		       void* cb_params);

/**
 * Génére (algorithme parallèle) tous les mots d'une longueur particulière à 
 * partir d'un alphabet et invoque un callback pour chaque mot généré (alloué 
 * dynamiquement).
 *
 * @param[in] charset l'alphabet.
 * @param[in] how_many la longueur des mots à générer.
 * @param[in] cb le callback à invoquer.
 * @param[in] cb_params les paramètres du callback.
 */
void word_gen_omp_generate(char* charset,
			   int how_many,
			   callback_t cb,
			   void* cb_params);

#endif
