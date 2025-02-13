#ifndef OMP_SOLVE_N_QUEENS_V2_H
#define OMP_SOLVE_N_QUEENS_V2_H

#include "omp_put_queen_v2.h"

/**
 * Implémentation parallèle basée sur des sections.
 *
 * @param[in] dim la dimension du problème.
 * @return le nombre de solutions du problème.
 */
unsigned long omp_solve_n_queens_v2(const int dim);

#endif
