#ifndef STABLO_H
#define STABLO_H
#include <vector>
using namespace std;

template <typename Tip>
class Stablo {
  public:
  struct Cvor {
      Cvor *ld, *dd, *rod;
      Tip element;
      Cvor(Tip element, Cvor *rod = nullptr, Cvor *ld = nullptr,
           Cvor *dd = nullptr):element(element),rod(rod),ld(ld),dd(dd) {}
  };

  private:
  Cvor *korijen;
  int velicina;
  void InOrder(Cvor *tekuci, void(*akcija)(Tip&));
  Tip Suma(Cvor *);
  int Visina(Cvor*);
  int BrojListova(Cvor*);
  void Sortiraj(Cvor*, vector<Tip>&);
  void Ogledalo(Cvor *kor);
  void IspisiNeparneLevele(Cvor *kor, bool neparan);
  Tip SumaListova(Cvor *kor);
  void IzbrisiListove(Cvor *kor);
  int BrojNeListova(Cvor *kor);
  void PreOrder(Cvor *tekuci, void(*akcija)(Tip&));
  void PostOrder(Cvor *tekuci, void(*akcija)(Tip&));
  Cvor* Najmanji(Cvor *kor);
  Cvor* Najveci(Cvor *kor);
  Cvor* Sljedbenik(Cvor *kor);
  Cvor* Prethodnik(Cvor *kor);
  void IzbrisiOdabraneListove(bool(*akcija)(Tip&),Cvor *kor);

  public:
  Stablo() { korijen = nullptr; velicina = 0; }
  Stablo(Tip element) { korijen = new Cvor(element); velicina = 1; }
  void Umetni(Tip element);
  void Izbrisi(Tip element);
  Cvor* Nadji(Tip element);
  void InOrder(void(*akcija)(Tip&));
  vector<Tip> vratiSortiran() { vector<int> v; Sortiraj(korijen,v); return v;}
  void LevelOrder(void(*akcija)(Tip&));
  Tip Suma() { Suma(korijen); }
  int Visina() { return Visina(korijen); }
  int BrojListova() { return BrojListova(korijen); }
  void Ogledalo() { Ogledalo(korijen); }
  void IspisiNeparneLevele() { IspisiNeparneLevele(korijen,false); }
  Tip SumaListova() { SumaListova(korijen); }
  void IzbrisiListove() { IzbrisiListove(korijen); }
  int BrojNeListova() { BrojNeListova(korijen); }
  void PreOrder(void(*akcija)(Tip&));
  void PostOrder(void(*akcija)(Tip&));
  Cvor* Najmanji() { Najmanji(korijen); }
  Cvor* Najveci() { Najveci(korijen); }
  Cvor* Sljedbenik(Tip element);
  Cvor* Prethodnik(Tip element);
  void IzbrisiOdabraneListove(bool(*akcija)(Tip&)) { IzbrisiOdabraneListove(akcija,korijen); }
};

#include "stablo.cpp"
#endif // STABLO_H
