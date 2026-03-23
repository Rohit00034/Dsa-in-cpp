/*Learnt about queue and it's implementation(check notes for more info) ,the queue can be implemented in 2 ways 
1)array 2)linked list
We implemented queue here using array. 
here the index incrementation is done only using (n+1)%N where n is the one to be incremented and num is the lenght of array.
and here the array is a circular array rather than a linear normal one check notes for idea*/
#include <iostream>
using namespace std;
class Queuearr{
int num; //here num is lenght of array and also in notes the N is lenght of array in implementation pov
int* arr;
int rear,front;
    public:
    Queuearr(){
        rear=front=-1;
    cout<<"enter the length of queue:";
    cin>>num;
    arr=new int[num];
}
~Queuearr(){
    delete[] arr;
}
bool Isempty(){
    if(rear==-1 && front==-1){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int x){
if(Isempty()){ //queue is empty
    front=rear=0;
    arr[rear]=x;
    cout<<"Inserted "<<x<<" in queue\n";
}
else if((rear+1)%num==front){  //if revisiing understand this  using pen and paper,check notes for reference
cout<<"ERROR!,Queue is Full!\n"; //queue is full
return;
}
else{        //queue has element in it
rear=(rear+1)%num;
arr[rear]=x;
cout<<"Inserted "<<x<<" in queue\n";
}
}
void dequeue(){
    if(Isempty()){
        cout<<"Queue is empty! cannot remove any element\n";
        return;
    }
    else if(rear==front){ //has only one element
      rear=front=-1;
    }
    else{
      front=(front+1)%num;  //here front+=1 breaks the circular logic beacause in circular the index is determined by (n+1)%N
    }
}
int retFront(){
    return arr[front];
}
void printqueue(){
    cout<<"FRONT->[ ";
    int i=front;
    while(true){
        if(i==rear){
            cout<<arr[i];
            break;
        }
        else{
            cout<<arr[i]<<",";
            i=(i+1)%num;
        }
    }
    cout<<"]<-REAR\n";
}

};
int main(){
    Queuearr queue1;
    cout<<queue1.Isempty()<<endl;
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);
    queue1.enqueue(4);
    queue1.dequeue();
    queue1.dequeue();
    cout<<"FRONT: "<<queue1.retFront()<<endl;
    queue1.printqueue();
    queue1.enqueue(6);
    queue1.enqueue(7);
    queue1.enqueue(9);
    queue1.printqueue();
    return 0;
}