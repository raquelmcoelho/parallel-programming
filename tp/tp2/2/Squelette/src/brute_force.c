/**
 * @mainpage 
 *
 * Casse un mot de passe crypté en SHA1 via une méthode brute force parallèle.
 *
 * @note pour générer un signature SHA1 à partir d'un mot de passe :
 *   echo -n "mon_mot_de_passe" | sha1sum | awk '{print $1}'
 */

#include "word_gen.h"

#include <openssl/sha.h>
#include <omp.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Le callback à invoquer pour chaque mot généré.
 *
 * @param[in, out] word le mot généré.
 * @param[in] les paramètres du callback (ici la signature SHA du mot mystère).
 * @return @c true.
 */
bool mismatch(char* word, void* param);

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
    printf("Usage:\n\t%s charset word_length sha1_hex_string\n", argv[0]);
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments est différent de 4: l'utilisateur fait n'importe
  // quoi.
  if (argc != 4) {
    fprintf(stderr, "Incorrect argument number\n");
    return EXIT_FAILURE;
  }

  // Tentative d'extraction de la longueur des mots à générer.
  int word_length;
  {
    char dummy; // Pour vérifier que l'on a bien un entier et pas qqch comme 12t.
    
    if (sscanf(argv[2], "%d%c", &word_length, &dummy) != 1 || word_length < 1) {
      fprintf(stderr, "Incorrect argument %s\n", argv[2]);
      return EXIT_FAILURE;
    }
  }

  // Vérification et chargement de la signature sha1.
  unsigned char target_hash[SHA_DIGEST_LENGTH];
  {
    bool ok = strlen(argv[3]) == 2 * SHA_DIGEST_LENGTH;
    if (ok) {
      for (size_t i = 0; i < 40 && ok; i ++) {
	switch (argv[3][i]) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'A':
	case 'b':
	case 'B':
	case 'c':
	case 'C':
	case 'd':
	case 'D':
	case 'e':
	case 'E':
	case 'f':
	case 'F':
	  break;
	default:
	  ok = false;
	}
      }
    }
    if (! ok) {
      fprintf(stderr, "Incorrect argument %s\n", argv[3]);
      return EXIT_FAILURE;
    }
    for (int i = 0, j = 0; i < 2 * SHA_DIGEST_LENGTH; i += 2, j ++) {
      sscanf(argv[3] + i, "%2hhx", &target_hash[j]);
    }
  }

  // Timing de la version séquentielle.
  double seq;
  {
    const double start = omp_get_wtime();
    word_gen_generate(argv[1],
		      word_length,
		      mismatch, (unsigned char*) target_hash);
    const double stop = omp_get_wtime();
    seq = stop - start;    
  }

  // Timing de la version parallèle.
  double par;
  {
    const double start = omp_get_wtime();
    word_gen_omp_generate(argv[1],
			  word_length,
			  mismatch, (unsigned char*) target_hash);
    const double stop = omp_get_wtime();
    par = stop - start;    
  }  

  // Nombre de threads utilisés.
  int threads;
#pragma omp parallel
#pragma omp single
  threads = omp_get_num_threads();

  // Calcul des facteurs d'accélération et d'efficacité.
  const double speedup    = seq / par;
  const double efficiency = speedup / threads;  

  // Affichage des performances sur la sortie standard.
  printf("Seq. time (s):\t%f\n", seq);
  printf("Par. time (s):\t%f\n", par);
  printf("Thread(s)    :\t%d\n", threads);
  printf("Speedup      :\t%f\n", speedup);
  printf("Efficiency   :\t%f\n", efficiency);   
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}
  
/************
 * mismatch *
 ************/

bool
mismatch(char* word, void* param) {

  // ... à compléter ...
  return false;

}
