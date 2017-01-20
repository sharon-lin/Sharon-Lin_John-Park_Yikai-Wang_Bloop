#define ASCII_SIZE 16
#define MAX_ASCII_SIZE 250

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
  183, 186, 119, 186,
  7, 10, 13,
  8, 9, 14,
  1, 10, 11,
  1, 1, 14
};

void read_all( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int fd ) {
  int i = 0;
  for(; i < ASCII_SIZE; i++ ) {
    read( fd, buff[i], ascii_sizes[i] );
    int x = 0;
    buff[i][ascii_sizes[i]-1] = 0;
    printf( "buff[%d]:\n%s\n", i, buff[i] );
    lseek(fd, 1, SEEK_CUR );
  }
}

void print_drums( char buff[ASCII_SIZE][MAX_ASCII_SIZE], char *key ) {
  int i = atoi(key);
  if( i%3 == 1 ) {
    char * s = "                  ";
    printf("%s%s\n", s, buff[11] );
    printf("%s%s\n", s, buff[12] );
    printf("%s\n", buff[2] );
  }
  if( i%3 == 2 ) {
    printf("%s\n", buff[11] );
    printf( "%s                      %s\n", buff[12], buff[15] );
    printf("%s\n", buff[3] );
  }
}

void print_hit( char buff[ASCII_SIZE][MAX_ASCII_SIZE], char *key ) {
    char c = key[0];
    int a = 0;

    if( (c > 64) && (c < 73) )
      a = c - 64;
    else if( (c > 96) && (c < 105) )
      a = c - 96;

    int i = 0;
    for(; i < a; i++) {

    }
}

void main(int argc, char const *argv[]
) {
  int fd = open("ascii.txt", O_RDONLY);

  char buff[ASCII_SIZE][MAX_ASCII_SIZE];
  read_all( buff, fd );
  close(fd);

  printf("argv[2]: %s\n", argv[2] );
  print_drums( buff, argv[2]);

}
