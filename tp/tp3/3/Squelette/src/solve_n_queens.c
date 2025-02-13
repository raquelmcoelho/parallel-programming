#include "solve_n_queens.h"

unsigned long
solve_n_queens(const int dim) {

  // Nombre de solutions.
  unsigned long how_many = 0;

  // Echiquier.
  int chessboard[dim];

  // Nous comptabilisons le nombre de solutions trouvée au départ de chaque
  // case de la première ligne.
  for (int c = 0; c < dim; c ++) {
    how_many += put_queen(chessboard, dim, 0, c);
  }

  // C'est terminé.
  return how_many;
  
}
