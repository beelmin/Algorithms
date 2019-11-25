#include <iostream>
#include <stack>
#include <cmath>
#include <conio.h>

using namespace std;

int Prioritet(char Znak) {
  if(Znak=='s') return 3;
  else if(Znak=='*'||Znak=='/') return 2;
  else if(Znak=='+'||Znak=='-') return 1;
  else return 0;
}

void IzvrsiOperaciju(stack<double> &s,char Operacija) {

if(Operacija=='-' || Operacija=='+'  || Operacija=='/' || Operacija=='*')
{
  if(s.size()<2) throw "Neizbalansirani operatori i operandi!";
  double Operand1=s.top();
  s.pop();
  double Operand2=s.top();
  s.pop();
  double Rezultat;
  if(Operacija=='+') Rezultat=Operand2+Operand1;
  else if(Operacija=='-') Rezultat=Operand2-Operand1;
  else if(Operacija=='*') Rezultat=Operand2*Operand1;
  else Rezultat=Operand2/Operand1;
  s.push(Rezultat);
}
else{
  if(s.size()<1) throw "Neizbalansirani operatori i operandi (sin)!";
  double Operand1=s.top();
  s.pop();
  s.push(sin(Operand1));
     }
}

int main() {
  while(1) {
    stack<char> Stek;
    stack<double> StekBrojeva;
    int BrojZagrada=0;
    char Prethodni='(';
    cout<<"Unesi izraz: ";
    try {
      while(cin.peek()!='\n') {
        if(cin.peek()>='0'&&cin.peek()<='9') {
          double Broj;
          cin>>Broj;
          StekBrojeva.push(Broj);
          Prethodni='0';
        }
        else {
          char Znak=cin.get();
          cout<<Prethodni<<" -"<<Znak<<endl;
          if(Prioritet(Znak)>0) {
            if((Prioritet(Prethodni)>0 && Znak!='s') || (Prethodni=='(' && Znak!='s') )
              throw "Neocekivan operator!";
            while(1) {
              if(Stek.empty()||Prioritet(Znak)>Prioritet(Stek.top())) {
                Stek.push(Znak); break;
              }
              IzvrsiOperaciju(StekBrojeva,Stek.top());
              Stek.pop();
            }
          // while(cin.peek()>='a' && cin.peek()<='z')cin.get();
        if(Znak=='s'){cin.get();cin.get();}

          }
          else if(Znak=='(') {
            Stek.push('('); BrojZagrada++;
          }
          else if(Znak==')') {
            BrojZagrada--;
            if(BrojZagrada<0) throw "Visak zatvorena zagrada!";
            while(Stek.top()!='(') {
              IzvrsiOperaciju(StekBrojeva,Stek.top());
              Stek.pop();
            }
            Stek.pop();
          }
           else if(Znak=='{') {
            Stek.push('{'); BrojZagrada++;
          }
          else if(Znak=='}') {
            BrojZagrada--;
            if(BrojZagrada<0) throw "Visak zatvorena zagrada!";
            while(Stek.top()!='{') {
              IzvrsiOperaciju(StekBrojeva,Stek.top());
              Stek.pop();
            }
            Stek.pop();
          }
          else throw "Neocekivan znak!";
          Prethodni=Znak;
        }
      }
      if(BrojZagrada>0) throw "Nedostaje zatvorena zagrada!";
      while(!Stek.empty()) {
        IzvrsiOperaciju(StekBrojeva,Stek.top());
        Stek.pop();
      }
      if(StekBrojeva.size()!=1) throw "Neizbalansirani operatori i operandi!";
      cout<<"Rezultat: "<<StekBrojeva.top()<<endl<<endl;
    }
    catch(const char Poruka[]) {
      cout<<Poruka<<endl<<endl;
    }
    cin.ignore(1000,'\n');
  }
  return 0;
}
