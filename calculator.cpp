#include<iostream>
using namespace std;
int main(){
  int x,y;
  cout<<"enter two numbers"<<endl;
  cin>>x>>y;
  int choice;
  cout<<" 1: addition"<<endl;
  cout<<" 2: subtraction "<<endl;
  cout<<" 3: multiplication"<<endl;
  cout<<" 4: division"<<endl;
  cin>>choice;
  switch (choice)
  {
  case 1:
  cout<<x+y;
    break;
    case 2:
  cout<<x-y;
    break;
    case 3:
  cout<<x*y;
    break;
  case 4:
  cout<<x/y;
    break;
  default:
  cout<<"wrong choice entered"<<endl;
    break;
  }
    return 0;
}