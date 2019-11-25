#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int fib(int n) {
   int rez=1,a,b;
   stack<int> s;
   
 while(n>=3){
      s.push(a); s.push(b); s.push(n--); s.push(1);
  } 
    
 while(!s.empty()) {
 int gdje=s.top(); s.pop();
     n=s.top();    s.pop();
     b=s.top();    s.pop();
     a=s.top();    s.pop();
     
     if(gdje==1)
     {
       a=rez;
       s.push(a); s.push(b); s.push(n); s.push(2);
       n-=2;
       while(n>=3){
         s.push(a); s.push(b); s.push(n--); s.push(1);
        } 
        rez=1;
       
     }
     else 
      {
       b=rez;
       rez+=a;
      }
   }
   return rez;
}

int main() {
  for(int i=1;i<=50;i++) cout<<fib(i)<<" ";
  getch();
}
