/**
 * @mainpage
 *
 * Modèle de programmation à parallélisme de contrôle via les sections
 * parallèles.
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

  const int n = 128;
  int tab_1[n], tab_2[n];

#pragma omp parallel num_threads(2)
  {

#pragma omp sections
    {

#pragma omp section
      {
	printf("%d\n", omp_get_num_threads());
	
         // Une boucle for non parallélisable.
	tab_1[0] = 0;
	for (int i = 1; i < n; i ++) {
          tab_1[i] = 2 * tab_1[i - 1] + 3;
        }
	
      }

#pragma omp section      
      {
	
        // Une autre boucle for non parallélisable.
	tab_2[n - 1] = 20;
	for (int i = n - 2; i >= 0; i --) {
          tab_2[i] = tab_2[i + 1] - 5;
        }

      }  

    } // Barrière implicite.

  }

  // C'est terminé.
  return EXIT_SUCCESS;
  
}

