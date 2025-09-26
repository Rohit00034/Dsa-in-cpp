#include <iostream>
using namespace std;
/*A linked list has various nodes in it which are linked to together to form a data 
structure ,A node is divided in 2 parts 1st part has data and 2nd has the address to the
next node.the first node of the linked list is called the head node and the last node in 
the linked list is called tail and points to NULL .We use pointer to store the location
of the head node(start of linked list),it points to Null if linked list is empty*/
//we can also use template to make a linked list store any type of data
struct Node{
int data;
Node* NextAdd;
};
//function to traverse and print all the data of linked list
void printlnkdlst(Node* start){
    Node* temp=start;
    while(temp->NextAdd!=nullptr){
    temp=temp->NextAdd;
    cout<<temp->data<<endl;
}
}
int main(){
    Node* Aptr;
    // Aptr=NULL; this indicates list is empty
    //creating a node
    Node*Node1=new Node; //can also write Node*Node1=new Node(); here Node() may represent a constructor
    //now Aptr will point to the Node1
    Aptr->NextAdd=Node1;
    //assigning a value in the the Node1
    (*Node1).data=1;
     // Node1->NextAdd=NULL;//i can also equate it to a nullpointer(nullptr) 
    Node* Node2=new Node; //creating 2nd node
    Node1->NextAdd=Node2; //conneted node1 to node2
    Node2->data=2;//assigning a value in the 2nd node
    // Node2->NextAdd=nullptr;
    Node* Node3=new Node;//creating 3rd node
    Node2->NextAdd=Node3;//conneted node2 to node3
    Node3->data=3;
    Node3->NextAdd=nullptr;
    //CURRENT LINKED LIST STRUCTURE
    // Aptr------------>Node1---------->Node2------->Node3
    //NULL|&Node1    [1]|&Node2     [2]|&Node3   [3]|nullptr(NULL)
    printlnkdlst(Aptr);
    return 0;
}