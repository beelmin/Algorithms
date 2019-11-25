#include <iostream>
#include <conio.h>

using namespace std;

void Hanoi(int N,int A,int B) {
  if(N!=0) {
    Hanoi(N-1,A,6-A-B);
    cout<<"Sa "<<A<<" na "<<B<<endl;
    Hanoi(N-1,6-A-B,B);
  }
}

int main() {
  Hanoi(4,1,2);
  getch();
}
