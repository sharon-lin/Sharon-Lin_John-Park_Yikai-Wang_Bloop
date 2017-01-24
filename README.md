# Virtual Drums
 
A C socket application that allows users to play and record drum sequences. 
 
## Team Members   
Sharon Lin - backend, networking

John Park - menu design, aiding with drum animations

Yikai Wang - project manager, drum animations

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
$ ./client [IP ADDRESS]
```

## File Structure

## Bugs
- The buffer overflows when the query string is too long
