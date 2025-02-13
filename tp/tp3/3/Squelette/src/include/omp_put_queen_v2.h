#ifndef OMP_PUT_QUEEN_V2_H
#define OMP_PUT_QUEEN_V2_H

#include "put_queen.h"

/**
 * Version parallèle de la fonction put_queen basée sur l'utilisation de
 * sections parallèles.
 *
 * @param[in, out] chessboard l'échiquier.
 * @param[in] dim la dimension de l'échiquier.
 * @param[in] lin la ligne.
 * @param[in] la colonne.
 * @param[in] threads le nombre de threads disponibles.
 * @return le nombre de solutions au départ de la case.
 */
unsigned long omp_put_queen_v2(int chessboard[],
                               const int dim,
                               const int lin,
                               const int col,
                               const int threads);

#endif
