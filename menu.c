#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>
#include "readline/readline.h"
#include "readline/history.h"

char **splitnsep(char *input, char *sym);
char *fireblanks(char *input);

int main() {
  FILE * intro;
  char * lid = NULL;
  size_t size = 0;
  ssize_t red;
  intro = fopen("intro.txt", "r");
  int counter = 0;
  while ((red = getline(&lid, &size, intro)) != -1) {
    printf("%s", lid);
    counter++;
    if (counter%20==0){
      printf("\e[2J\e[H");
      usleep(40000);
    }
  }
  fclose(intro);
  printf("\nWhat is your name?: ");
  char input[60];
  fgets(input, sizeof(input), stdin);
  input[strlen(input)-1] = 0;
  char **pieces;
  pieces = splitnsep(input, ";");
  char *name;
  int i;
  for (i = 0; pieces[i] != NULL; i++) {
    char * c1 = (char*)(malloc(100));
    char ** c2 = (char**)(malloc(100));
    c1 = fireblanks( pieces[i] );
    c2 = splitnsep(c1, " ");
    char *cdstr;
    //if( !strcmp(c2[0], "exit") ) {
    char *name = c2[0];
    printf("\rHello %s!\n\n\n", name);
  }
  sleep(1);
  printf("How many drums do you want to play with? (max 7):\n");
  printf("Respond in letter fromat:\n");
  printf("with 1 drum set as A\n");
  printf("with 2 drum sets as B\n");
  printf("with 3 drum sets as C\n");
  printf("...\n\n- ");
  
  int forever = 0;
  while(forever == 0){
  char ainput[60];
  fgets(ainput, sizeof(ainput), stdin);
  ainput[strlen(ainput)-1] = 0;
  char **apieces;
  apieces = splitnsep(ainput, ";");
  char *aname;
  int ai;
  for (ai = 0; apieces[ai] != NULL; ai++) {
    char * ac1 = (char*)(malloc(100));
    char ** ac2 = (char**)(malloc(100));
    ac1 = fireblanks( apieces[ai] );
    ac2 = splitnsep(ac1, " ");
    char *acdstr;
    if( !strcmp(ac2[0], "A") ) {
      forever = 1;
    }
    else {
      printf("\nIncorrect Format! Redo: ");
    }
    }
  }
  return 0;
}


char **splitnsep(char *input, char *sym) {
  char *temp = input;
  
  int i = 0;
  
  char **arr = (char **)(malloc(100));
  
  while (temp) {
    arr[i] = strsep(&temp, sym);
    i++;
  }
  
  arr[i] = NULL;
  
  return arr;
}


char *fireblanks(char *input) {
  
  char *temp = (char*)(malloc(100));
  
  int i = 0;
  
  while(input[i]) {
  
    if ( !(input[i]==' ' && (strlen(temp)==0 || input[i+1] == ' ' || !(input[i+1]))) ) {
      sprintf(temp, "%s%c", temp, input[i]);
  
    }
  
    i++;
  }
  
  return temp;
}
