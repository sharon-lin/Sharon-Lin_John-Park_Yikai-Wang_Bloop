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
- - Occasionally, the play [SEQUENCE] function will result in a SEG FAULT
- - This will terminate the program
- - Similar occurance with file I/O depending on sizes of files
- - - Primarily due to limit sizes of files set during development

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

#### server.c

#### networking.c

#### print_ascii.c

## Folders

#### txt

#### sounds

## Bugs
- The buffer overflows when the query string is too long
