#include<iostream>
using namespace std;
int main(){
    int a;

    cout<<"Enter the number: ";
    cin>>a;

    if(a>0){
        cout<<"Number is Positive!";
    }
    else if (a<0){
        cout<<"Number is Negative!";
    }
    else if (a==0){
        cout<<"Number is neither Negative nor Positive!";
    }
    else{
        cout<<"Invalid data type!";
    }

    system("pause");
    return 0;
}