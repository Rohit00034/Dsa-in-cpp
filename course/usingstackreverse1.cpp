/*REVERSED A STRING USING A STACK(LL IMPLEMENTATION)*/
//WE CAN ALSO USE STL FOR STACK BY #include <stack> reather than implementing it
/*NOTE: WHEN TO USE WHICH TYPE OF IMPLEMENTATION FOR STACK ,1)ARRAY IMPLEMENTATION OR 2)LINKED LIST 
IMPLEMENTATION.
1)USE ARRAY WHEN:
You know the maximum size in advance.
You want faster access (continuous memory).
You want less memory overhead.
Used in: expression evaluation, recursion simulation, static-size stacks.
PROS:                                  CONS:
A)Fast (O(1) push/pop).                   Fixed size (stack overflow if full).
B)Simple to implement.
C)Better cache performance.
2)USE LINKED LIST WHEN:-
Stack size can grow/shrink dynamically.
You don't know maximum size.
Memory availability is uneven.
PROS:                                             CONS:
A)No fixed size → grows as needed.                  A)Extra memory for pointers.
B)No overflow (unless system is out of memory).     B)Slightly slower due to dynamic memory allocation.                       */
//WE WILL GO WITH LINKED LIST IMPLEMENTATION
#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    char data; //here we will use char as string is a array of characters
    Node* NextAdd;
    Node(){
        data='0';
        NextAdd=nullptr;
    }
};
class LinkedlistAKAStack{ 
protected:
 Node* top=nullptr; //empty stack
public:
void Push(char dat){ //insert at head
    Node* newNode=new Node;
    newNode->data=dat;
    if(top==nullptr){
        top=newNode;
        return;
    }
    newNode->NextAdd=top;
    top=newNode;
}
char POP(){ //delete at head
if(top==nullptr){
    cout<<"STACK IS EMPTY CANNOT POP\n";
    return '0';
}
Node* temp=top;
char CharToReturn=temp->data;
cout<<"POPPED "<<temp->data<<" !"<<endl;
top=top->NextAdd;
delete temp;
return CharToReturn;
}
char TOP(){
    return top->data;
}
};
void ReverseStringUsingStack(string &str){
LinkedlistAKAStack stack;
for(int i=0;i<str.length();i++){
stack.Push(str[i]);
}
for(int i=0;i<str.length();i++){
str[i]=stack.TOP(); //we can also make pop return the variable it popped and do str[i]=stack.POP
stack.POP();
}
}
int main(){
    string a="aggin olleh";
    ReverseStringUsingStack(a);
    cout<<"REVERSED STRING IS:"<<a<<endl;
    return 0;
}