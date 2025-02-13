/**
 * @mainpage
 *
 * Comparaisons d'une implémentation séquentielle de l'algorithme du tri fusion
 * avec différentes implémentation parallèles OpenMP.
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "solve_n_queens.h"
#include "omp_solve_n_queens_v1.h"
#include "omp_solve_n_queens_v2.h"
#include "omp_solve_n_queens_v3.h"

/**
 * Type résumant les caractéristiques d'une implémentation parallèle.
 */
struct parallel_t {
  int threads;       /** Nombre de threads utilisés.                          */
  double seq;        /** Durée d'exécution du meilleur algorithme séquentiel. */
  double par;        /** Durée d'exécution du meilleur algorithme parallèle.  */
  double speedup;    /** Speedup.                                             */
  double efficiency; /** Efficacité.                                          */
};

/**
 * Constructeur de résumé.
 *
 * @param[in] threads le nombre de threads utilisés.
 * @param[in] seq la durée d'exécution du meilleur algorithme séquentiel.
 * @param[in] par la durée d'exécution du meilleur algorithme parallèle.
 * @return un résumé.
 */
struct parallel_t make(const int threads, const double seq, const double par);

/**
 * Affiche le résumé des performances d'une implémentation parallèle sur la
 * sortie standard.
 *
 * @param[in] msg un message d'annonce.
 * @param[in] abstract le résumé.
 */
void display(const char* msg, const struct parallel_t abstract);

/**
 * Programme principal.
 *
 * @param[in] argc le nombre d'arguments de la ligne de commandes.
 * @param[in] argv les arguments de la ligne de commandes.
 * @return @c EXIT_SUCCESS.
 */
int
main(int argc, char* argv[]) {

  // La ligne de commandes est vide : l'utilisateur demande de l'aide.
  if (argc == 1) {
    printf("Usage: %s dim\n", argv[0]);
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments de la ligne est différent de 2 : l'utilisateur
  // fait n'importe quoi.
  if (argc != 2) {
    fprintf(stderr, "Nombre d'argument(s) incorrect\n");
    return EXIT_FAILURE;
  }

  // Tentative d'extraction de la dimension de l'échiquier.
  int dim;
  {    
    char foo;

    // argv[1] doit contenir une chaîne de caractères répondant à la syntaxe
    // d'un entier. De plus ce dernier doit être strictement positif.
    if (sscanf(argv[1], "%d%c", &dim, &foo) != 1 || dim <= 0) {
      fprintf(stderr, "Argument %s incorrect\n", argv[1]);
      return EXIT_FAILURE;    
    }   
  }
  
  // Version séquentielle.
  unsigned long res_seq;
  double time_seq;
  {
    const double start = omp_get_wtime();
    res_seq = solve_n_queens(dim);
    const double stop = omp_get_wtime();
    time_seq = stop - start;
  }

  // Obtention du nombre de threads disponibles.
  int threads;
#pragma omp parallel
#pragma omp single
  threads = omp_get_num_threads();
  
  // Version parallèle #1 (boucle for // sur fonction solve_n_queens).
  {
    const double start = omp_get_wtime();
    const unsigned long res_par = omp_solve_n_queens_v1(dim);
    const double stop = omp_get_wtime();

    if (res_par != res_seq) {
      fprintf(stderr, "omp_solve_n_queens_v1: bad_result\n");
      return EXIT_FAILURE;
    }

    const struct parallel_t abstract = make(threads, time_seq, stop - start);
    display("--[ omp_solve_n_queens_v1 ] --", abstract);
    printf("\n");
  }

  // Version parallèle #2 (sections // sur fonction put_queen).
  {
    const double start = omp_get_wtime();
    const unsigned long res_par = omp_solve_n_queens_v2(dim);
    const double stop = omp_get_wtime();
  
    if (res_par != res_seq) {
      fprintf(stderr, "omp_solve_n_queens_v2: bad_result\n");
      return EXIT_FAILURE;
    }

    const struct parallel_t abstract = make(threads, time_seq, stop - start);
    display("--[ omp_solve_n_queens_v2 ] --", abstract);
    printf("\n");
  }

  // Version parallèle #3 (tâches sur fonction put_queen).
  {
    const double start = omp_get_wtime();
    const unsigned long res_par = omp_solve_n_queens_v3(dim);
    const double stop = omp_get_wtime();

    if (res_par != res_seq) {
      fprintf(stderr, "omp_solve_n_queens_v3: bad_result\n");
      return EXIT_FAILURE;
    }

    const struct parallel_t abstract = make(threads, time_seq, stop - start);
    display("--[ omp_solve_n_queens_v3 ] --", abstract);
    printf("\n");
  }  
  
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}

/********
 * make *
 ********/

struct parallel_t
make(const int threads, const double seq, const double par) {
  const struct parallel_t abstract = {
    threads,
    seq,
    par,
    seq / par,
    seq / par / threads
  };
  
  return abstract;
}

/***********
 * display *
 ***********/

void
display(const char* msg, const struct parallel_t abstract) {
  printf("%s\n", msg);
  printf("threads   :\t%d\n", abstract.threads);
  printf("seq. time :\t%f (s)\n", abstract.seq);
  printf("par. time :\t%f (s)\n", abstract.par);
  printf("speedup   :\t%f\n", abstract.speedup);
  printf("efficiency:\t%f\n", abstract.efficiency);
}
