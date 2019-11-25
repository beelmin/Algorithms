#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int fib(int n) {
   int rez,a,b;
   stack<int> s;
X: if(n<3) 
     rez=1;
   else {
     s.push(a); s.push(b); s.push(n); s.push(1);
     n-=1; goto X;
Y:   a=rez;
     s.push(a); s.push(b); s.push(n); s.push(2);
     n-=2; goto X;
     
Z:  b=rez;
    rez=b+a;
	}	


	if(!s.empty()) {
     int gdje=s.top(); s.pop();
     n=s.top(); s.pop();
     b=s.top(); s.pop();
     a=s.top(); s.pop();
     if(gdje==1) goto Y;
     else 
		goto Z;
   }
   return rez;
}

int main() {
  for(int i=1;i<=10;i++) cout<<fib(i)<<" ";
  getch();
}
