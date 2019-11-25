#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int Prioritet(char Znak) {
  if(Znak=='*'||Znak=='/') return 2;
  else if(Znak=='+'||Znak=='-') return 1;
  else return 0;
}

int main() {
  while(1) {
    stack<char> Stek;
    int BrojZagrada=0,Balans=0;
    char Prethodni='(';
    cout<<"Unesi izraz: ";
    try {
      while(cin.peek()!='\n') {
        if(cin.peek()>='0'&&cin.peek()<='9') {
          double Broj;
          cin>>Broj;
          cout<<Broj<<" ";
          Balans++; Prethodni='0';
        }
        else {
          char Znak=cin.get();
          if(Prioritet(Znak)>0) {
            if(Prioritet(Prethodni)>0||Prethodni=='(')
              throw "Neocekivan operator!";
            while(1) {
              if(Stek.empty()||Prioritet(Znak)>Prioritet(Stek.top())) {
                Stek.push(Znak); break;
              }
              cout<<Stek.top()<<" ";
              Stek.pop(); Balans--;
            }
          }
          else if(Znak=='(') {
            Stek.push('('); BrojZagrada++;
          }
          else if(Znak==')') {
            BrojZagrada--;
            if(BrojZagrada<0) throw "Visak zatvorena zagrada!";
            while(Stek.top()!='(') {
              cout<<Stek.top()<<" ";
              Stek.pop(); Balans--;
            }
            Stek.pop();
          }
          else throw "Neocekivan znak!";
          Prethodni=Znak;
        }
      }
      if(BrojZagrada>0) throw "Nedostaje zatvorena zagrada!";
      while(!Stek.empty()) {
        cout<<Stek.top()<<" ";
        Stek.pop();
        Balans--;
      }
      if(Balans!=1) throw "Neizbalansirani operatori i operandi!";
    }
    catch(const char Poruka[]) {
      cout<<endl<<Poruka;
    }
    cout<<endl<<endl;
    cin.ignore(1000,'\n');
  }
  return 0;
}
