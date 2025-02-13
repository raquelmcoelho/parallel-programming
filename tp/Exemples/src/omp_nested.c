/**
 * @mainpage
 *
 * Parallélisme imbriqué contrôlé via les variables d'environnement OMP_NESTED
 * et OMP_THREAD_LIMIT.
 *
 * @note par défaut, le parallélisme imbriqué est désactivé.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 * Calcule le terme d'ordre n de la suite de fibonacci.
 *
 * @param[in] n l'ordre du terme.
 * @return la valeur du terme.
 */
long fibonacci(int n);

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  int n1, n2;
  
#pragma omp parallel // Région #1
  {

#pragma omp single // Le premier thread dispo.
    n1 = omp_get_num_threads();
    
#pragma omp parallel // Région #2
    {

#pragma omp single
    n2 = omp_get_num_threads();      
         
    }
    
  }

  printf("n1 : %d\n", n1);
  printf("n2 : %d\n", n2);
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}

/*************
 * fibonacci *
 *************/

long
fibonacci(int n) {
  if (n < 2) {
    return n;
  }
  long a, b;
#pragma omp parallel num_threads(2)
  {
#pragma omp sections
    {
#pragma omp section
      a = fibonacci(n - 1);
#pragma omp section
      b = fibonacci(n - 2);
    }
  }
  return a + b;
}
