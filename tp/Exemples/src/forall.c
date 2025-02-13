/**
 * @mainpage
 *
 * Boucles de type forall c'est à dire indépendantes de l'ordre d'évaluation
 * de leurs itérations.
 */

#include <stdlib.h>

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  const int n = 128;
  int t[n];
  
  // Forall ? oui.
  for (int i = 0; i < n; i ++) {
    t[i] = i;
  }

  // Forall ? non.
  t[0] = 0;
  for (int i = 1; i < n; i ++) {
    t[i] = t[i - 1] + 2;
  }

  // Forall ? oui (addition commutative + associative).
  int acc = 0;
  for (int i = 0; i < n; i ++) {
    acc += t[i];
  }

  // t = { 1, -2, 3 }
  // acc = 0 + 1 -2 + 3 = 2
  // acc = 0 + 3 -2 + 1 = 2
  // acc = 0 -2 + 1 + 3 = 2
  // acc = 0 + (1 + -2) + 3 = 0 -1 + 3 = 2 => associativité
  // acc = 0 + (3 + 1) -2 = 2 => commutativité
 
  // Forall ? non (soustraction associative mais pas commutative).
  acc = 0;
  for (int i = 0; i < n; i ++) {
    acc -= t[i];
  }
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}
