#define ASCII_SIZE1 1020
#define ASCII_SIZE2 949

#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(){

  printf("Hi! What note would you like to play: ");

  int decision;

  scanf("%d", &decision);

  system("mpg123 piano1.mp3");

  /*
  int fd = open("ascii.txt", O_RDONLY);

  char buff[ASCII_SIZE1];
  read( fd, buff, sizeof(buff) );
  buff[ASCII_SIZE1-1] = 0;
  printf( "%s\n", buff );

  //gets # of bytes the current position is from the beginning of the file
  lseek(fd, -(ASCII_SIZE2), SEEK_END );//from end

  read( fd, buff, sizeof(buff) );
  buff[ASCII_SIZE2] = 0;
  printf( "%s\n", buff );


  close(fd);
  */
  return 0;
}
