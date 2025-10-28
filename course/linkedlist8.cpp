//IMPLEMENTED LINKED LIST AND CREATED A RECURSIVE FUNCTION TO ACTUALLY REVERSE THE LINKED LIST
#include <iostream>
using namespace std;
struct Node{
int data;
Node* NextAdd;
};
Node* head=nullptr;
void InsertNode(int dat,int pos){
Node* temp1=new Node;
temp1->data=dat;
temp1->NextAdd=nullptr;
if(pos==1 or head==nullptr){
    temp1->NextAdd=head;
    head=temp1;
    return;
}
Node* temp2=head;
for(int i=0;i<pos-2;i++){
    temp2=temp2->NextAdd;
}
temp1->NextAdd=temp2->NextAdd;
temp2->NextAdd=temp1;
}
void printlist(){
    Node* temp=head;
    cout<<"LIST: [";
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void ReverseTheList(Node* h1){
    if(h1->NextAdd==nullptr){
        head=h1;
        return;
    }
    ReverseTheList(h1->NextAdd);
    Node* h2=h1->NextAdd; //WE CAN ELIMINATE THIS LINES BY REPLACING THEM WITH H1->NEXTADD->NEXTADD=H1
    h2->NextAdd=h1;
    h1->NextAdd=nullptr;
}
int main(){
     InsertNode(1,1);
    InsertNode(3,2);
    InsertNode(6,3);
    InsertNode(9,4);
    printlist();
    ReverseTheList(head);
    printlist();
    return 0;
}