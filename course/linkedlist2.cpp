//IMPLEMENTED INSERTING A NODE AT THE BEGINNING OF THE LINKED LIST
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* NextAdd;
};
Node* head; //used a global variable to access it in function instead of passing it to each function 
void InsertAtBegin(int x){
Node* temp=new Node;  //creating a node
temp->data=x;
temp->NextAdd=nullptr; //initially setting the node link as null   
if(head==nullptr){  //if the list is empty
    head=temp;
}
else if(head!=nullptr){ //if the list is not empty
    temp->NextAdd=head;
    head=temp;
}
}
void printlist(){
    Node* temp=head;
    cout<<"List is: ";
    while(temp!=nullptr){  //better than the first print function wrote in linkedlist1.cpp                     
        cout<<temp->data<<" ";
        temp=temp->NextAdd;
        }
}
int main(){
    head=nullptr;//empty linked list
    int num;
    cout<<"Enter the number of elements you want: ";
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        int data;
        cout<<endl<<"Enter the number : ";
        cin>>data;
        InsertAtBegin(data);
        printlist();
    }

    return 0;
}
/*If the head variable was not a global if declared inside the main function,instead of 
creating temp pointer again and again and using memory what we can do is we can pass the 
copy of the head variable to the functions */
/*So there are 3 ways 
1)using the global head variable in fucntions with temp pointer
2)passing the head pointer as a parameter in funciton and using tmep pointer
3)declaring the head in main() and passing its copy to the fucntion and using it as a temp 
pointer*/