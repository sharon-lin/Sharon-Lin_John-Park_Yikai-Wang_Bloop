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

#include "networking.h"
//#include "networking.c"

void process( char * s );
void sub_server( int sd );


int main(){

  int sd, connection;

  sd = server_setup();
    
  while (1) {

    connection = server_connect( sd );

    int f = fork();
    if ( f == 0 ) {

      close(sd);
      sub_server( connection );

      exit(0);
    }
    else {
      close( connection );
    }
  }
  return 0;
}


void sub_server( int sd ) {

  char buffer[MESSAGE_BUFFER_SIZE];
  while (read( sd, buffer, sizeof(buffer) )) {

    printf("[SERVER %d] received: %s\n", getpid(), buffer );
    process( buffer );
    write( sd, buffer, sizeof(buffer));    
  }
  
  }



void play_sound(char * sequence){

  int length = (int)strlen(sequence);

  for (int i =0;i<length;i++){
    if (sequence[i]=='A')
      system("mpg123 sounds/sound1.mp3");
    else if (sequence[i]=='a')
      system("mpg123 sounds/sound1.mp3");
    else if (sequence[i]=='B')
      system("mpg123 sounds/sound2.mp3");
    else if (sequence[i]=='b')
      system("mpg123 sounds/sound2.mp3");
    else if (sequence[i]=='C')
      system("mpg123 sounds/sound3.mp3");
    else if (sequence[i]=='c')
      system("mpg123 sounds/sound3.mp3");
    else if (sequence[i]=='D')
      system("mpg123 sounds/sound4.mp3");
    else if (sequence[i]=='d')
      system("mpg123 sounds/sound4.mp3");
    else if (sequence[i]=='E')
      system("mpg123 sounds/sound5.mp3");
    else if (sequence[i]=='e')
      system("mpg123 sounds/sound5.mp3");
    else if (sequence[i]=='F')
      system("mpg123 sounds/sound6.mp3");
    else if (sequence[i]=='f')
      system("mpg123 sounds/sound6.mp3");
    else if (sequence[i]=='G')
      system("mpg123 sounds/sound7.mp3");
    else if (sequence[i]=='g')
    system("mpg123 sounds/sound7.mp3");
  }
}

void lower_string(char s[]) {
  int c = 0;
 
  while (s[c] != '\0') {
    if (s[c] >= 'A' && s[c] <= 'Z') {
      s[c] = s[c] + 32;
    }
    c++;
  }
}

void process( char * args ) {
  char * cmd;
  cmd = strtok(args, " ");
  lower_string(cmd);
  if (strcmp(cmd,"play") == 0){
    cmd = strtok(NULL," ");
    play_sound(cmd);
  }

  //  play_sounds(a[1]);
}
