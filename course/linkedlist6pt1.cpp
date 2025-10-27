/*IMPLEMENTED THE LINKED LIST ,MODIFIED THE INSERT AT NTH POSITION FUNCITON AND CREATED A FUNCTION TO 
REVERSE THE LINKED LIST IN PT1,AND MODIFIED THE REVERSE FUNCTION AND MADE IT BETTER IN PT2*/  
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
if(pos==1 or head==nullptr){ //this condition handle if initially the given index is too large to start with.Like if list is empty and given index is 3 then it will handle it
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
Node* temp=head;
Node* StorePrev,*StoreNext;
// Node* StorePrev,StoreNext; never do this here StoreNext becomes a variable(obj) of the Node struct
while(temp!=nullptr){/*what we did in this function is we traversed to each node and stored its current
    positon(StorePrev) and its next position(StoreNext),and then pointed the nextadd of the node to the 
    previous node(Node->NextAdd=StorePrev) */
    if(temp==head){
        StoreNext=temp->NextAdd;
        temp->NextAdd=nullptr;
    StorePrev=temp;
    temp=StoreNext;
}else{
StoreNext=temp->NextAdd;
temp->NextAdd=StorePrev;
StorePrev=temp;
temp=StoreNext;
}}
head=StorePrev;
}//this function is wirtten and logic built by me refer pt2 for better function eliminating if else block 
//by making the StorePrev=nullptr
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