#ifndef STABLO_CPP
#define STABLO_CPP
#include "stablo.h"
#include <queue>
#include <iostream>
using namespace std;

template <typename Tip>
void Stablo<Tip>::Umetni(Tip element) {

  if(!korijen) {
    korijen = new Cvor(element);
    velicina = 1;
    return;
  }

  Cvor *trenutni = korijen, *prethodni = nullptr;
  while(trenutni != nullptr) {
    if(element > trenutni->element) {
        prethodni = trenutni;
        trenutni = trenutni->dd;
    }
    else if(element < trenutni->element) {
        prethodni = trenutni;
        trenutni = trenutni->ld;
    }
    else return;
  }
  if(element > prethodni->element)
    prethodni -> dd = new Cvor(element,prethodni);
  else prethodni -> ld = new Cvor(element, prethodni);
  velicina++;
  return;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Nadji(Tip element) {
  Cvor *trenutni = korijen;
  while(trenutni != nullptr) {
    if(element == trenutni->element)
        return trenutni;
    else if(element > trenutni->element)
        trenutni = trenutni -> dd;
    else trenutni = trenutni -> ld;
  }
  return nullptr;
}

template <typename Tip>
void Stablo<Tip>::InOrder(void (*akcija)(Tip&)) {
  InOrder(korijen,akcija);
}

template <typename Tip>
void Stablo<Tip>::InOrder(Cvor *tekuci, void (*akcija)(Tip&)) {
  if(tekuci) {
    InOrder(tekuci->ld,akcija);
    akcija(tekuci->element);
    InOrder(tekuci->dd,akcija);
  }
}

template <typename Tip>
void Stablo<Tip>::Izbrisi(Tip element) {
  Cvor *pok = Nadji(element);
  if(pok == nullptr)
    return;
  //ako nema lijevo dijete
  if(pok->ld == nullptr) {
    //ako je list
    if(pok->dd == nullptr) {
        //ako je korijen
        if(pok->rod == nullptr) {
            delete korijen;
            korijen = nullptr;
        }
        //ako nije korijen
        else {
            if(pok -> rod -> dd == pok)
                pok->rod->dd = nullptr;
            else pok->rod->ld = nullptr;
            delete pok;
        }
    }
    //ako nije list
    else {
        //ako je korijen
        if(pok->rod == nullptr) {
            korijen = pok->dd;
            delete pok;
        }
        //ako je lijevo dijete svog roditelja
        if(pok->rod->ld == pok) {
            pok->rod->ld = pok->dd;
            pok->dd->rod = pok->rod;
            delete pok;
        }
        //ako je desno dijete svog roditelja
        else {
            pok->rod->dd = pok->dd;
            pok->dd->rod = pok->rod;
            delete pok;
        }
    }
  }
  //ako ima lijevo dijete
  else {
    Cvor *trenutni = pok->ld;
    if(trenutni->dd == nullptr) {
        trenutni->rod = pok->rod;
        trenutni->dd = pok->dd;
        if(pok->rod == nullptr) {
            korijen = trenutni;
        }
        else if(pok->rod->ld == pok) {
            pok->rod->ld = trenutni;
        }
        else pok->rod->dd = trenutni;
        delete pok;
    }
    else {
      while(trenutni->dd != nullptr)
        trenutni = trenutni->dd;
      trenutni->rod->dd = trenutni->ld;
      if(trenutni->ld != nullptr)
       trenutni->ld->rod = trenutni->rod;
      trenutni->ld = pok->ld;
      trenutni->dd = pok->dd;
      trenutni->rod = pok->rod;
      if(pok->rod == nullptr)
        korijen = trenutni;
      else if(pok->rod->ld == pok)
        pok->rod->ld = trenutni;
      else pok->rod->dd = trenutni;
      pok->ld->rod = trenutni;
      delete pok;
    }
  }
  velicina--;

}

template <typename Tip>
void Stablo<Tip>::LevelOrder(void(*akcija)(Tip&)) {
  queue<Cvor*> red;
  red.push(korijen);
  while(!red.empty()) {
    Cvor *trenutni = red.front();
    red.pop();
    akcija(trenutni->element);
    if(trenutni->ld != nullptr)
        red.push(trenutni->ld);
    if(trenutni->dd != nullptr)
        red.push(trenutni->dd);
  }
}

template <typename Tip>
void Stablo<Tip>::IzbrisiOdabraneListove(bool(*akcija)(Tip&),Cvor *kor) {
    if(kor == nullptr) {
        return;
    }

    if(kor->ld == nullptr && kor->dd == nullptr && akcija(kor->element)) {
        Izbrisi(kor->element);
        return;
    }


    IzbrisiOdabraneListove(akcija,kor->ld);
    IzbrisiOdabraneListove(akcija,kor->dd);

}


template <typename Tip>
Tip Stablo<Tip>::Suma(Stablo::Cvor *pok) {
  if(pok == nullptr)
    return 0;
  return pok->element + Suma(pok->ld) + Suma(pok->dd);
}

template <typename Tip>
int Stablo<Tip>::Visina(Cvor *pok) {
  if(pok == nullptr)
    return -1;
  return 1 + max(Visina(pok->ld),Visina(pok->dd));
}

template <typename Tip>
int Stablo<Tip>::BrojListova(Cvor *pok) {
  if(pok == nullptr)
    return 0;
  if(pok->ld == nullptr && pok->dd == nullptr)
    return 1;
  return BrojListova(pok->ld) + BrojListova(pok->dd);
}

template <typename Tip>
void Stablo<Tip>::Sortiraj(Cvor *pok, vector<Tip> &v) {
    if(pok) {
        Sortiraj(pok->ld,v);
        v.push_back(pok->element);
        Sortiraj(pok->dd,v);
    }
}

template <typename Tip>
void Stablo<Tip>::Ogledalo(Cvor *kor) {
	if(kor == nullptr){
		return;
	}
	Ogledalo(kor->ld);
	Ogledalo(kor->dd);

	Cvor *temp = kor->ld;
	kor->ld = kor->dd;
	kor->dd = temp;
}


template <typename Tip>
void Stablo<Tip>::IspisiNeparneLevele(Cvor *kor, bool neparan) {
	if(kor == nullptr){
		return;
	}
	if(neparan) {
		cout << kor->element << " ";
	}

	IspisiNeparneLevele(kor->ld, !neparan);
	IspisiNeparneLevele(kor->dd, !neparan);
}

template <typename Tip>
Tip Stablo<Tip>::SumaListova(Cvor *kor) {
	if(kor == nullptr) {
		return 0;
	}
	if(kor->ld == nullptr && kor->dd == nullptr){
		return kor->element;
	}

	return SumaListova(kor->ld) + SumaListova(kor->dd);
}

template <typename Tip>
void Stablo<Tip>::IzbrisiListove(Cvor *kor) {
	if(kor == nullptr){
		return;
	}
	if(kor->ld == nullptr && kor->dd == nullptr){
		Izbrisi(kor->element);
		return;
	}

	IzbrisiListove(kor->ld);
	IzbrisiListove(kor->dd);
}

template <typename Tip>
int Stablo<Tip>::BrojNeListova(Cvor *kor) {
	if(kor == nullptr || (kor->ld == nullptr && kor->dd == nullptr)) {
		return 0;
	}

	return 1 + BrojNeListova(kor->ld) + BrojNeListova(kor->dd);
}

template <typename Tip>
void Stablo<Tip>::PreOrder(void (*akcija)(Tip&)) {
  PreOrder(korijen,akcija);
}

template <typename Tip>
void Stablo<Tip>::PreOrder(Cvor *tekuci, void (*akcija)(Tip&)) {
  if(tekuci) {
	akcija(tekuci->element);
    PreOrder(tekuci->ld,akcija);
    PreOrder(tekuci->dd,akcija);
  }
}

template <typename Tip>
void Stablo<Tip>::PostOrder(void (*akcija)(Tip&)) {
  PostOrder(korijen,akcija);
}

template <typename Tip>
void Stablo<Tip>::PostOrder(Cvor *tekuci, void (*akcija)(Tip&)) {
  if(tekuci) {
    PostOrder(tekuci->ld,akcija);
    PostOrder(tekuci->dd,akcija);
	akcija(tekuci->element);
  }
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Najmanji(Cvor *kor) {
	while(kor->ld != nullptr) {
		kor = kor->ld;
	}

	return kor;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Najveci(Cvor *kor) {
	while(kor->dd != nullptr) {
		kor = kor->dd;
	}

	return kor;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Sljedbenik(Cvor *kor) {
	if(kor->dd != nullptr){
		return Najmanji(kor->dd);
	}

	Cvor *q = kor->rod;
	while(q != nullptr && kor == q->dd) {
		kor = q;
		q = q->rod;
	}

	return q;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Sljedbenik(Tip element) {
	Cvor *pok = Nadji(element);
	if(pok == nullptr) {
		throw "Taj element se ne nalazi u stablu !";
	}
	Cvor *rez = Sljedbenik(pok);
	if(rez == nullptr) {
		throw "Taj element nema svog sljedbenika !";
	}else {
		return rez;
	}
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Prethodnik(Cvor *kor) {
	if(kor->ld != nullptr){
		return Najveci(kor->ld);
	}

	Cvor *q = kor->rod;
	while(q != nullptr && kor == q->ld) {
		kor = q;
		q = q->rod;
	}

	return q;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Prethodnik(Tip element) {
	Cvor *pok = Nadji(element);
	if(pok == nullptr) {
		throw "Taj element se ne nalazi u stablu !";
	}
	Cvor *rez = Prethodnik(pok);
	if(rez == nullptr) {
		throw "Taj element nema svog prethodnika !";
	}else {
		return rez;
	}
}




#endif // STABLO_CPP
