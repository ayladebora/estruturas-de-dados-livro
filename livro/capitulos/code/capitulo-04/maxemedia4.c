#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "vector.c"

int main() {
  int count = 0;
  int total = 0;
  int largest = INT_MIN;
  Element i;

  Vector vector = createVector();
  V_Iterator it = getEnd(&vector);

  while( (scanf("%d",&i) == 1 ) ) {
    if(vector.size == 0 )
      prepend(&vector,i);
    else {
      insertAfter(&it,i);
      moveNext(&it);
    }
    if( i > largest) largest = i;
  }
  
  printf( "Valor máximo: %d\n", largest);
  it = getBegin(&vector);

  while( it.index < vector.size ) {
    i = getElement(&it);  
//    if( largest % i == 0 ) {
      total += i;
      count++;
//    }
    moveNext(&it);
  }
  if(count != 0)
    printf( "Média: %d\n", (total/count));
}
