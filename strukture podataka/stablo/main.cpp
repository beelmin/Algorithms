#include <iostream>
#include "stablo.h"

using namespace std;

void Ispisi(int &k) {
 cout<<k<<" ";
}

bool uslov(int &k) {
    if(k > 10) {
        return true;
    }
    return false;
}

int main() {

  Stablo<int> s;

  s.Umetni(25);
  s.Umetni(12);
  s.Umetni(34);
  s.Umetni(7);
  s.Umetni(18);
  s.Umetni(29);
  s.Umetni(39);
  s.Umetni(3);
  s.Umetni(10);
  s.Umetni(27);
  s.Umetni(32);


  s.IzbrisiOdabraneListove(uslov);

  s.LevelOrder(Ispisi);
  //cout << endl;
  //s.IspisiNeparneLevele();
  //s.Ogledalo();
  //s.LevelOrder(Ispisi);


  //cout << "Visina stabla je : " << s.Visina() << endl;
  //cout << "Broj listova je : " << s.BrojListova() << endl;
 /* try{
    auto pok = s.Prethodnik(27);
    cout << pok->element << endl;
  }catch(const char greska[]) {
    cout << greska << endl;
  }
  */

}
