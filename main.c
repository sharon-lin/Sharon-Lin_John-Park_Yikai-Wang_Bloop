#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

//#include "print_ascii.c"
//#include "server.c"
//#include "client.c"

int main(){

  char d[1024];
  char *dest = d;

  //********************
  //   Start of loop
  //********************

  while(1){
    printf("Music sequence: ");
    fgets(dest, 256, stdin); // Need to limit this to abcd for display
    // Alternatively, need to figure out "global display" of scrolling notes and local 
    // display of notes to be added to the global display



    if(!*(dest+1)) continue;
    system("ffplay piano1.mp3");
  }

  // Plan of work:
  //      - Opens to menu
  //      - Display of drums
  //      - Display of keys (a,b,c,d,s (save), p (pause), f (finish))
  //      - Plays drums after if it is one of the above
  //      - Will not play sound or note the key if it isn't abcd
  // Functions:
  //      - Allows multiple users to access same display
  //      - Allows individuals to save current sequence
  //      - Twitch plays drums

  while(1){
    //Functions for processing music
  }

  return 0;
}
