/*IMPLEMENTED A LINKED LIST AND CREATED FUNCTIONS TO PRINT THE LINKED LIST USING RECURSION,
ALSO PRINTING IN REVERSE ORDER*/
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
if(pos==1){
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
//function using recursion to print elements of linked list
void PrintList(Node* h){ //logic and coded by myself
if(h==nullptr){return;}
    cout<<h->data<<",";
    h=h->NextAdd;
    PrintList(h);
}
void PrintList2(Node* h){ //optimized version better
if(h==nullptr) return;
    cout<<h->data<<",";
PrintList2(h->NextAdd);
}
//function using loops to print list
void printlist(){
    Node* temp=head;
    cout<<"LIST: [";
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void ReversePrint(Node* h){/*this function seems like some sort of trick has been applied to make it work
    but it's working can actually be understood by seeing the recursion tree ,what is happeneing is the 
    stack section of the memory refer the screenshots or the lecture */
    if(h==nullptr) return;
    ReversePrint(h->NextAdd);
    cout<<h->data<<",";
}
//Note:iterative approach is more optimal as it does not need so much stack usage like recursion
int main(){
     InsertNode(1,1);
    InsertNode(3,2);
    InsertNode(6,3);
    InsertNode(9,4);
    PrintList(head);
    cout<<endl;
    printlist();
    PrintList2(head);
    cout<<endl;
    ReversePrint(head);
    return 0;
}