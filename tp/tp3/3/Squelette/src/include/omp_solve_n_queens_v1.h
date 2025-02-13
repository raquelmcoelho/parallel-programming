#ifndef OMP_SOLVE_N_QUEENS_V1_H
#define OMP_SOLVE_N_QUEENS_V1_H

#include "put_queen.h"

/**
 * Implémentation parallèle basée sur une boucle parallèle for.
 *
 * @param[in] dim la dimension du problème.
 * @return le nombre de solutions du problème.
 */
unsigned long omp_solve_n_queens_v1(const int dim);

#endif
