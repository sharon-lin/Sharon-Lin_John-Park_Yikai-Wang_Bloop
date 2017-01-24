# Virtual Drums
 
A C socket application that allows users to play and record drum sequences. 
 
## Team Members   
Sharon Lin - backend, networking

John Park - menu design, aiding with drum animations

Yikai Wang - project manager, drum animations

## Features

- Allows users to play sequences of drum sounds [A,B,C,D,E,F,G]
- Allows users to save sequences of drum sounds as .txt files
- Users can access other users' sequences and delete and modify files
- Accompanied by drum animations

## Attempted

- Using mutexes to protect files
- Setting limits to number of users at once using semaphores
- Creating more sophisticated animation for the program (frame ASCII animations)

## Bugs

- Issues with buffer/memory
 - Occasionally, the play [SEQUENCE] function will result in a SEG FAULT
 - This will terminate the program
  - Similar occurance with file I/O depending on sizes of files
   - Primarily due to limit sizes of files set during development

## Running the program

#### On Linux machines 

- If mpg123 is not installed
```
$ sudo apt-get mpg123
```
#### On Mac machines
```
$ sudo brew mpg123
```

- To build the program
```
$ make
```

- To run the program (server-side)
```
$ ./server
```

- To run the program (client-side)
```
$ ./client [IP ADDRESS OF SERVER]
```

## File Structure

#### client.c

- **void play_original(char * sequence);**
 - Input: sequence of notes
 - Output: None
  - Plays the sounds from .mp3 files associated to ABCDEFG in the keys inputted by the user
- **void play_sound(char * sequence);**
 - Input: sequence of notes
 - Output: None
  - Plays ASCII animations for each of the notes inputted by the user
- **int main( int argc, char * argv[] )**
 - Input: arguments
 - Output: None
  - Handles all primary client-side functions

#### server.c

- **void subserver(int sd);**
 - Input: socket descriptor
  - Reads input from client and sends input to process
 - Output: None
  - Writes output to client
- **void get_message (char * filename, char * args);**
 - Input: filename, buffer
  - Retrieves contents of specified file
 - Output: None
  - Returns the contents of the file or "There are no files" to the client buffer
- **void delete_file(char * filename, char * args);**
 - Input: filename, buffer 
  - Deletes the specified filename 
 - Output: None
  - Returns success or failure statement to the client buffer
- **void list_files(char * args);**
 - Input: buffer
 - Output: None
  - Prints all of the current .txt sound sequence files to the client buffer
- **void postmessage (char * sequence, char * filename, char * args);**
 - Input: sequence of notes, filename, buffer
  - Reads sequence of letter-notes inputted by client and the desired filename
 - Output: None
  - Saves a .txt file on the server with specified filename and content, returns success or error statement to client buffer
- **void process( char * args , int sd);**
 - Input: buffer, socket descriptor
 - Output: processes commands from client
- **int main()**
 - Input: None
 - Output: None
  - Handles all primary server-side functions

#### networking.c

- **void error_check( int i, char * s );**
 - Input: error number, error string
 - Output: None
  - Displays the specific error encountered within the program
- **int server_setup();**
 - Input: None
 - Output: socket descriptor
  - Sets up and binds the specified socket
- **int server_connect(int sd);**
 - Input: socket descriptor
 - Output: connection descriptor
  - Connects the server to the specified socket
- **int client_connect( char * host );**
 - Input: host descriptor
 - Output: socket descriptor
  - Connects the client to the specified host
- **void lower_string(char s[]);**
 - Input: string
 - Output: None
  - Turns the specified string into all lowercase letters

#### print_ascii.c

- **void read_all( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int fd );**
 - Input: None
 - Output: None
- **void print_top( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int i, char keyhit, char * s1, char * s2, char * s3 );**
 - Input: None
 - Output: None
- **void print_drums( char buff[ASCII_SIZE][MAX_ASCII_SIZE], int numkeys, char * keyhit );**
 - Input: None
 - Output: None

#### menu.c

- **char /*/* splitnsep(char * input, char * sym);**
 - Input: None
 - Output: None
- **char * fireblanks(char * input);**
 - Input: None
 - Output: None
- **int main();**
 - Input: None
 - Output: None

## Folders

#### txt

#### sounds
