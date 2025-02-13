#include "omp_put_queen_v3.h"

#include <string.h>
#include <stdio.h>

/********************
 * omp_put_queen_v3 *
 ********************/

unsigned long
omp_put_queen_v3(int chessboard[],
                 const int dim,
                 const int lin,
                 const int col,
                 const int threads) {

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

  // Dans le cas contraire il faut traiter la ligne suivante. S'il le nombre
  // de threads disponible est supérieur à 1 alors nous créons deux tâches
  // qui se partagent les colonnes de la prochaine ligne. Ces tâches
  // nécessitent une copie locale de l'échiquier car le paramètre chessboard
  // n'est qu'un pointeur.
  unsigned long how_many = 0;
  
  if (threads > 1) {

#pragma omp task shared(how_many)
    {
      
      // Copie locale de l'échiquier.
      int my_chessboard[dim];
      memcpy(my_chessboard, chessboard, (lin + 1) * sizeof(int));

      // Compteur permettant de travailler localement. La mise à jour de
      // how_many n'a donc lieu qu'une fois le travail de la tâche terminé.
      unsigned long my_how_many = 0;

      /***********************
       * ... à compléter ... *
       ***********************/
      
    } // omp task

#pragma omp task shared(how_many) 
    {

      // Copie locale de l'échiquier.
      int my_chessboard[dim];
      memcpy(my_chessboard, chessboard, (lin + 1) * sizeof(int));

      // Compteur permettant de travailler localement. La mise à jour de
      // how_many n'a donc lieu qu'une fois le travail de la tâche terminé.
      unsigned long my_how_many = 0;

      /***********************
       * ... à compléter ... *
       ***********************/

    } // omp_task

    // Barrière de synchronisation explicite pour nos deux tâches.
#pragma omp taskwait
    
  }
  else {
    for (int c = 0; c < dim; c ++) {
      how_many += put_queen(chessboard, dim, lin + 1, c);
    }
  }

  // C'est terminé.
  return how_many;
  
}
