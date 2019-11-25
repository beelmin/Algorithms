#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<double> stek;
  while(1) {
    cout<<"Unesi RPN izraz: ";
    while(1) {
      while(cin.peek()==' ') cin.get();
      if(cin.peek()=='\n') break;
      if(cin.peek()>='0'&&cin.peek()<='9') {
        int broj;
        cin>>broj;
        stek.push(broj);
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
        double operand1=stek.top();
        stek.pop();
        double operand2=stek.top();
        stek.pop();
        double rezultat;
        if(znak=='+') rezultat=operand2+operand1;
        else if(znak=='-') rezultat=operand2-operand1;
        else if(znak=='*') rezultat=operand2*operand1;
        else rezultat=operand2/operand1;
        stek.push(rezultat);
      }
    }
    cout<<"Stanje steka: ";
    while(!stek.empty()) {
      cout<<stek.top()<<" ";
      stek.pop();
    }
    cout<<endl;
    cin.ignore(1000,'\n');
  }
}
