#define ASCII_SIZE 15
#define MAX_ASCII_SIZE 200

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

int ascii_sizes[ASCII_SIZE] = {
  183, 186, 119,
  7, 10, 13,
  8, 9, 14,
  1, 10, 11,
  1, 1, 14
};

void read_all( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int fd ) {
  int i = 0;
  for(; i < ASCII_SIZE; i++ ) {
    read( fd, buff[i], ascii_sizes[i] );
    buff[i][ascii_sizes[i]] = 0;
    printf( "buff[%d]:\n%s\n", i, buff[i] );
    lseek(fd, 1, SEEK_CUR );
  }
}

void main(//int argc, char const *argv[]
) {
  int fd = open("ascii.txt", O_RDONLY);

  char buff[ASCII_SIZE][MAX_ASCII_SIZE];
  read_all( buff, fd );

  close(fd);
}
