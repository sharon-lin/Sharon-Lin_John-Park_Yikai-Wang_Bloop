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

#include "networking.h"
#include "print_ascii.h"

void process( char * s );
void sub_server( int sd );

int directory_num = 0;

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


void postmessage (char * sequence, char * filename)
{
  int i, bytesread;
  char buffer[255];

  strcpy(buffer, sequence);
  FILE *outputfile;
 
  bzero(buffer,255);

  /*  char dn[10];
  sprintf(dn, "%d", directory_num);

  char str[30];
  strcpy(str, dn);
  strcat(str, ".txt");
  */

  char str[30];
  strcpy(str, filename);
  strcat(str, ".txt");
 
  if ((outputfile = fopen(str, "w")) == NULL)
    {
      fprintf(stderr, "Cannot open\n");
      return;
    }
 
  for (i = 0; i < 100; i++)
    {
      if (putc(sequence[i], outputfile) == EOF)
        {
	  printf ("Write error\n");
	  break; /* stop the for loop */
        }
    }
  

  directory_num++;
     
  fclose(outputfile);
}


void play_sound(char * sequence){

  int length = (int)strlen(sequence);
  int i = 0;

  int fd = open("ascii.txt", O_RDONLY);
  char anime[ASCII_SIZE][MAX_ASCII_SIZE];
  read_all( anime, fd );
  close(fd);


  while(!isdigit(sequence[i++]));
  int numdrums = sequence[i-1];
  print_drums( anime, numdrums, "0" );

  for (;i<length;i++){
    int c = tolower(sequence[i]);
    if ((c=='a') && (numdrums > 0)) {
      print_drums( anime, numdrums, "a" );
      system("mpg123 sounds/sound1.mp3");
    }
    else if ((c=='b') && (numdrums > 1)) {
      print_drums( anime, numdrums, "b" );
      system("mpg123 sounds/sound2.mp3");
    }
    else if ((c=='c') && (numdrums > 2)) {
      print_drums( anime, numdrums, "c" );
      system("mpg123 sounds/sound3.mp3");
    }
    else if ((c=='d') && (numdrums > 3)) {
      print_drums( anime, numdrums, "d" );
      system("mpg123 sounds/sound3.mp3");
    }
    else if ((c=='e') && (numdrums > 4)) {
      print_drums( anime, numdrums, "e" );
      system("mpg123 sounds/sound5.mp3");
    }
    else if ((c=='f') && (numdrums > 5)) {
      print_drums( anime, numdrums, "f" );
      system("mpg123 sounds/sound6.mp3");
    }
    else if ((c=='g') && (numdrums > 6)) {
      print_drums( anime, numdrums, "g" );
      system("mpg123 sounds/sound7.mp3");
    }
  }
}

void play_original(char * sequence){

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
	system("mpg123 sound5.mp3");
      else if (sequence[i]=='F')
	system("mpg123 sound6.mp3");
      else if (sequence[i]=='f')
	system("mpg123 sound6.mp3");
      else if (sequence[i]=='G')
	system("mpg123 sound7.mp3");
      else if (sequence[i]=='g')
	system("mpg123 sound7.mp3");
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
  char * filename;

  cmd = strtok(args, " ");
  lower_string(cmd);
  
  if (strcmp(cmd,"play") == 0){
    cmd = strtok(NULL," ");
    //play_sound(cmd);
    play_original(cmd);
  }
  
  else if (strcmp(cmd,"save")==0){
    filename = strtok(NULL," ");
    cmd = strtok(NULL," ");
    postmessage(cmd, filename);
  }
  
}
