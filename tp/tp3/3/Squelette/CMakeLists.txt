# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Création des exécutables.
ADD_EXECUTABLE(
  bench

  src/bench.c
  src/can_put_queen.c
  src/put_queen.c
  src/solve_n_queens.c
  src/omp_solve_n_queens_v1.c
  src/omp_put_queen_v2.c
  src/omp_solve_n_queens_v2.c
  src/omp_put_queen_v3.c
  src/omp_solve_n_queens_v3.c
)

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

