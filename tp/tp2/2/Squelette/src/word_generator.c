/**
 * @mainpage 
 *
 * Ecrit tous les mot d'une longueur donnée produits à partir d'un alphabet
 * sur la sortie standard.
 */

#include "word_gen.h"
#include <stdio.h>

/**
 * Le callback à invoquer pour chaque mot généré.
 *
 * @param[in, out] word le mot généré.
 * @param[in] les paramètres du callback (ici aucun).
 * @return @c true.
 */
bool print(char* word, void* no_param);

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
    printf("Usage:\n\t%s charset length\n", argv[0]);
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments est différent de 3 : l'utilisateur fait n'importe
  // quoi.
  if (argc != 3) {
    fprintf(stderr, "Incorrect argument number\n");
    return EXIT_FAILURE;
  }

  // Tentative d'extraction de la longueur des mots à générer.
  int how_many;
  {
    char dummy; // Pour vérifier que l'on a bien un entier et pas qqch comme 12t.
    
    if (sscanf(argv[2], "%d%c", &how_many, &dummy) != 1 || how_many < 1) {
      fprintf(stderr, "Incorrect argument %s\n", argv[2]);
      return EXIT_FAILURE;
    }
  }

  // C'est parti.
  word_gen_generate(argv[1], how_many, print, NULL);
  
  // Tout est ok.
  return EXIT_SUCCESS;
  
}

/*********
 * print *
 *********/

bool
print(char* word, void* no_param) {
  printf("%s\n", word);
  free(word);
  return true;
}
