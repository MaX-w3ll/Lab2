//Nathaniel Maxwell
//816034720

//Includes
#include <p18f4550.h>
#include "FSIO.h"

//Definitions
#define bfrsize 1  //Defines the buffer size

//Writing to file
void write(char x , char y)
{   
    FSFILE *pWriteFile;
    char data1  = x;
    char bfr1  = y;
    int bytesWritten;
    pWriteFile = FSfopenpgm ("file.txt", "w");
    
    bytesWritten = FSfwrite ((void *) data1, 8, 1, pWriteFile);
    bytesWritten = FSfwrite ((void *) bfr1, 1, bfrsize, pWriteFile);
    FSfclose( pWriteFile );
}

//Reading from file
void read(char x , char y)
{
    FSFILE *pReadFile;
    char data2 = x ;
    char bfr2 = y; 
    int bytesRead;
    pReadFile =  FSfopenpgm ("text.txt", "r"); 
    
    bytesRead = FSfread((void*)data2, 1, 1, pReadFile); 
    bytesRead = FSfread( (void *)bfr2, 1, bfrsize, pReadFile );
    FSfclose( pReadFile );  
}

//Calling functions
void main (void) {
    
    char data3  = "d";
    char bfr3  = "b";
    
    write(data3, bfr3);
    read(data3, bfr3);

    return;
       
}