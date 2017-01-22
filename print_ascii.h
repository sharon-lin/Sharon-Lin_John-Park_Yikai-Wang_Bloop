#define ASCII_SIZE 16
#define MAX_ASCII_SIZE 250

void read_all( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int fd );
void print_top( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int i, char keyhit, char * s1, char * s2, char * s3 );
void print_drums( char buff[ASCII_SIZE][MAX_ASCII_SIZE], char *numkeys, char * keyhit );
