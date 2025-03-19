#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_CMD 10
#define MAX_INPUT 100
#define MAX_PATH 115

/*
  find, cat, touch, rm, mv
  find dir, rmdir, mkdir, mv dir, pwd
*/

void help(){
  //read from help file
}

int main(void){
  char cmd[MAX_CMD];
  char arg[MAX_INPUT];
  char *pathstart = "C:\\Users\\henry\\";
  char path[MAX_PATH];
  puts("Enter quit -y or q -y to exit");
  loop:
  while(true){
    printf("%s", "$> ");
    scanf("%s%s", cmd, arg);    
    int size1 = strlen(cmd);
    int size2 = strlen(arg);
    if (size1 > MAX_CMD || size2 > MAX_INPUT){
      puts("Input size is too large");
      goto loop;
    }
    if (!strcmp(cmd, "quit") || !strcmp(cmd, "q")) exit(0);
    if (!strcmp(cmd, "ls")){
      char dst[118];
      utils_concat(path, MAX_PATH, pathstart, arg);
      utils_concat(dst, MAX_PATH, "dir ", path);
      if (system(dst) != 0 ){
       puts(strerror(errno));
     }
    }
    if (!strcmp(cmd, "clear")){
      if (system("cls") != 0 ) puts(strerror(errno)); 
    }
    if(!strcmp(cmd, "set")){
      pathstart = arg;
      printf("Path set to %s\n", pathstart);
    }
  }
  return 0;
}
