#include<iostream>
using namespace std;
int main(){
    
    int random=rand()%100;
    int guess,attempt=1;
    cout<<"guess the number"<<endl;
    cin>>guess;
    while(guess!=random){
        if(guess>random)
        cout<<"large"<<endl;
        else
        cout<<"small"<<endl;
        cin>>guess;
        attempt++;
    
    }

    cout<<" you have guessed it in "<<attempt<<" attempt";

    return 0;
}