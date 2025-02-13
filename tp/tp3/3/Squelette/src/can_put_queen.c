#include "can_put_queen.h"

#define ABS(e) ( (e) >= 0 ? (e) : (-(e)) )

bool
can_put_queen(const int chessboard[], const int lin, const int col) {  
  for (int l = 0; l < lin; l ++) {
    if (chessboard[l] == col || ABS(chessboard[l] - col) == lin - l) {
      return false;
    }
  }
  return true; 
}
