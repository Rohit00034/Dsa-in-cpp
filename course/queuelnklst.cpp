/*Implemented queue using linked list approach ,remember from front we dequeue that is head of the linked list and from rear
we enqueue that is the tail of the linked list.Check notes for more info and visual representation*/
#include <iostream>
using namespace std;
class Queue;
class Node{
    private:
    int data;
    Node* NextAdd;
    public:
    Node(){
        data=0;
        NextAdd=nullptr;
    }
    friend class Queue;
};
class Queue{ //actually a linked list 
    Node* rear=nullptr;//tail //don't forget to keep the rear and front nullptr, make a constructor instead or you wiil get code to debug!! :)
    Node* front=nullptr; //head
    public:
    void Enqueue(int x){
        Node* NewNode=new Node;
        NewNode->data=x;
        if(rear==nullptr & front==nullptr){ //queue(list) is empty
            rear=front=NewNode;
        }
        // }else if(rear==front and front!=nullptr){
        // no need for this case as below else does the same 
        // }
        else{ //queue(list) is not empty
            rear->NextAdd=NewNode;
            rear=NewNode;

        }
     }
     void Dequeue(){
        if(front==nullptr & rear==nullptr){
            cout<<"Queue is empty!!\n"; //queue is empty
        }else if(rear==front & rear!=nullptr){ //only one element in the list
            Node* temp=front;
            front=rear=nullptr;
            cout<<"Dequeued "<<temp->data<<" from queue\n";
            delete temp;
        }
        else{
            Node* temp=front;
            front=front->NextAdd;
            cout<<"Dequeued "<<temp->data<<" from queue\n";
            delete temp;
        }
     }
     Node* returnFront(){//not so useful since data and nextadd are private  in the node class
        return front;
     }
     int ReturnFrontVal(){
         return front->data;
     }
     bool IsEmpty(){
        if(front==rear & front==nullptr){
            return true;
        }else{
            return false;
        }
     }
     void printQueue(){
        Node* temp=front;
        cout<<"Front->[";
        while(temp!=nullptr){
            cout<<temp->data<<",";
            temp=temp->NextAdd;
        }
        cout<<"]<-Rear\n";
     }
};
int main(){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(5);
    q1.Enqueue(8);
    q1.Enqueue(3);
    q1.printQueue();
    q1.Dequeue();
    q1.Dequeue();
    q1.printQueue();
    cout<<q1.ReturnFrontVal()<<endl;
    string res=(q1.IsEmpty())? "Queue is empty":"Queue is not empty"; //short hand if else
    cout<<res<<endl;
    q1.Enqueue(7);
    q1.Enqueue(4);
    q1.printQueue();
    return 0;
}