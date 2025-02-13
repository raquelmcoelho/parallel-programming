/**
 * @mainpage
 *
 * Boucles de type for parallélisables.
 */

#include <stdlib.h>

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  const int n = 127;
  int t[n];

  // Oui.
  for (int i = 0; i < n; i += 2) {
    t[i] = i;
  }

  // Non (impossible de pré-calculer le nombre d'itérations à répartir car
  // la condition de continuation utilise == ou !=.
  for (int i = 0; i != n; i += 2) {
    t[i] = i;
  }

  // Non : indice non entier (impossible de pré-calculer le nombre d'itérations
  // à répartir).
  for (double x = 0.0; x < 3.1415; x += 2.1);

  // Non : boucle non forall.
  int acc = 0;
  for (int i = 0; i < n; i ++) {
    acc -= t[i];
  }

  // C'est terminé.
  return EXIT_SUCCESS;
  
}
