/*IMPLEMENTED STACK USING LINKED LIST IMPLEMENTATION.MADE FUNCTIONS FOR PUSH,POP,TOP,PRINT
NOTE:THIS IS AN OOP BASED APPROACH BY ME */
/*There are two ways to implement stack using linked list,
1)insert/delete at the end(tail) complexity O(n)
2)insert/delete at the beginning(head) complexity O(1)
so obviusly we will go for head as it is more optimal solution*/
#include <iostream>
using namespace std;
class stackusingll;
class Node{
protected:
int data;
Node* Nextadd;
void setdata(int x){
    data=x;
}
public: //constructor is always in public
Node(){
    data=0;
    Nextadd=nullptr;
}

friend stackusingll; //made this as friend to access protected members
};
class stackusingll : public Node{
private:
Node* top; //here top is our head according to the linked list we implemented previously
public:
stackusingll(){
top=nullptr;
}
void PUSH(int x){ //this is nothing but insert at beginnig function
Node* newNode=new Node;
// newNode->data=x; can't do this here because newnode here is a pointer to an new object which neither belongs to new node created in the memory
newNode->setdata(x); //we can do newNode->data=x as we have made the stackusingll friend of calss node
if(top==nullptr){
    top=newNode;
    return;
}
newNode->Nextadd=top;
top=newNode;

}
void POP(){ //delete from beginning
if(top==nullptr){
    cout<<"CAN'T POP,STACK EMPTY!\n";
    return;
}
    Node* temp=top;
    top=temp->Nextadd;
    delete temp;
}
Node* TOP(){ //returns top element of stack
    cout<<"TOP:"<<top->data<<endl;
    return top; 
}
void PRINTSTACK(){
    if(top==nullptr){
        cout<<"EMPTY STACK!!\n";
        return;
    }
    cout<<"STACK:[";
    Node* temp=top;
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->Nextadd;
    }
    cout<<"]\n";
}
};
int main(){
    stackusingll stack1;
    stack1.PRINTSTACK();
    stack1.PUSH(4);
    stack1.PUSH(3);
    stack1.PUSH(2);
    stack1.PUSH(1);
    stack1.POP();
    stack1.PRINTSTACK();
    stack1.TOP();
    return 0;
}