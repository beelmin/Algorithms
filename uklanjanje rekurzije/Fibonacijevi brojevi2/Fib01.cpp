#include <iostream>
#include <conio.h>

using namespace std;

int fib(int n) {
  if(n<3) return 1;
  else return fib(n-1)+fib(n-2);
}

int main() {
  for(int i=1;i<=50;i++) cout<<fib(i)<<" ";
  getch();
}
