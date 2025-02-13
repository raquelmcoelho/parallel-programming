#ifndef PUT_QUEEN_H
#define PUT_QUEEN_H

#include "can_put_queen.h"

/**
 * Retourne le nombre de solutions au départ de la case (lin, col) d'un
 * échiquier.
 *
 * @param[in, out] chessboard l'échiquier.
 * @param[in] dim la dimension de l'échiquier.
 * @param[in] lin la ligne.
 * @param[in] la colonne.
 * @return le nombre de solutions au départ de la case.
 */
unsigned long put_queen(int chessboard[],
                        const int dim,
                        const int lin,
                        const int col);

#endif
