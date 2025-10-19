/*Implemented linked list and made function to insert a node at nth place/index*/
#include <iostream>
using namespace std;
struct Node{
int data;
Node* NextAdd;
};
Node* head=nullptr;
void printlist(){
    cout<<"LIST: [";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void Insert(int dat,int pos){
    cout<<"Creating a Node!\n";
    Node* temp1=new Node;//ptr to node
    temp1->data=dat;
    temp1->NextAdd=nullptr;
    if(pos==1){
        temp1->NextAdd=head;
        head=temp1;
        return; //we can end the function here by the return statement
    }
    Node* temp2=head;//ptr used to traverse
    for(int i=0;i<pos-2;i++){
        temp2=temp2->NextAdd;
    }
    temp1->NextAdd=temp2->NextAdd;
    temp2->NextAdd=temp1;
    
}
void listlen(Node* head){ //passsing a copy of head instead of creating a new pointer
    int count=0;
    while(head!=nullptr){
        count++;
        head=head->NextAdd;
        }
        cout<<"The length of the list is: "<<count<<endl;
}
int main(){
    Insert(1,1);
    Insert(2,1);
    Insert(4,3);
    Insert(9,4);
    printlist();
    listlen(head);
    return 0;
}