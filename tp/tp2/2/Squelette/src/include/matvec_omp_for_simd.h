#ifndef MATVEC_OMP_FOR_SIMD_H
#define MATVEC_OMP_FOR_SIMD_H

/**
 * Forme OpenMP de l'algorithme de multiplication matrice-vecteur
 * basée sur une boucle parallèle au niveau des lignes de la matrice
 * et une vectorisation au niveau de ses colonnes. Les tableaux ne se 
 * recouvrent pas et sont supposés être alignés sur des blocs de de 16 ou 32 
 * octets.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 */
void matvec_omp_for_simd(const float A[restrict],
                         const float x[restrict],
                               float b[restrict],
                         const unsigned size);

#endif
