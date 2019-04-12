// "Write a program that prints the numbers from 1 to 100. But for multiples 
// of three print “Fizz” instead of the number and for the multiples of five 
// print “Buzz”. For numbers which are multiples of both three and five print 
// “FizzBuzz”.

#include <iostream>
#include <sstream>

using namespace std ;

int main (
  int   nNumberofArguments,
  char* apszArgument[]
)
{
  int nReturncode = 0;

  stringstream ssOutputLine ("") ;

  int nCount = 1 ;

  while ( nCount <= 100) {

    if ( ( ( nCount % 3 ) == 0 ) ||
         ( ( nCount % 5 ) == 0 )
       ) {
        if ( ( nCount % 3 ) == 0 ) 
          ssOutputLine << "Fizz" ;
        if ( ( nCount % 5 ) == 0 ) 
          ssOutputLine << "Buzz" ;
      }
     else
      ssOutputLine << nCount ;

    cout << ssOutputLine.str() << "\n" ;
    ssOutputLine.str("") ;

    nCount++ ;
  }

  return nReturncode ;
}
