#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tr1/memory>
#include <stdlib.h>

using namespace std ;

enum eTypes { eInt, eFloat, eString } ;

class Base {                            // virtual base class
private:
public:
   virtual string sGetData() = 0 ;      // pure virtual method
} ;

class DerivedInt : public Base {
private:
   int nData ;
public:
   DerivedInt (int i) { nData = i ; } ;
   string sGetData () { ostringstream o ; o << nData ; return o.str() ; } ;
} ;

class DerivedFloat : public Base {
private:
   float fData ;
public:
   DerivedFloat (float i) { fData = i ; } ;
   string sGetData () { ostringstream o ; o << fData ; return o.str() ; } ;
} ;

class DerivedString : public Base {
private:
   string sData ;
public:
   DerivedString (string i) { sData = i ; } ;
   string sGetData () { ostringstream o ; o << sData ; return o.str() ; } ;
} ;

typedef shared_ptr<Base> BasePtr ;

int main (int argc, char* argv[]) {
   int nReturnCode = 0 ;

   srand(time(NULL)) ;

   vector<BasePtr> vBase (0) ;
   for (int n=0 ; n < 25 ; n=n+1) {
      BasePtr pbLocal = NULL ;

      switch (rand()%3) {
         case eInt:
            pbLocal = (BasePtr) new DerivedInt(rand()%32) ;
            break;
         case eFloat:
            pbLocal = (BasePtr) new DerivedFloat(((rand()%10)*10)+(rand()%10)+ \
               ((rand()%10)/10.0)+((rand()%10)/100.0)) ;
            break;
         case eString: {
            int nLength = (rand()%7)+3 ;
            string s = "" ;
            for (int n = 0 ; n < nLength ; n++)
               s += 'a'+(rand()%26) ;
            pbLocal = (BasePtr) new DerivedString(s) ; }
            break;
         default:
            break;
      }
      vBase.push_back(pbLocal) ;
      cout << n << " : " << vBase.back()->sGetData () << "\n" ;
   }

   cout << "Vector filled\n" ;

   vector<BasePtr>::iterator vBaseIterator = vBase.begin() ;
   int m = 0 ;
   while(vBaseIterator != vBase.end()) {

      cout << m << " : " << (*vBaseIterator)->sGetData () << "\n" ;

      vBaseIterator++ ;
      m++ ;
   }

   return nReturnCode ;
}
