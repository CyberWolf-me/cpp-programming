#include<iostream>
using namespace std;
int main(){
    float Temp;
    char unit;

    cout<<"Enter the temperature: ";
    cin>>Temp;

    cout<<"Enter the unit(C/F): ";
    cin>>unit;

    if(unit == 'C' ){
        cout<<"Temperature in Farenheit is: "<<(Temp * 9 / 5) + 32 << "F."<<endl;
    }
    else if ( unit =='F'){
        cout<<"Temperature in Celcius is: "<<(Temp - 32) * 5 / 9<<"C."<<endl;
    }
    else{
        cout<<"Invalid unit(Enter only C/F)";
    }
    system("pause");
    
    return 0;
}