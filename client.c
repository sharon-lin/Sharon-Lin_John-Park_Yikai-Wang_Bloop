#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"
#include "print_ascii.h"

int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, conneting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];

  int sd;

  sd = client_connect( host );

  char * menu_options = "******************************\nWELCOME TO THE MUSIC MAKER\n\nOPTIONS:\n\nPLAY [number of drums (1-7)] [sequence (A-G)] - Will play the sounds in the sequences\nSAVE [filename] [sequence] - Will save the notes in the sequence\nGET [filename] will return the value saved in the file\n\n******************************\n\n";

  printf("%s",menu_options);

  char buffer[MESSAGE_BUFFER_SIZE];

  while (1) {
    printf("Next note: ");
    fgets( buffer, sizeof(buffer), stdin );
    char *p = strchr(buffer, '\n');
    *p = 0;

    write( sd, buffer, sizeof(buffer) );
    read( sd, buffer, sizeof(buffer) );
    printf( "received: %s\n", buffer );
    //send_message_all(buffer);
  }

  return 0;
}
