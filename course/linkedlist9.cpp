/*IMPLEMENTED A LINKED LIST AND REVERSED IT USING A RECURSIVE FUNCTION WHEN HEAD IS NOT A GLOBAL 
VARIABLE*/
/*TIP/NOTE:GRAB A PEN AND PAPER TO UNDERSTAND THE LOGIC BEHIND THE RECURSIVE FUNCTION ,SEE THE CONTROL
FLOW BY FUNCTION CALL ON PAPER*/
#include <iostream>
using namespace std;
struct Node{
int data;
Node* NextAdd;
};
Node*& InsertNode(Node* &h,int dat,int pos){
    Node* temp=new Node;
    temp->data=dat;
    temp->NextAdd=nullptr;
    if(pos==1 or h==nullptr){
        temp->NextAdd=h;
        h=temp;
        return h; //don't forget to put this return here or the program may not stop from here
    }
    Node* temp1=h;
    for(int i=0;i<pos-2;i++){
        if(temp1->NextAdd==nullptr) break; //this solves the problem of when someone gives and input like given now in main function
        temp1=temp1->NextAdd;
    }
    temp->NextAdd=temp1->NextAdd;
    temp1->NextAdd=temp;
    return h;
}
void printlist(Node* h){
cout<<"LIST[";
    Node* temp=h;
while(temp!=nullptr){
    cout<<temp->data<<",";
    temp=temp->NextAdd;
}
cout<<"]\n";
}
Node* ReverseTheList(Node* head){ /*wondering why to return the head pointer check it out in the mainfunction*/
    //WE USED HEAD AS A LOCAL TRAVERSING VARIABLE HERE
    if(head->NextAdd==nullptr || head==nullptr){
        return head; //this will contain the new head
    }
    Node* q =ReverseTheList(head->NextAdd);
    head->NextAdd->NextAdd=head;
    head->NextAdd=nullptr;
    return q ;//this will carry the new head(head in line 37)
}
int main(){
    Node* head=nullptr; 
    InsertNode(head,1,1);
    InsertNode(head,7,5);
    InsertNode(head,3,2);
    InsertNode(head,4,3);
    printlist(head);
    head=ReverseTheList(head);
    printlist(head);
    return 0;
}