#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Programme principal.
 *
 * @param[in] argc le nombre d'arguments de la ligne de commandes.
 * @param[in] argv les arguments de la ligne de commandes.
 *
 * @return @c EXIT_SUCCESS en cas d'exécution réussie sinon @c EXIT_FAILURE.
 */
int
main(int argc, char* argv[]) {

  // La ligne de commandes est vide : l'utilisateur demande de l'aide.
  if (argc == 1) {
    printf("Usage: %s nb_points\n", argv[0]);
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments est différent de 2 : l'utilisateur fait n'importe
  // quoi.
  if (argc != 2) {
    fprintf(stderr, "Nombre d'arguments incorrect\n");
    return EXIT_FAILURE;
  }

  // Tentative d'extraction du nombre de points d'intégration.
  long nb_points;
  {
    char dummy; // Pour vérifier que l'on bien un entier et pas qqch come 12t.
    
    if (sscanf(argv[1], "%ld%c", &nb_points, &dummy) != 1 || nb_points < 1) {
      fprintf(stderr, "Argument %s incorrect\n", argv[1]);
      return EXIT_FAILURE;
    }
  }

  // Résultat final.
  double res = 0.0;

  // Pas d'integration.
  const double h = 1.0 / nb_points;
  
  // C'est parti.
  for (long i = 0; i < nb_points; i ++) {
    const double x = h * (i - 0.5);
    res += 4.0 / (1.0 + x * x);
  }
  res *= h;

  // Affichage du résultat sur la sortie standard.
  printf("%f\n", res);

  // C'est terminé.
  return EXIT_SUCCESS;
  
}
