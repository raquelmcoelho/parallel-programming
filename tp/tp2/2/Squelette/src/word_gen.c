#include "word_gen.h"

/**
 * Implémentation récursive interne (le mot-clé static garantit l'invisibilité
 * au niveau du fichier compilé word_gen.o).
 *
 * @param[in] charset l'alphabet.
 * @param[in] how_many la longueur des mots à générer.
 * @param[in] cb le callback à invoquer.
 * @param[in] cb_params les paramètres du callback.
 * @param[in] prefix le mot en cours de construction.
 * @return the callback result.
 */
static bool word_gen_generate_impl(char* charset,
				   int how_many,
				   callback_t cb,
				   void* cb_params,
				   char* prefix);

/*********************
 * word_gen_generate *
 *********************/

void
word_gen_generate(char* charset,
		  int how_many,
		  callback_t cb,
		  void* cb_params) {
  char* prefix = (char*) malloc(1);
  prefix[0] = '\0';
  word_gen_generate_impl(charset, how_many, cb, cb_params, prefix);
}

/*************************
 * word_gen_omp_generate *
 *************************/

void
word_gen_omp_generate(char* charset,
		      int how_many,
		      callback_t cb,
		      void* cb_params) {
  
  // ... à compléter ...
}


/**************************
 * word_gen_generate_impl *
 **************************/

bool
word_gen_generate_impl(char* charset,
		       int how_many,
		       callback_t cb,
		       void* cb_params,
		       char* prefix) {
  if (how_many == 0) {
    return (*cb)(prefix, cb_params);
  }
  const int prefix_len = strlen(prefix);
  bool again = true;
  for (size_t i = 0; i < strlen(charset) && again; i ++) {
    char* new_prefix = (char*) malloc(prefix_len + 2);
    strcpy(new_prefix, prefix);
    new_prefix[prefix_len] = charset[i];
    new_prefix[prefix_len + 1] = '\0';
    again = word_gen_generate_impl(charset,
				   how_many - 1,
				   cb,
				   cb_params,
				   new_prefix);
  }
  free(prefix);
  return again;
}
