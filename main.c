#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void){
  char input[256];
  char *pathstart = "C:/Users/henry/";
  char path[271];
  puts("Enter quit or q to exit");
  loop:
  while(true){
    printf("%s", "$> ");
    scanf("%s", input);
    int size = strlen(input);
    if (size > 256){
      puts("Input size is to large");
      goto loop;
    }
    if (!strcmp(input, "quit") || !strcmp(input, "q")){
      exit(0);
    }
    utils_concat(path, 272, pathstart, input);
  }
  int size = strlen(pathstart);
  utils_puti(size);
  return 0;
}
