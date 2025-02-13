#ifndef MATVEC_OMP_FOR_I_H
#define MATVEC_OMP_FOR_I_H

/**
 * Forme OpenMP de l'algorithme de multiplication matrice-vecteur
 * basée sur une boucle parallèle au niveau des lignes de la
 * matrice. La clause de répartition des itérations utilisée runtime c'est
 * à dire décidée au moment de l'exécution via la variable d'environnement
 * OMP_SCHEDULE.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 */
void matvec_omp_for_i(const float A[],
                      const float x[],
                            float b[],
                      const unsigned size);

#endif
