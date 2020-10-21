#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
char *local_time(char *filename) {
 struct tm *tm_ptr;
 struct stat stat_block;
 char *buffer = malloc(sizeof(char)*120);
 /* get the sourcefile's timestamp in time_t format */
 stat(filename, &stat_block);
 /* convert UNIX time_t into a struct tm holding local time */
 tm_ptr = localtime(&stat_block.st_mtime);
 /* convert the tm struct into a string in local format */
 strftime(buffer, 120*sizeof(char), "%a %b %e %T %Y", tm_ptr);
 //printf("File date: \t\t%s\n", buffer);
 return buffer;
}
int main(int argc, char **argv) {
 if (argc != 2)
 return 1;
 char *buf = local_time(argv[1]);
 printf("Information for %s\n", argv[1]);
 printf("---------------------------\n");
 printf("File date: \t\t%s\n", buf);
 free(buf);
 return 0;
}
