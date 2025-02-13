#include "omp_solve_n_queens_v2.h"

#include <omp.h>

unsigned long
omp_solve_n_queens_v2(const int dim) {
    
  // Echiquier.
  int chessboard[dim];

  // Obtention du nombre de threads disponibles.
  int threads;
#pragma omp parallel
#pragma omp single
  threads = omp_get_num_threads();

  // Nombre de solutions.
  unsigned long how_many = 0;

  // Nous comptabilisons le nombre de solutions trouvée au départ de chaque
  // case de la première ligne.
  for (int c = 0; c < dim; c ++) {
    how_many += omp_put_queen_v2(chessboard, dim, 0, c, threads);
  }

  // C'est terminé.
  return how_many;
  
}
