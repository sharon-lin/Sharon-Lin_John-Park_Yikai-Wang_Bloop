#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"
//#include "networking.c"

void process( char * s );
void sub_server( int sd );

int main() {

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
void process( char * s ) {

  if (strcmp(s,"A") == 0)
       system("mpg123 sound1.mp3");
  else if (strcmp(s,"B") == 0)
       system("mpg123 sound1.mp3");
  else if (strcmp(s,"B") == 0)
       system("mpg123 sound2.mp3");
  else if (strcmp(s,"b") == 0)
       system("mpg123 sound2.mp3");
  else if (strcmp(s,"C") == 0)
       system("mpg123 sound3.mp3");
  else if (strcmp(s,"c") == 0)
       system("mpg123 sound3.mp3");
  else if (strcmp(s,"D") == 0)
       system("mpg123 sound4.mp3");
  else if (strcmp(s,"d") == 0)
       system("mpg123 sound4.mp3");
  else if (strcmp(s,"E") == 0)
       system("mpg123 sound5.mp3");
  else if (strcmp(s,"e") == 0)
       system("mpg123 sound5.mp3");
  else if (strcmp(s,"F") == 0)
       system("mpg123 sound6.mp3");
  else if (strcmp(s,"f") == 0)
       system("mpg123 sound6.mp3");

}
