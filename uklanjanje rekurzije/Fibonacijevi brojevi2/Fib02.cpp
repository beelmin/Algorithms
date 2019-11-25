#include <iostream>
#include <conio.h>

using namespace std;

int fib(int n) {
  int rez,a,b;
  if(n<3) rez=1;
  else {
    a=fib(n-1);
    b=fib(n-2);
    rez=a+b;
  }
  return rez;
}

int main() {
  for(int i=1;i<=50;i++) cout<<fib(i)<<" ";
  getch();
}
