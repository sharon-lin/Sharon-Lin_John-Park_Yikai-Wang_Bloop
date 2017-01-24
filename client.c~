#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"
#include "print_ascii.h"

void play_original(char * sequence){

  int length = (int)strlen(sequence);
  int i =0;
    for (;i<length;i++){
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



int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, connecting to 127.0.0.1\n");
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
    
    char * cmd = strtok(buffer, " ");
    lower_string(cmd);
    if (strcmp(cmd,"play")==0){
      cmd = strtok(NULL, " ");
      play_original(cmd);
    }

    write( sd, buffer, sizeof(buffer) );
    read( sd, buffer, sizeof(buffer) );
    printf( "received: %s\n", buffer );
    //send_message_all(buffer);
  }

  return 0;
}
