//REVERSED A LINKED LIST USING A STACK FROM STL
#include <iostream>
#include <stack>
using namespace std;
class Node{
public:
    int data;
Node* NextAdd;
Node(){
    data=0;
    NextAdd=nullptr;
}
};
class LinkedList;
void reverseLL(LinkedList &l);
class LinkedList{
protected:
Node* head=nullptr;
public:
void InsertAtHead(int dat){
    Node*newNode=new Node;
    newNode->data=dat;
    if(head==nullptr){
      head=newNode;
      return;
    }
    newNode->NextAdd=head;
    head=newNode;
}
void printlist(){
    cout<<"LL:[";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->NextAdd;
    }
    cout<<"]\n";
}
friend void reverseLL(LinkedList &l );
};
// void reverseLL(LinkedList &l){
//     Node*temp=l.head;
//     stack<Node*> s1;
//     while(temp!=nullptr){
//         if(temp->NextAdd==nullptr){
//             l.head=temp;
//         }
//         s1.push(temp);
//         temp=temp->NextAdd;

//     }
//     temp=l.head;
//     while(!s1.empty()){
//       if(temp==s1.top()){
//         s1.pop();
//         continue;
//       }
//       else{
//       temp->NextAdd=s1.top();
//       s1.pop();
//       }
//       temp=temp->NextAdd;
//       if(s1.empty()){
//         temp->NextAdd=nullptr;
//       }
//     }
// } this was made by me ,AND IT WORKS!
void reverseLL(LinkedList &l){
    Node* temp=l.head;
    stack<Node*> s;
    while(temp!=nullptr){
        s.push(temp);
        temp=temp->NextAdd;
    }
    temp=s.top();
    l.head=temp;
    s.pop();
    while(!s.empty()){
        temp->NextAdd=s.top();
        s.pop();
        temp=temp->NextAdd;
    }
    temp->NextAdd=nullptr; //to point the last node to null
}



int main(){
  LinkedList l1;
  l1.InsertAtHead(1);  
  l1.InsertAtHead(4);  
  l1.InsertAtHead(8);  
  l1.InsertAtHead(3);
  l1.printlist(); 
  reverseLL(l1);
  l1.printlist(); 
    return 0;
}