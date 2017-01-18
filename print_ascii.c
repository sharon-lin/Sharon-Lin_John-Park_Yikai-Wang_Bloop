#define ASCII_SIZE1 70
#define ASCII_SIZE2 72
#define ASCII_SIZE3 80
#define ASCII_SIZE4 92

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

void main(//int argc, char const *argv[]
) {
  int fd = open("ascii.txt", O_RDONLY);

  char buff[4][100];
  read( fd, buff[0], ASCII_SIZE1 );
  buff[0][ASCII_SIZE1] = 0;
  printf( "buff[0]:\n%s\n", buff[0] );

  lseek(fd, 1, SEEK_CUR );

  read( fd, buff[1], ASCII_SIZE2 );
  buff[1][ASCII_SIZE2] = 0;
  printf( "buff[1]:\n%s\n", buff[1] );

  lseek(fd, 1, SEEK_CUR );

  read( fd, buff[2], ASCII_SIZE3 );
  buff[2][ASCII_SIZE3] = 0;
  printf( "buff[2]:\n%s\n", buff[2] );

  lseek(fd, 1, SEEK_CUR );

  read( fd, buff[3], ASCII_SIZE4 );
  buff[3][ASCII_SIZE4] = 0;
  printf( "buff[3]:\n%s\n", buff[3] );

  close(fd);
}
