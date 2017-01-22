#define ASCII_SIZE 16
#define MAX_ASCII_SIZE 250

int ascii_sizes[ASCII_SIZE] = {
  183, 186, 119, 186,
  7, 10, 13,
  8, 9, 14,
  1, 10, 11,
  1, 1, 14
};

void read_all( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int fd );
void print_top( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int i, char keyhit, char * s1, char * s2, char * s3 );
void print_drums( char buff[ASCII_SIZE][MAX_ASCII_SIZE], char *numkeys, char * keyhit );
