/**
 * @mainpage
 *
 * Parallélisation de boucles for.
 */

#include <stdlib.h>

/**
 * Un type lourd en mémoire et son renommage pré-processeur.
 */
typedef struct {
  int a;
  double t[1024];
} my_type_t;

//#define T my_type_t
#define T double

/**
 * Fonction factoriel.
 *
 * @param[in] n l'ordre du terme.
 * @return la valeur du terme.
 */
int fact(int n);

/**
 * Retourne le carré d'un entier.
 *
 * @param[in] e l'entier.
 * @return son carré.
 */
int square(int e);

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  int (*func_ptr)(int n);
  
  const int n = 128;
  int tab[n];
  T other_tab[n];

  // Nature : homogène. Logiquement, schedule(static).
  // Mais risque de false sharing puisque écritures
  // dans des éléments de tableaux.
#pragma omp parallel
  {
#pragma omp for schedule(auto)    
    for (int i = 0; i < n; i ++) {
      tab[i] = i;
    } // Barrière implicite.
  }
 
  // Nature : quasi-homogène.
  int acc = 0;
#pragma omp parallel reduction(+:acc)
  {
    // Equivalent à schedule(static, 1) ?
    // Sémantiquement équivalent mais problèmatique
    // en termes d'efficacité car ça gène les
    // optimisations du compilateur.
#pragma omp for schedule(static)      
    for (int i = 0; i < n; i ++) {
      if (tab[i] == 5) {
        acc ++;
      } 
    }
  }

  // Nature : hétérogène. Logiquement, schedule(dynamic)
  // ou schedule(guided).
  // Mais risque de false sharing puisque écritures
  // dans des éléments de tableaux.
#pragma omp parallel
  {
#pragma omp for schedule(auto)    
    for (int i = 0; i < n; i ++) {
      tab[i] = fact(i);
    }
  }

  // Nature : quasi-homène. Logiquement, schedule(static).
  // Mais risque de false sharing puisque écritures
  // dans des éléments de tableaux.
#pragma omp parallel
  {
#pragma omp for schedule(auto)   
    for (int i = 0; i < n; i ++) {
      if (tab[i] != 0) {
	tab[i] = square(i);
      }
    }
  }

  // Nature : inconnue (dépend de T).
#pragma omp parallel
  {
#pragma omp for schedule(auto)   
    for (int i = 0; i < n - 1; i ++) {
      if (tab[i] < tab[i + 1]) {
	other_tab[i] = other_tab[i + 1];
      }
    }
  }

  // Nature : inconnue (dépend de la fonction pointée).
  /* func_ptr = fact; */
  func_ptr = square;
#pragma omp parallel
  {
#pragma omp for schedule(auto)  
    for (int i = 0; i < n; i ++) {
      tab[i] = (*func_ptr)(i);
    }
  }
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}

/********
 * fact *
 ********/

int
fact(int n) {
  return n == 0 ? 1 : n * fact(n - 1);
}

/**********
 * square *
 **********/

int
square(int e) {
  return e * e;
}
