#include<iostream>
using namespace std;
int main(){
    int a;

    cout<<"Enter the number: ";
    cin>>a;

    if(a%2==0){
        cout<<a<<" is an even number!";
    }
    else if (a%2==1){
        cout<<a<<" is an odd number!";
    }
    else{
        cout<<"Invalid Data type!";
       }

    system("pause");
    return 0;
}