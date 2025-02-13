/**
 * @mainpage
 *
 * Implémentation du modèle de programmation Single Program Multiple Data
 * (parallélisme de données) sur liste chaînée à l'aide d'une simple région
 * parallèle.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 * Cellule d'une liste d'entiers simplement chaînée.
 */
struct slist_t {

  /** L'entier. */
  int elt;

  /** Un pointeur vers la cellule suivante. */
  struct slist_t* next;
  
};

/**
 * Ajoute un entier en tête de liste.
 *
 * @param[in] head la tête de liste actuelle.
 * @param[in] elt l'entier.
 * @return la nouvelle tête de liste.
 */
struct slist_t* push_front(struct slist_t* head, int elt);

/**
 * Affiche tous les éléments d'une liste sur la sortie standard.
 *
 * @param[in] head la tête de liste.
 */
void print(struct slist_t* head);

/**
 * Initialise tous les éléments d'un liste à une valeur par défaut.
 *
 * @param[in, out] head la tête de liste.
 * @param[in] val la valeur par défaut.
 */
void fill(struct slist_t* head, int val);

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  // La tête de liste.
  struct slist_t* head = NULL;

  // Nous ajoutons quelques entiers.
  for (int i = 0; i < 10; i ++) {
    head = push_front(head, i % 3);
  }

  // Premier affichage.
  print(head);

  // Ré-initialisation.
  fill(head, 10);

  // Deuxième affichage.
  printf("\n");
  print(head);
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}

/**************
 * push_front *
 **************/

struct slist_t*
push_front(struct slist_t* head, int elt) {
  struct slist_t* cell = (struct slist_t*) malloc(sizeof (struct slist_t));
  cell->elt = elt;
  cell->next = head;
  return cell;
}

/*********
 * print *
 *********/

void
print(struct slist_t* head) {
  struct slist_t* cell = head;
  while (cell != NULL) {
    printf("%d\n", cell->elt);
    cell = cell->next;
  }  
}

/********
 * fill *
 ********/

void
fill(struct slist_t* head, int val) {
    struct slist_t* cell = head;

#pragma omp parallel firstprivate(cell) // Mix clause + déclaration intérieure.
    { // Coût de création des threads manquants (overhead).
    const int tid = omp_get_thread_num();
    const int steps = omp_get_num_threads();

    // Tenter de se positionner sur la cellule initiale (overhead).
    for (int i = 0; i < tid && cell != NULL; i ++, cell = cell->next);

    // Traiter la cellule courante et tenter de se positionner sur la suivante
    // (overhead).
    while (cell != NULL) {
      cell->elt = val;
      for (int i = 0; i < steps && cell != NULL; i ++, cell = cell->next);
    }
    
  } // Barrière de synchronisation implicite.
  // Coût de destruction des threads manquants (overhead).
}
