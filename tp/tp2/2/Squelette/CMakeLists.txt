# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Packages requis.
FIND_PACKAGE( OpenSSL ) 

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Création des exécutables.
ADD_EXECUTABLE( bench              src/bench.c src/matvec.c                )
ADD_EXECUTABLE( bench_omp_for_i    src/bench.c src/matvec_omp_for_i.c      ) 
ADD_EXECUTABLE( bench_omp_for_j1   src/bench.c src/matvec_omp_for_j1.c     )
ADD_EXECUTABLE( bench_omp_for_j2   src/bench.c src/matvec_omp_for_j2.c     )
ADD_EXECUTABLE( bench_omp_simd     src/bench.c src/matvec_omp_simd.c       )
ADD_EXECUTABLE( bench_omp_for_simd src/bench.c src/matvec_omp_for_simd.c   )

ADD_EXECUTABLE(
  bench_vs_omp_for_i
  
  src/bench_vs.c
  src/matvec.c
  src/matvec_omp_for_i.c
)

ADD_EXECUTABLE(
  bench_vs_omp_for_j1

  src/bench_vs.c
  src/matvec.c
  src/matvec_omp_for_j1.c
)

ADD_EXECUTABLE(
  bench_vs_omp_for_j2
  
  src/bench_vs.c
  src/matvec.c
  src/matvec_omp_for_j2.c
)

ADD_EXECUTABLE(
  bench_vs_omp_simd
  
  src/bench_vs.c
  src/matvec.c
  src/matvec_omp_simd.c
)

ADD_EXECUTABLE(
  bench_vs_omp_for_simd
  
  src/bench_vs.c
  src/matvec.c
  src/matvec_omp_for_simd.c
  )

ADD_EXECUTABLE(
  word_generator

  src/word_generator.c
  src/word_gen.c
)

ADD_EXECUTABLE(
  brute_force

  src/brute_force.c
  src/word_gen.c
)

# Symboles pré-processeur nécessaires à la génération des exécutables.
TARGET_COMPILE_DEFINITIONS( bench              PRIVATE RAW          )
TARGET_COMPILE_DEFINITIONS( bench_omp_for_i    PRIVATE OMP_FOR_I    )
TARGET_COMPILE_DEFINITIONS( bench_omp_for_j1   PRIVATE OMP_FOR_J1   )
TARGET_COMPILE_DEFINITIONS( bench_omp_for_j2   PRIVATE OMP_FOR_J2   )
TARGET_COMPILE_DEFINITIONS( bench_omp_simd     PRIVATE OMP_SIMD     )
TARGET_COMPILE_DEFINITIONS( bench_omp_for_simd PRIVATE OMP_FOR_SIMD )

TARGET_COMPILE_DEFINITIONS( bench_vs_omp_for_i    PRIVATE OMP_FOR_I    )
TARGET_COMPILE_DEFINITIONS( bench_vs_omp_for_j1   PRIVATE OMP_FOR_J1   )
TARGET_COMPILE_DEFINITIONS( bench_vs_omp_for_j2   PRIVATE OMP_FOR_J2   )
TARGET_COMPILE_DEFINITIONS( bench_vs_omp_simd     PRIVATE OMP_SIMD     )
TARGET_COMPILE_DEFINITIONS( bench_vs_omp_for_simd PRIVATE OMP_FOR_SIMD )

# Librairies avec lesquelles linker certaines de nos applications.
TARGET_LINK_LIBRARIES( brute_force OpenSSL::SSL OpenSSL::Crypto )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

