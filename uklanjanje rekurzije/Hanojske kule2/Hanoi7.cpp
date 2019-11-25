#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

void Hanoi(int N,int A,int B) {
   stack<int> s;
   
   while(N!=0) {
     s.push(N); s.push(A); s.push(B);
     N--; B=6-A-B;
    
   }
   
  while(!s.empty()) {
     B=s.top(); s.pop();
     A=s.top(); s.pop();
     N=s.top(); s.pop();
     cout<<"Sa "<<A<<" na "<<B<<endl;
     N--; A=6-A-B;  
     while(N!=0) {
       s.push(N); s.push(A); s.push(B);
       N--; B=6-A-B;
      }   
   }
}

int main() {
  Hanoi(4,1,2);
  getch();
}
