#ifndef merge_n_hpp
#define merge_n_hpp

#include <algorithm>

namespace merging {

  /**
   * Permet de fusionner les n premiers éléments de deux conteneurs pré-ordonnés
   * selon la même relation d'ordre total.
   *
   * @param[in] first1 - un itérateur repérant le premier élément du premier
   *   conteneur.
   * @param[in] last1  - un itérateur repérant l'élément situé derrière le
   *   dernier élément du premier conteneur.
   * @param[in] first2 - un itérateur repérant le premier élément du second
   *   conteneur.
   * @param[in] last2  - un itérateur repérant l'élément situé derrière le
   *   dernier élément du second conteneur.
   * @param[in] result - un itérateur repèrant le prochain emplacement d'accueil
   *   dans le conteneur cible.
   * @param[in] n      - le nombre maximum d'éléments à fusionner.
   * @param[in] comp   - un comparateur binaire représentant la relation d'ordre
   *   total.
   * @return un itérateur repèrant l'élément situé juste derrière le dernier
   *   élément accueilli dans le conteneur cible de la fusion.
   */
  template< typename InputIterator1,
	    typename InputIterator2,
	    typename OutputIterator,
	    typename Size,
	    typename Compare >
  OutputIterator
  merge_n(InputIterator1 first1, InputIterator1 last1,
	  InputIterator2 first2, InputIterator2 last2,
	  OutputIterator result,
	  Size n,
	  Compare comp) {

    // Nous bouclons tant que le compte n'y est pas.
    while (n > 0) {

      // Nous sommes arrivés à la fin du premier conteneur : ne restent que les
      // éléments du second.
      if (first1 == last1) {
	return std::copy_n(first2, std::min< Size >(n, last2 - first2), result);
      } // if

      // Nous sommes arrivés à la fin du second conteneur : ne restent que les
      // éléments du premier.
      if (first2 == last2) {
	return std::copy_n(first1, std::min< Size >(n, last1 - first1), result);
      } // if

      // Nous choisissons le plus petit des deux éléments (au sens de la 
      // relation d'ordre total utilisée) et nous avonçons conjointement dans le
      // conteneur correspondant et le conteneur cible de la fusion.
      *result ++ = comp(*first1, *first2) ? *first1 ++ : *first2 ++;

      // Un élément de moins à fusionner.
      n --;

    } // while

    // Retourner l'itérateur balayant le conteneur cible.
    return result;

  } // merge_n
  
  /**
   * Permet de fusionner les n premiers éléments de deux conteneurs pré-ordonnés
   * selon la relation d'ordre total "strictement inférieur à".
   *
   * @param[in] first1 - un itérateur repérant le premier élément du premier
   *   conteneur.
   * @param[in] last1  - un itérateur repérant l'élément situé derrière le
   *   dernier élément du premier conteneur.
   * @param[in] first2 - un itérateur repérant le premier élément du second
   *   conteneur.
   * @param[in] last2  - un itérateur repérant l'élément situé derrière le
   *   dernier élément du second conteneur.
   * @param[in] result - un itérateur repèrant le prochain emplacement d'accueil
   *   dans le conteneur cible.
   * @param[in] n      - le nombre maximum d'éléments à fusionner.
   * @return un itérateur repèrant l'élément situé juste derrière le dernier
   *   élément accueilli dans le conteneur cible de la fusion.
   */
  template< typename InputIterator1,
	    typename InputIterator2,
	    typename OutputIterator,
	    typename Size >
  OutputIterator
  merge_n(InputIterator1 first1, InputIterator1 last1,
	  InputIterator2 first2, InputIterator1 last2,
	  OutputIterator result,
	  Size n) {

    // Type synonyme pour le type des éléments du premier conteneur (qui est
    // supposé évidemment compatible avec ceux du second). 
    typedef std::iterator_traits< InputIterator1 > Traits;
    typedef typename Traits::value_type value_type;

    // Fabriquer le comparateur less puis invoquer la fonction définie 
    // ci-dessus.
    return merge_n(first1, last1, 
		   first2, last2,
		   result,
		   n,
		   std::less< const value_type& >());

  } // merge_n

} // merging

#endif
