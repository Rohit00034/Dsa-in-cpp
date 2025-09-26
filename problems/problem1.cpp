//Check if number is prime or not
//solution: if num is given number mod from 2 to num-1
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int num;
    while(1){cout<<"Enter a number:\n ";
    cin>>num;
    int nd=2;
    bool flag=true;
    
    while(nd<=int(sqrt(num))) //optimal if sqrt(num) we can use num-1 too
    {
        if(num%nd==0){
            flag=false;
            break;
        }
        nd++;
    }
    if(flag==false){
        cout<<"number is not prime\n";
    }else{
        cout<<"Number is prime\n";
    }
    cin.clear();
    cin.ignore(10000,'\n');}
    return 0;
}