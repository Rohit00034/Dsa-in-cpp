//IMPLEMENTED LINKED LIST AND CREATED A FUNCTION TO DLETE A NODE AT Nth POSITION
#include <iostream>
using namespace std;
struct Node{
int data;
Node* NextAdd;
};
Node* head=nullptr;//head initially pointing to null(list is empty)
void InsertNode(int dat,int pos){
cout<<"Creating a Node!\n";
Node* temp=new Node;
temp->data=dat;
temp->NextAdd=nullptr;
    if(pos==1){
temp->NextAdd=head;
head=temp;
return;
}
Node* traverser=head;
for(int i=0;i<pos-2;i++){
traverser=traverser->NextAdd;
}
temp->NextAdd=traverser->NextAdd;
traverser->NextAdd=temp;
}
void printlist(){
    Node*temp=head;
    cout<<"LIST: [";
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
void DeleteNode(int pos){
    Node* temp1=head; //creating a pointer to treverse to (n-1)th node
    for(int i=0;i<pos-2;i++){
        temp1=temp1->NextAdd; 
    }
    Node*temp2=temp1->NextAdd;//pointing to the nth node
    temp1->NextAdd=temp2->NextAdd;
    delete temp2; //deleted the node

} 
int main(){
    InsertNode(1,1);
    InsertNode(3,2);
    InsertNode(6,3);
    InsertNode(9,4);
    printlist();
    DeleteNode(3);
    printlist();
    return 0;
}