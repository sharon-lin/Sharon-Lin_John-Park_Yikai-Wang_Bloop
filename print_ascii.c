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
#include <ctype.h>
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
=======
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

void print_top( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int i, char keyhit, char * s1, char * s2, char * s3 ) {
  int key = toupper(keyhit);
  if( i == 6 ) {
      if((key < 'D') || (key > 'F')) {
        printf("%s%s\n", s3, buff[11] );
        printf("%s%s%s%s%s\n", buff[15], s1, buff[12], s2, buff[15] );
      }

      else if( key == 'D' ) {
          printf("%s\n", buff[7] );
          printf("%s     %s%s\n", buff[8], s1, buff[11] );
          printf("%s%s%s%s%s\n", buff[9], s1, buff[12], s2, buff[15] );
        }
      else if( key == 'E' ) {
         printf("%s%s\n", s3, buff[4] );
         printf("%s%s\n", s3, buff[5] );
         printf("%s%s%s%s%s\n", buff[15], s1, buff[6], s2, buff[15] );
      }
      else if( key == 'F' ) {
        printf("%s%s          %s\n", s3, s2, buff[7] );
        printf("%s%s%s %s\n", s3, buff[11], s2, buff[8] );
        printf("%s%s%s%s%s\n", buff[15], s1, buff[12], s2, buff[9] );
      }
  }

  else if( i == 3 ) {
      if((key < 'A') || (key > 'C')) {
        printf("%s%s%s\n", buff[11], s3, buff[11]);
        printf("%s%s%s%s%s\n", buff[12], s1, buff[15], s2, buff[12] );
      }

      else if( key == 'A' ) {
           printf("%s\n", buff[4] );
           printf("%s%s%s\n", buff[5], s3, buff[11] );
           printf("%s%s%s%s%s\n", buff[6], s1, buff[15], s2, buff[12] );
        }
      else if( key == 'B' ) {
        printf("          %s%s\n", s1, buff[7] );
        printf("%s%s %s     %s%s\n", buff[11], s1, buff[8], s2, buff[11] );
        printf("%s%s%s%s%s\n", buff[12], s1, buff[9], s2, buff[12] );
      }
      else if( key == 'C' ) {
        printf("         %s%s\n", s3, buff[4] );
        printf("%s%s%s\n", buff[11], s3, buff[5] );
        printf("%s%s%s%s%s\n", buff[12], s1, buff[15], s2, buff[6] );
      }
  }

  else if( i == 2 ) {
      if((key < 'A') || (key > 'B')) {
        printf("%s\n", buff[11] );
        printf( "%s%s%s\n", buff[12], s1, buff[15] );
      }

      else if( key == 'A' ) {
           printf("%s\n", buff[4] );
           printf("%s\n", buff[5] );
           printf("%s%s%s\n", buff[6], s1, buff[15] );
        }
      else if( key == 'B' ) {
        printf("          %s%s\n", s1, buff[7] );
        printf("%s%s %s\n", buff[11], s1, buff[8] );
        printf("%s%s%s\n", buff[12], s1, buff[9] );
      }
  }

  else {
    if(key != 'A') {
      printf("%s%s\n", s1, buff[11] );
      printf("%s%s\n", s1, buff[12] );
    }

    else {
      printf("%s%s\n", s1, buff[4] );
      printf("%s%s\n", s1, buff[5] );
      printf("%s%s\n", s1, buff[6] );
    }
  }

}

void print_drums( char buff[ASCII_SIZE][MAX_ASCII_SIZE], char *numkeys, char * keyhit ) {
  int i = atoi(numkeys);
  char c = 65; char diff = 0;

  if( i > 2 ) {
    char * s1 = "      ";
    char * s2 = "     ";
    char * s3 = "                         ";
    print_top( buff, 3, keyhit[0], s1, s2, s3 );
    printf("%s\n", buff[0] );
    printf("     %c    %s       %c      %s    %c\n\n", c, s1, c + 1, s2, c + 2 );
    diff += 3;

    if( i > 5 ) {
      char * s1 = "     ";
      char * s2 = "    ";
      char * s3 = "                  ";
      print_top( buff, 6, keyhit[0], s1, s2, s3 );
      printf("%s\n", buff[1] );
      printf("       %c      %s    %c     %s      %c\n\n", c + diff, s1, c + diff + 1, s2, c + diff + 2 );
      diff += 3;
    }
  }
>>>>>>> 88cbbbb7d5c9003884c49378e8576ef9b7b099cc

  if( i%3 == 1 ) {
    char * s = "                  ";
    print_top( buff, 1, keyhit[0] + diff, s, "", "" );
    printf("%s\n", buff[2] );
    printf("%s     %c\n\n", s, c + diff );
  }
  if( i%3 == 2 ) {
    char * s = "                      ";
    print_top( buff, 2, keyhit[0] + diff, s, "", "" );
    printf("%s\n", buff[3] );
    printf("     %c    %s       %c\n\n", c + diff, s, c + diff + 1 );
  }
}

void main(int argc, char const *argv[]
) {
  int fd = open("ascii.txt", O_RDONLY);

<<<<<<< HEAD

  close(fd);
  */

  char buff[ASCII_SIZE][MAX_ASCII_SIZE];
  read_all( buff, fd );
  close(fd);

  printf("\nChecking for inputs (argv must be >= 2)...\n" );
  int i = 1;
  for(; i <= argc; i++ )
    printf("argv[%d]: %s\n", i, argv[i] );

  printf("\n" );
  print_drums( buff, argv[1], argv[2] );


  return 0;


}
