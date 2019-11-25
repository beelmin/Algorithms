#include <iostream>
#include <list>

using namespace std;

template <typename Tip>
class Stek {
  list<Tip> l;
public:
  int Prazan() { return l.empty(); }
  int Velicina() { return l.size(); }
  void Gurni(Tip element) { l.push_back(element); }
  Tip Skini() { Tip element=l.back(); l.pop_back(); return element; }
};

int main() {
  Stek<double> stek;
  while(1) {
    cout<<"Unesi RPN izraz: ";
    while(1) {
      while(cin.peek()==' ') cin.get();
      if(cin.peek()=='\n') break;
      if(cin.peek()>='0'&&cin.peek()<='9') {
        int broj;
        cin>>broj;
        stek.Gurni(broj);
      }
      else {
        char znak=cin.get();
        if(znak!='+'&&znak!='-'&&znak!='*'&&znak!='/') {
          cout<<"Pogresna operacija!\n";
          break;
        }
        if(stek.Velicina()<2) {
          cout<<"Manjka podataka na steku za izvodjenje operacije!\n";
          break;
        }
        double operand1=stek.Skini();
        double operand2=stek.Skini();
        double rezultat;
        if(znak=='+') rezultat=operand2+operand1;
        else if(znak=='-') rezultat=operand2-operand1;
        else if(znak=='*') rezultat=operand2*operand1;
        else rezultat=operand2/operand1;
        stek.Gurni(rezultat);
      }
    }
    cout<<"Stanje steka: ";
    while(!stek.Prazan())
      cout<<stek.Skini()<<" ";
    cout<<endl;
    cin.ignore(1000,'\n');
  }
}
