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
void ReverseList(){
Node* current=head;
Node* StorePrev,*StoreNext;
// Node* StorePrev,StoreNext; never do this here StoreNext becomes a variable(obj) of the Node struct
StorePrev=nullptr;
while(current!=nullptr){/*instead of writing the if else block as done in linkedlist6pt1.cpp
    we can simply eliminate the if block by making the StorePrev=NULL*/
StoreNext=current->NextAdd;
current->NextAdd=StorePrev;
StorePrev=current;
current=StoreNext;
}
head=StorePrev;
}
int main(){
    // cout<<(nullptr==NULL); give true(1)
    InsertNode(1,1);
    InsertNode(3,2);
    InsertNode(6,3);
    InsertNode(9,4);
    printlist();
    ReverseList();
    printlist();

    return 0;
}