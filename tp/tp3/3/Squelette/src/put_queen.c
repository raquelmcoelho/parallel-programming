#include "put_queen.h"

unsigned long
put_queen(int chessboard[], const int dim, const int lin, const int col) {

  // Impossible de poser une dame à cette position : l'exploration de la
  // branche s'arrête.
  if (! can_put_queen(chessboard, lin, col)) {
    return 0;
  }

  // La position n'étant pas menacée nous la conservons.
  chessboard[lin] = col;

  // La dernière ligne venant d'être traitée nous tenons une nouvelle solution.
  if (lin == dim - 1) {
    return 1;
  }

  // Dans le cas contraire il faut traiter la ligne suivante.
  unsigned long how_many = 0;
  for (int c = 0; c < dim; c ++) {
    how_many += put_queen(chessboard, dim, lin + 1, c);
  }

  // C'est terminé.
  return how_many;
  
}
