/**
 * @mainpage
 *
 * Les tâches : des jobs qui seront exécutés "plus tard" par les
 * threads d'une région parallèle.
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

  const int n = 128;
  int tab_1[n], tab_2[n];  // Données partagées.

#pragma omp parallel
  {
    int locale = 5; // Données locales au thread.
    int titi;

#pragma omp single // L'un des threads approvisionne la file de  
    {              // tâches, les autres attendent.

      // Les données partagées restent partagées dans une tâche.
      // Les données locales font l'objet d'une clause firstprivate.
#pragma omp task // firstprivate(locale, titi)
      {	
	// Une boucle for non parallélisable.
	tab_1[0] = 0;
	for (int i = 1; i < n; i ++) {
	  tab_1[i] = 2 * tab_1[i - 1] + 3;
	}
      }

#pragma omp task
      {	
	// Une autre boucle for non parallélisable.
	tab_2[n - 1] = 20;
	for (int i = n - 2; i >= 0; i --) {
	  tab_2[i] = tab_2[i + 1] - 5;

	}
      }

    } // Les autres attendent ici.

    // Les threads exécutent les tâches de la file.
    
  }

#pragma omp parallel
  {

#pragma omp single // Créer l'ensemble des jobs initiaux.
    {
      // Suite de Fibonacci.
      printf("%ld\n", fibonacci(8)); // Double Ended Queue (DEQUE)
                                     // Contenu initial = { fibo(8) }
    }

    
  }
  

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
  // Contenu = { fibo(7), fibo(6), fibo(8 : a, b) }
#pragma omp task shared(a, b)
  {
    a = fibonacci(n - 1);
  }
  
#pragma omp task shared(a, b)
  {
    b = fibonacci(n - 2);
  }

#pragma omp taskwait
  
  return a + b;
}
