# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Création des exécutables.
ADD_EXECUTABLE( serial  src/serial.c  )
ADD_EXECUTABLE( barrier src/barrier.c )
ADD_EXECUTABLE( count   src/count.c   )
ADD_EXECUTABLE( pi      src/pi.c      )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

