#include <omp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
 * Compatabilise le nombre d'occurrences d'un entier.
 *
 * @param[in] head la tête de liste.
 * @param[in] elt l'entier recherché.
 * @return le nombre d'occurrences de l'entier recherché.
 */
unsigned long count(struct slist_t* head, int elt);

/**
 * Version OpenMP de la fonction count.
 *
 * @param[in] head la tête de liste.
 * @param[in] elt l'entier recherché.
 * @return le nombre d'occurrences de l'entier recherché.
 */
unsigned long omp_count(struct slist_t* head, int elt);

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

  // C'est parti.
  printf("count(2):\t%ld\n", count(head, 2));
  printf("omp_count(2):\t%ld\n", omp_count(head, 2));
  
  // C'est terminé.
  return EXIT_SUCCESS;
  
}

/*********
 * count *
 *********/

unsigned long
count(struct slist_t* head, int elt) {
  unsigned long res = 0;
  struct slist_t* cell = head;
  while (cell != NULL) {
    if (cell->elt == elt) {
      res ++;
    }
    cell = cell->next;
  }
  return res;
}

/*********
 * count *
 *********/

unsigned long
omp_count(struct slist_t* head, int elt) {
  unsigned long res = 0;

  // ... à compléter ...
  
  return res;
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
