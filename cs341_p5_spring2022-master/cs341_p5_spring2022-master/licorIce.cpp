#include "licorIce.h"





void LicorIce:: makeBabies(int shatte){
  shatter = shatte;

   weapon = rand() % 100;
   for(int i = 0; i < 5; i++)
   {
  //   int a = i;
  //  stringstream ss;
  //  ss << a;
  //  string str = ss.str();
   babName = "baby" ;
  }//end of weapon and name loop

}//end of make babies



   ostream & operator<<(ostream & out, const LicorIce & lic){
     out << "Weapon: " <<lic.weapon << " Shatter: "<< lic.shatter << " Name: "<< lic.babName << " " << lic.shatter;
    return out;
  }
