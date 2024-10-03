#ifndef LICORICE_H
#define LICORICE_H

#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;


class LicorIce {

  private:
    int shatter;
    int weapon;
    string babName;
  public:

    int fireWeapon() const {return  rand() % (weapon-1); };
    int getShatter() const {return shatter;};
    void makeBabies(int shatte);// end of makebabies

  friend bool operator<=(const LicorIce  & baby1, const  LicorIce & baby2)  {
      return baby1.getShatter() <= baby2.getShatter();
    }
  friend bool operator>=(const LicorIce  & baby1, const LicorIce & baby2)  {
      return baby1.getShatter() >= baby2.getShatter();
    }
  friend bool operator>(const LicorIce  & baby1, const LicorIce & baby2)  {
      return baby1.getShatter() > baby2.getShatter();
    }
//need an operator << for ostream
friend bool operator<(const LicorIce  & baby1, const LicorIce & baby2)  {
    return baby1.getShatter() < baby2.getShatter();
  }
  friend ostream & operator<<(ostream &, const LicorIce &);

};//end of class




#endif
