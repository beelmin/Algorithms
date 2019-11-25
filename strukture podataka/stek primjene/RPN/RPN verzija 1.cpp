#include <iostream>
#include <list>

using namespace std;

int main() {
  list<double> stek;
  while(1) {
    cout<<"Unesi RPN izraz: ";
    while(1) {
      while(cin.peek()==' ') cin.get();
      if(cin.peek()=='\n') break;
      if(cin.peek()>='0'&&cin.peek()<='9') {
        int broj;
        cin>>broj;
        stek.push_back(broj);
      }
      else {
        char znak=cin.get();
        if(znak!='+'&&znak!='-'&&znak!='*'&&znak!='/') {
          cout<<"Pogresna operacija!\n";
          break;
        }
        if(stek.size()<2) {
          cout<<"Manjka podataka na steku za izvodjenje operacije!\n";
          break;
        }
        double operand1=stek.back();
        stek.pop_back();
        double operand2=stek.back();
        stek.pop_back();
        double rezultat;
        if(znak=='+') rezultat=operand2+operand1;
        else if(znak=='-') rezultat=operand2-operand1;
        else if(znak=='*') rezultat=operand2*operand1;
        else rezultat=operand2/operand1;
        stek.push_back(rezultat);
      }
    }
    cout<<"Stanje steka: ";
    while(!stek.empty()) {
      cout<<stek.back()<<" ";
      stek.pop_back();
    }
    cout<<endl;
    cin.ignore(1000,'\n');
  }
}
