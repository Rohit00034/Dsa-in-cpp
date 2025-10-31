/*IMPLEMENTED CIRCULAR LINKED LIST AND IMPLEMENTED FUNCTION TO INSETR AND DELETE AT HEAD AND TAIL AND 
PRINT THE LIST */
//THIS IS LEARNT FROM https://www.youtube.com/watch?v=e6lZY5Yha8U&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=64
#include <iostream>
using namespace std;
//trying a different programming appraoch(class approach)
class Node{
    public:
    int data;
    Node* NextAdd;
    Node(){
        data=0;
        NextAdd=nullptr;
    }
};
class circularLL{
public:
Node* head;
Node* tail; //here tail pointer is essential to know where the tail is beacue a circle never has a tail
circularLL(){
    head=nullptr;
    tail=nullptr;
}
void InsertAthead(int val){
    Node* newNode=new Node;
    newNode->data=val;
    if(head==nullptr||tail==nullptr){//if list is empty
        head=tail=newNode;
        newNode->NextAdd=newNode;
    }
    else{
        newNode->NextAdd=head;
        head=newNode;
        tail->NextAdd=newNode;
    }

}
void printList(){
    if(head==nullptr) {cout<<"LIST IS EMPTY!!\n"; return;}//if list is empty
    cout<<"LIST["<<head->data<<",";
    Node* temp=head->NextAdd;
    while(temp!=head){ //we cannot do temp!=nullptr because it will never occur
     cout<<temp->data<<",";
     temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void InsertAtTail(int val){
    Node* newNode=new Node;
    newNode->data=val;
    if(head==nullptr){ //if list is empty
        head=tail=newNode;
        newNode->NextAdd=head;
    }
    else{
     newNode->NextAdd=head;
     tail->NextAdd=newNode;
     tail=newNode;
    }
     
}
void DeleteAtHead(){ //3 cases 1)if list is empty 2)if there is single node 3)if there are 2 or more nodes
if(head==nullptr){cout<<"Cannot delete! List Is Empty!!\n"; return;}
else if((head==tail)& head!=nullptr){ //singular element exists
    Node* temp=head;
    head=tail=nullptr;
    delete temp; return;
}
else{
    tail->NextAdd=head->NextAdd;
    delete head; //this won't delete head from the stack segment of memory it will clear the node at heap memory
    head=tail->NextAdd;
}
}
void DeleteAtTail(){ //three cases same a above
 if(head==nullptr){cout<<"Cannot delete! List Is Empty!!\n"; return;}
else if((head==tail)& head!=nullptr){ //singular element exists
    Node* temp=head;
    head=tail=nullptr;
    delete temp; return;
}
else{
Node* temp=head;
while(temp->NextAdd!=tail){
    temp=temp->NextAdd;
}
temp->NextAdd=tail->NextAdd;
delete tail;
tail=temp;
}   

}
};


int main(){
circularLL cll;
cout<<"Printing empty list\n";
cll.printList();
cll.InsertAthead(1);
cll.InsertAthead(2);
cll.InsertAthead(3);
cll.InsertAthead(4);
cout<<"Printing list after inserting elements at head\n";
cll.printList();
cll.InsertAtTail(0);
cll.InsertAtTail(9);
cout<<"Printing list after inserting elements at tail\n";
cll.printList();
cout<<"Printing list after deleting element at head\n";
cll.DeleteAtHead();
cll.printList();
cout<<"Printing list after deleting element at tail\n";
cll.DeleteAtTail();
cll.printList();
circularLL cll2; //we now have another circular linked list
cll2.DeleteAtHead();
    return 0;
}