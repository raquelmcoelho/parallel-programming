#ifndef MATVEC_OMP_FOR_J2_H
#define MATVEC_OMP_FOR_J2_H

/**
 * Forme OpenMP de l'algorithme de multiplication matrice-vecteur
 * basée sur une boucle parallèle au niveau des colonnes de la
 * matrice. La région parallèle est maximisée afin de contenir la boucle
 * sur les lignes de la matrice.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 */
void matvec_omp_for_j2(const float A[],
                       const float x[],
                             float b[],
                       const unsigned size);

#endif
