#ifndef OMP_SOLVE_N_QUEENS_V3_H
#define OMP_SOLVE_N_QUEENS_V3_H

#include "omp_put_queen_v3.h"

/**
 * Implémentation parallèle basée sur des tâches.
 *
 * @param[in] dim la dimension du problème.
 * @return le nombre de solutions du problème.
 */
unsigned long omp_solve_n_queens_v3(const int dim);

#endif
