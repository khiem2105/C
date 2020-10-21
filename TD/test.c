#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
 char *s = (char*)malloc(12*sizeof(char));
 char *t = (char*)malloc(15*sizeof(char));
 strcpy(s, "good");
 strcpy(t, "hi there");
 char *p = t+4;
 t = s;
 strcat(s, "bye");
 printf("s = %s\n", s);
 printf("t = %s\n", t);
 printf("p = %s\n", p);
 free(s); free(t);
 return 0;
}