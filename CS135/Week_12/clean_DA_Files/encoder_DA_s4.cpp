////////////////////////////////////////////////////////////////////////////////
// Header Files ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
   #include <iostream>
   #include <fstream> 
   using namespace std ;


////////////////////////////////////////////////////////////////////////////////
// Global Constant Definitions /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// character constants

const char NULL_CHAR = '\0';
const char NEW_LINE  = '\n';

// numerical constants

const int MAX_MESSAGE = 1001;     // 1001 to accomodate for the null terminator
const int MAX_ENCODED = 7500;
const int OUT_STRNG_LEN = 8;
const int EVEN_PROB = 25;
const int ASCII_LOW = 33;
const int ASCII_HI  = 126; 
const int EVEN = 0;
const int ODD  = 1;
const int MAX_VAL_PER_LINE = 5;


////////////////////////////////////////////////////////////////////////////////
// Global Function Prototypes //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/* 
Name: printTitle
Process: displays the program title on the console
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: displays the program title
Dependencies: <iostream>
*/
void printTitle();


/* 
Name: promptForFileNames
Process: propmts the user for 2 file names: one for a message to read and encode,
         a second to create and write the coded message to
Function Input/Parameters: char inName[]      a c-style string for the name of
                                              message file to be read in 
                           char outName[]     a c-style string representing the 
                                              name of the output file to be created
Function Output/Parameters: (by reference)     char inName[]
                            (by reference)     char outName[]
Function Output/Returned: none
Device Input: the two file names
Device Output: a message prompting for the two file names
Dependencies: <iostream>, <fstream> 
*/
void promptForFileNames( char inName[], char outName[] );


/* 
Name: readData
Process: notifies the user attempted reading has begun, reads the message of the
         input file into a c-style string to store in the program
Function Input/Parameters: char inName[]         a c-style string for the name of
                                                 message file to be read in
                           char message[]        a c-style string that holds the 
                                                 message that is read in
                           bool fileThere        a boolean flag to indicate whether 
                                                 or not the input file name references
                                                 an existing file
                           bool fileTooLarge     a boolean flag to indicate whether
                                                 or not the message being read in is
                                                 too large to be handled by the program
                           int messSize          indicates how large the message
                                                 that was read in is
Function Output/Parameters: (by reference) char message[]
                            (by reference) bool fileThere
                            (by reference) bool fileTooLarge
                            (by reference) int messSize
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: <iostream>, <fstream>
*/
int readData( char inName[], char message[], bool &fileThere, bool &fileTooLarge, int &messSize );


/* 
Name: noFileError
Process: displays an error message indicating that the given file name does not 
         reference an existing file  
Function Input/Parameters: char inName[]     a c-style string for the name of
                                             message file to be read in
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: the invalid file name error message
Dependencies: <iostream>
*/
void noFileError( char inName[] );


/* 
Name: oversizeError
Process: displays an error message indicating that the input message is too long
         to be processed by the program
Function Input/Parameters: char inName[]     a c-style string for the name of
                                             message file to be read in
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: the file is too large error message
Dependencies: <iostream>
*/
void oversizeError( char inName[]);


/* 
Name: encodeData
Process: notifies user that encryption has begun, encodes the message one character 
at a time, and places them interspersed between dummy values, even codes being 
valid characters, odd values being dummies
Function Input/Parameters: char message[]           a c-style string that holds the 
                                                    message that is read in
                           int encodedMessage[]     an array to contain both valid
                                                    and dummy values that have been
                                                    coded
                           int messSize             indicates how large the message
                                                    that was read in is
                           int codeSize             indicate how large the coded
                                                    message is
Function Output/Parameters: (by reference) int codeSize
Function Output/Returned: none
Device Input: none
Device Output: notifies user encryption has begun
Dependencies: none
*/
void encodeData( char message[], int encodedMessage[], int messSize, int &codeSize );


/* 
Name: doLoadEven 
Process: returns true, in this case to indicate an even number should be loaded, 
         the specified percentage of times 
Function Input/Parameters: int timesIn100     indicates the expected times out of 100
                                              true (do load an even value) is returned
Function Output/Parameters: none
Function Output/Returned: true      signals an even value should be loaded
                          false     signals an even value should not be loaded
Device Input: none
Device Output: none
Dependencies: rand()
*/
bool doLoadEven( int timesIn100 );


/* 
Name: getRandBetween
Process: generates a random number within the range of the input values
Function Input/Parameters: int low      the lower limit of the range for the 
                                        generated random number
                           int high     the upper limit of the range for the 
                                        generated random number
Function Output/Parameters: none
Function Output/Returned: a random number within the specified range
Device Input: none
Device Output: none
Dependencies: rand()
*/
int getRandBetween( int low, int high );


/* 
Name: encodeVal
Process: encodes a value that is presumably, but not necessarily, the code for an
         ASCII character
Function Input/Parameters: int value        the presumed ASCII code to be encoded
                           int tailType     indicates whether the encoded value
                                            whould end in an even or odd digit
                                            to mark it as a true or dummy value
Function Output/Parameters: none
Function Output/Returned: an encoded integer
Device Input: none
Device Output: none
Dependencies: none
*/
int encodeVal( int value, int tailType );


/* 
Name: genTail
Process: randomly generates a tail value to be used in the encoding process
Function Input/Parameters: int tailType      indicates whether the generated tail 
                                             value should be even or odd 
Function Output/Parameters: none
Function Output/Returned: an appropriate integer tail value
Device Input: none
Device Output: none
Dependencies: none
*/
int genTail( int tailType );


/* 
Name: genDummy
Process: randomly generates a value in the range of valid ASCII code
Function Input/Parameters: none     
Function Output/Parameters: none
Function Output/Returned: a random integer that is within the range of valid
                          ASCII code
Device Input: none
Device Output: none
Dependencies: none
*/
int genDummy();


/* 
Name: writeEncodedMessage
Process: notifies user that message writing has begun, converts encoded integer 
         values to c-style strings, and writes them to an output file
Function Input/Parameters: char outName[]           the name of the output file 
                                                    to be created and written to
                           int encodedMessage[]     the array containing the encoded
                                                    message values
                           int codeSize             the size of the coded message,
                                                    used to indicate when writing
                                                    should stop
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: writes an encoded message file
Dependencies: <iostream>, <fstream>
*/
void writeEncodedMessage( char outName[], int encodedMessage[], int codeSize );


/* 
Name: stringConversion
Process: takes an encoded integer value and converts it to an 8 characteer c-style string
Function Input/Parameters: char tempString[]     an 8 slot array or c-style string
                                                 used to hold the value to be written
                                                 to the file
                           int codeVal           the encoded integer value to be 
                                                 converted
Function Output/Parameters: (by reference) char tempString[]
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: none
*/
void stringConversion( char tempString[], int codeVal );


////////////////////////////////////////////////////////////////////////////////
// Main Program Definition /////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
   { 

   // initialize function/variables

      // vars

         // arrays and c-style strings
         char inputFile[ MAX_MESSAGE ]  = "None entered yet...";
         char outputFile[ MAX_MESSAGE ] = "None entered yet...";
         char message[ MAX_MESSAGE ];
         int encodedMessage[ MAX_ENCODED ];

         // flags
         bool fileThere  = false;
         bool fileTooLarge = true;
         int messageSize = 0;
         int codeSize = 0;

         // initialize random seed 
         srand( time( NULL ) );

      // display program title
         // function: printTitle
         printTitle();

   // prompt for in/out file names
      // function: promptForFileNames
      promptForFileNames( inputFile, outputFile );

   // read in message
      // function: readData
      readData( inputFile, message, fileThere, fileTooLarge, messageSize );

      // if input file is invalid/reading fails, abort program
         // operation: if
            if( !fileThere )
              {
               // display error message
                  // function: noFileError
                  noFileError( inputFile ); 

               // return 0 to end program
               return 0;          
              }

// if input file is too large, abort program
         // operation: if
            if( fileTooLarge )
              {
               // display error message
                  // function: oversizeError
                  oversizeError( inputFile ); 

               // return 0 to end program
               return 0;          
              }

   // encrypt message
      // function: encodeData
      encodeData( message, encodedMessage, messageSize, codeSize );

   // write encrypted message
      // function: writeEncodedMessage
      writeEncodedMessage( outputFile, encodedMessage, messageSize );

   // end program

      // hold program for user
         // function: system 
         system ( "PAUSE" );
    
      // return 0
      return 0;
   }


////////////////////////////////////////////////////////////////////////////////
// Supporting function implementations /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printTitle()
   {
   // no return - void
   }


void promptForFileNames( char inName[], char outName[] )
   {
   // no return - void
   }


int readData( char inName[], char message[], bool &fileThere, bool &fileTooLarge, int &messSize )
   {
   return 0;     // temporary stub return
   }


void noFileError( char inName[] )
   {
   // no return - void    
   }


void oversizeError( char inName[] )
   {
   // no return - void   
   }


void encodeData( char message[], int encodedMessage[], int messSize, int &codeSize )
   {
   // no return - void
   }


bool doLoadEven( int timesIn100 )
   {
   return 0;     // temporary stub return
   }


int getRandBetween( int low, int high )
   {
    return 0;     // temporary stub return
   }


int encodeVal( int value, int tailType )
   {
   return 0;     // temporary stub return
   }


int genTail( int tailType )
   {
   return 0;     // temporary stub return
   }

int genDummy()
   {
   return 0;     // temporary stub return
   }


void writeEncodedMessage( char outName[], int encodedMessage[], int codeSize )
   {
   // no return - void 
   }


void stringConversion( char tempString[], int codeVal )
   {
   // no return - void
   } 