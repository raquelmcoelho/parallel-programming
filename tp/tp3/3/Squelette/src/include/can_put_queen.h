#ifndef CAN_PUT_QUEEN_H
#define CAN_PUT_QUEEN_H

#include <stdbool.h>

/**
 * Indique si une dame peut être posée à la position (lin, col) d'un échiquier.
 *
 * @param[in] chessboard l'échiquier.
 * @param[in] lin la ligne.
 * @param[in] la colonne.
 * @return @c true si une dame peut peut être posée à cette position.
 */
bool can_put_queen(const int chessboard[], const int lin, const int col);

#endif
