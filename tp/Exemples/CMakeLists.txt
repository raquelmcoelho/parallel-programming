# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C 2011.
SET( CMAKE_C_FLAGS "-std=c11")

# Création des exécutables.
ADD_EXECUTABLE( omp_num_threads src/omp_num_threads.c )
ADD_EXECUTABLE( spmd            src/spmd.c            )
ADD_EXECUTABLE( omp_nested      src/omp_nested.c      )
ADD_EXECUTABLE( forall          src/forall.c          )
ADD_EXECUTABLE( conditions_for  src/conditions_for.c  )
ADD_EXECUTABLE( corps_de_boucle src/corps_de_boucle.c )
ADD_EXECUTABLE( parallel_for    src/parallel_for.c    ) 
ADD_EXECUTABLE( omp_section     src/omp_section.c     )
ADD_EXECUTABLE( omp_task        src/omp_task.c        )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

