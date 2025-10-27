//IMPLEMENTED A LINKED LIST AND DELETED THE NODE BASED ON THE VALUE IN IT NOT THE POSITION
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
void DelNum(int num){ //wee will find the index of given num and pass it to DeleteNode function
Node* temp=head;
bool flag=true;
for(int i=1;temp!=nullptr;i++){
    cout<<"Data is: "<<temp->data<<endl;
    cout<<"Index is: "<<i<<endl;
    if(temp->data==num){
        DeleteNode(i);
        return;
    }
    temp=temp->NextAdd;
    
}
if(flag){
        cout<<"Number not in list\n";
    }
}
void CheckAndDelNum(int num){ /*int his funciton we will check if the number exist in the list if yes 
    we will call the function for each copy we found of the number ,if 3 nines exist then function will be called 3 times*/  
Node* temp=head;
int count=0;
for(int i=0;temp!=nullptr;i++){
    if(temp->data==num){
        count++;
    }
    temp=temp->NextAdd;
}
for(int i=0;i<count;i++){
    DelNum(num);
}
}
int main(){
    InsertNode(1,1);
    InsertNode(3,2);
    InsertNode(6,3);
    InsertNode(9,4);
    InsertNode(9,4);
    InsertNode(9,4);
    InsertNode(9,4);
    printlist();
    CheckAndDelNum(9);
    printlist();
    return 0;
}