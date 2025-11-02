//OBJECT ORIENTED IMPLEMENTATION OF STACK USING ARRAY
#include <iostream>
#define MAXSIZE 100 //MACRO
using namespace std;
class stack{
private:
int arr[MAXSIZE]; //actual stack storage
int top=-1; //varible to track the top of the stack
public:
void PUSH(int x){ //pushes element to the top of the stack
    if(top==MAXSIZE){ //handling stack overflow(if array reaches it max limit array full)
    cout<<"Stack overflow!!\n";
    return;
}
    arr[++top]=x;
}
void POP(){ /*removes element from the top of the stack NOTE:IN THIS WE DECREMENT THE VALUE OF TOP
    AND DO NOT CARE ABOUT THE ELEMENTS AFTER THE TOP INDEX IN ARRAY THEY ARE GARBAGE AT THIS POINT*/ 
if(top==-1){ //cannot pop element from an empty stack
    cout<<"EMPTY STACK!!CANNOT POP ELEMENT\n";
    return;
}
cout<<"POPPED:"<<arr[top]<<endl;
top--;
}
int TOP(){//returns the top element
return arr[top];
}
void PRINTSTACK(){ //not a standard function for stack just for our convenience
cout<<"STACK:[";
    for(int i=0;i<=top;i++){ //DON'T USE FOR EACH LOOP WE DON'T WANT TO PRINT WHLE ARRAY
    cout<<arr[i]<<",";
}
cout<<"]\n";
}
};
int main(){
    stack s1;
    s1.PUSH(1);
    s1.PUSH(2);
    s1.PUSH(3);
    s1.PUSH(4);
    s1.PRINTSTACK();
    s1.POP();
    s1.PRINTSTACK();
    cout<<"TOP ELEMENT OF STACK:"<<s1.TOP()<<endl;
    return 0;
}