/**
 * @mainpage 
 *
 * Directive barrier.
 */

#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  // Obtention du nombre de threads disponibles.
  int threads;
#pragma omp parallel
  {
#pragma omp single
    threads = omp_get_num_threads();
  }
  
  // Déclaration d'un tableau avec un emplacement par thread.
  int values[threads];

#pragma omp parallel
  {

    // ... à compléter ...

  }

  // Affichage du tableau sur la sortie standard.
  for (int i = 0; i < threads; i ++) {
    printf("%d\t", values[i]);
  }
  printf("\n");
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}
