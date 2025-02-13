/**
 * @mainpage
 *
 * Sélection du nombre de threads par défaut via la variable d'environnement
 * OMP_NUM_THREADS.
 *
 * @note La fonction int omp_get_thread_num() de la bibliothèque OpenMP retourne
 *   l'identifiant du thread au sein d'une région parallèle. 
 *
 * @note La fonction int omp_get_num_threads() retourne le nombre de threads 
 *   disponibles pour exécuter une région parallèle.
 *
 * @note Un région séquentielle est toujours exécutée par le thread maître
 *   c'est à dire celui dont l'identifiant vaut 0. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {
  
  // Une région séquentielle (exécutée par le thread maître).
  printf("C'est parti (thread %d)\n", omp_get_thread_num());
  
  // Une région parallèle (fork).
#pragma omp parallel
  {

    // Seul le thread maître affiche le nombre de threads disponibles sur
    // la sortie standard.
    if (omp_get_thread_num() == 0) {
      printf("Nombre de threads disponibles : %d\n", omp_get_num_threads()); 
    }
    
  } // Barrière de synchronisation implicite (join).

  // C'est terminé.
  return EXIT_SUCCESS;
  
}
