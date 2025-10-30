/*IMPLEMENTED DOUBLY LINKED LIST AND MADE FUNCTION TO INSERT AT THE HEAD ,INSERT AT TAIL,INSERT AT NTH
POSITION,PRINT LIST,REVERSE PRINT THE LIST,DELETE A NODE AT NTH POSITON IN THE LIST */
/*THE ADVANTAGE OF DOUBLY LINKED LIST IS THAT WE CAN REVERSE LOOK UP THE LIST AND THE DISADVANTAGE IS 
IT REQUIRES MORE MEMORY THAN THE SINGLY LINKED LIST */
//DO CHECK OUT HOW THE MEMORY ALLOCATION IS DONE IN STACK,HEAP,STATIC/GLOBAL(GLOBAL VARIABLES)
#include <iostream>
using namespace std;
struct Node{
int data;
Node*NextAdd;
Node*PrevAdd;
};
Node* head=nullptr;
void InsertNodeAtHead(int dat){
Node*temp=new Node;
temp->data=dat;
temp->NextAdd=nullptr;
temp->PrevAdd=nullptr;
if(head==nullptr){ //if the list is empty
    head=temp;
    return;
}
temp->NextAdd=head;
head->PrevAdd=temp;
head=temp;
}
void PrintList(){
    cout<<"LIST[";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void ReversePrintTheList(){
    cout<<"LIST[";
    Node* temp=head;
    while(temp->NextAdd!=nullptr){
        temp=temp->NextAdd;
    }
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->PrevAdd;
    }
    cout<<"]\n";
}
void InsertAtTail(int dat){
    Node* temp=new Node;
    temp->data=dat;
    temp->NextAdd=nullptr;
    temp->PrevAdd=nullptr;
    if(head==nullptr){
        head=temp;
        return;
    }
    Node* traverser=head;
    while(traverser->NextAdd!=nullptr){
        traverser=traverser->NextAdd;
    }
    traverser->NextAdd=temp;
    temp->PrevAdd=traverser;
}
int InsertAtNth(int dat,int pos){
Node* temp=new Node;
temp->data=dat;
temp->NextAdd=nullptr;
temp->PrevAdd=nullptr;
Node* traverser=head;
if(head==nullptr){ //if list is empty
cout<<"List is empty inserting at first position\n";
    head=temp;
return 1;
}
for(int i=0;i<pos-1;i++){ //in this we are directly going to the nth position and changing not like we did in the linked list at (n-1)th postion,beacause here we can traverse back
traverser=traverser->NextAdd;
}
temp->NextAdd=traverser;
temp->PrevAdd=traverser->PrevAdd;
traverser->PrevAdd->NextAdd=temp; //(n-1)th node lnkking to new node
traverser->PrevAdd=temp;
return pos; //we will use this to show at which postion it is printed
}
int DeleteNode(int pos){
    if(head==nullptr){
        cout<<"list is empty no elements to delete\n";
        return 0;
    }
    Node* traverser=head;
    for(int i=0;i<pos-1;i++){
        traverser=traverser->NextAdd;
    }
    traverser->PrevAdd->NextAdd=traverser->NextAdd;
    traverser->NextAdd->PrevAdd=traverser->PrevAdd;
    delete traverser;
    return pos;
}
int main(){
    cout<<"Printing before inserting nothing\n";
    PrintList();
    InsertNodeAtHead(1);
    InsertNodeAtHead(2);
    InsertNodeAtHead(3);
    InsertNodeAtHead(4);
    cout<<"Printing after inserting at head\n";
    PrintList();
    InsertAtTail(0);
    cout<<"Printing after inserting at tail\n";
    PrintList();
    cout<<"Printing after inserting at "<< InsertAtNth(6,3)<<"th postion"<<endl;
    PrintList();
    cout<<"Printing the list after Deleting node at "<< DeleteNode(4)<<"th position\n";
    PrintList();
    cout<<"Reverse printing the list\n";
    ReversePrintTheList();
    return 0;
}