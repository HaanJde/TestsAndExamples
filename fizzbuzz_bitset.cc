// "Write a program that prints the numbers from 1 to 100. But for multiples 
// of three print “Fizz” instead of the number and for the multiples of five 
// print “Buzz”. For numbers which are multiples of both three and five print 
// “FizzBuzz”.

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std ;

int main (
  int   nNumberofArguments,
  char* apszArgument[]
)
{
  int nReturncode = 0;

  stringstream ssOutputLine ("") ;

  bitset<2> b2 (string("00")) ;

  int nCount = 1 ;

  while ( nCount <= 100 ) {

    b2.reset() ;

    if ( ( nCount % 3 ) == 0 )
      b2.set(0,1) ;

    if ( ( nCount % 5 ) == 0 )
      b2.set(1,1) ;

    if ( b2.test(0) ) 
       ssOutputLine << "Fizz" ;
    if ( b2.test(1) ) 
       ssOutputLine << "Buzz" ;
    if ( !b2.test(0) && !b2.test(1) ) 
       ssOutputLine << nCount ;

    cout << ssOutputLine.str() << "\n" ;
    ssOutputLine.str("") ;

    nCount++ ;
  }

  return nReturncode ;
}
