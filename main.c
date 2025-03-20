#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_CMD 10
#define MAX_INPUT 100
#define MAX_PATH 115

/*
    mv
  find dir, rmdir, mkdir, mv dir, pwd
*/

void help(){
  char line[50];
  FILE *file = fopen("help.txt", "r");
  if (file == NULL){
    perror("Failed to open file");
  }
  else {
    while(fgets(line, 50, file)!= NULL){
      printf("%s\n", line);
    }
    fclose(file);
  }
}

void filecmd(char cmd[],char path[], char *pathstart, char arg[]){
  if (!strcmp(cmd, "cat")){
    char line[256];
    FILE *file = fopen(arg, "r");
    if (file == NULL){
      perror("Failed to open file");
    }
    else {
      while(fgets(line, 256, file)!= NULL){
      printf("%s\n", line);}
      fclose(file);
    }
  }
  if(!strcmp(cmd, "find")){
      FILE *file = fopen(arg, "r");
      if (file == NULL){
        puts("File not found");
      }
      else {
        puts("File found");
        fclose(file);
      }
  }
  if(!strcmp(cmd, "touch")){
    FILE *file = fopen(arg, "r");
    if (file == NULL){
      fopen(arg, "w");
      fclose(file);
      puts("File created");
    }
    else {
      puts("A file by that name aready exsit");
    }
  }
  if(!strcmp(cmd, "rm")){
    if(remove(arg) == 0) puts("File deleted");
    else puts("File failed to delete");
  }
  if(!strcmp(cmd, "mv")){
    
  }
}

void dircmd(char cmd[],char path[], char *pathstart, char arg[]){
  if (!strcmp(cmd, "ls")){
      char dst[118];
      utils_concat(path, MAX_PATH, pathstart, arg);
      // for(int i = 0; i < 115; i++){
      //   path[i] = arg[i];
      // }
      utils_concat(dst, MAX_PATH, "dir ", path);
      if (system(dst) != 0 ) puts(strerror(errno));
    }
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
    if (!strcmp(cmd, "clear")){
      if (system("cls") != 0 ) puts(strerror(errno)); 
    }
    if (!strcmp(cmd, "help")) help();
    
    
    dircmd(cmd, path,pathstart,arg);
    filecmd(cmd, path, pathstart, arg);
    
  }
  return 0;
}
