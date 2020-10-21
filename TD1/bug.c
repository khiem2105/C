#include <stdio.h>
#include <time.h>
int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
int main(){
 int d = -1, x = 0;
//  printf("%ld",TOTAL_ELEMENTS);
 if (d <= (int)(TOTAL_ELEMENTS - 2))
    x = array[d + 1];
 printf("x = %d \n", x);
 return 0;
}