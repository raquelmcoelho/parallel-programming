#ifndef SOLVE_N_QUEENS_H
#define SOLVE_N_QUEENS_H

#include "put_queen.h"

/**
 * Implémentation récursive et séquentielle du problème des n-reines.
 *
 * @param[in] dim la dimension du problème.
 * @return le nombre de solutions du problème.
 */
unsigned long solve_n_queens(const int dim);

#endif
