//Implemented DFS PREORDER,INORDER,POSTORDER TRAVERSAL in a DFS traversal in binary tree/graphs
/*Concept Note:there is no variable in c++ which stores data type as a varible like var=int
🔥 Important Concept
C++ is:
Statically typed
Types are decided at compile time
👉 Not like Python:
x = 10
x = "hello"*/ 
#include <iostream>
#include <algorithm>
using namespace std;
template <class T>
class Node{
    protected:
    T data=T(); 
    /*what is T()? 
    This means:
    int → 0
    float → 0.0
    char → '\0'
    string → ""
    ✔ Works for any data type*/
    Node* leftAdd;
    Node* rightAdd;
    public:
    Node(){
        // data=NULL; we cannot initialize this as NULL 
        leftAdd=nullptr;
        rightAdd=nullptr;
    }
    template <class U>
    friend class BT;
};
template <class T>
class BT {
    public:
Node<T>* GetnewNode(T dat){
    Node<T>* NewNode=new Node<T>;
    NewNode->data=dat;
    return NewNode;
}
Node<T>* InsertNewNode(Node<T>* root,T num){ /*this function is based on binary search tree as the
     smaller elements lie on the left and larger ones on right.*/
if(root==nullptr){
    root=GetnewNode(num);
    cout<<"Inserted "<<num<<"\n";
    return root;
}
else if(num<=root->data){
    root->leftAdd=InsertNewNode(root->leftAdd,num);
}
else if(num>root->data){
    root->rightAdd=InsertNewNode(root->rightAdd,num);
}
return root;
}
void SearchNode(Node<T>* root,T Numtosearch){
    if(root==nullptr){
        cout<<Numtosearch<<" Not Found!\n";
    }else if(root->data==Numtosearch){
        cout<<"Found "<<Numtosearch<<"!\n";
    }else if(Numtosearch<=root->data){
        SearchNode(root->leftAdd,Numtosearch);
    }else if(Numtosearch>root->data){
        SearchNode(root->rightAdd,Numtosearch);
    }
}
int FindHeight(Node<T>* root){
    if(root==nullptr){
        return -1;
    }
    int leftHeight=FindHeight(root->leftAdd);
    int rightHeight=FindHeight(root->rightAdd);
    return max(leftHeight,rightHeight)+1;
}
void DFSPreOrder(Node<T>* root){ //DLR(DATA ,LEFT,RIGHT)/VLR(VISIT LEFT RIGHT)
    string A;
    if(root==nullptr){
        cout<<"Empty tree!\n";
    }
    else if(root!=nullptr){//print/data/visit
        cout<<"Node data: "<<root->data<<endl;
    }
    if(root->leftAdd!=nullptr){//left
        DFSPreOrder(root->leftAdd);
    }
    if(root->rightAdd!=nullptr){//right
        DFSPreOrder(root->rightAdd);
    }
}
//here you will see that almost everything in the functions is similar to each other just the order is different just like it is in the dfs traversal
void DFSInOrder(Node<T>* root){ //LDR(,LEFT,DATA RIGHT)/LVR( LEFT VISIT RIGHT)
    string A;
    if(root==nullptr){
        cout<<"Empty tree!\n";
    }
    if(root->leftAdd!=nullptr){//left
            DFSInOrder(root->leftAdd);
        }
    if(root!=nullptr){//print/data/visit
            cout<<"Node data: "<<root->data<<endl;
        }
    if(root->rightAdd!=nullptr){//right
        DFSInOrder(root->rightAdd);
    }
}
void DFSPostOrder(Node<T>* root){ //LRD(,LEFT, RIGHT,DATA)/LRV( LEFT  RIGHT VISIT)
    string A;
    if(root==nullptr){
        cout<<"Empty tree!\n";
    }
    if(root->leftAdd!=nullptr){ //left
            DFSPostOrder(root->leftAdd);
        }
    if(root->rightAdd!=nullptr){//right
            DFSPostOrder(root->rightAdd);
        }
    if(root!=nullptr){//print/data/visit
            cout<<"Node data: "<<root->data<<endl;
        }
}
};


int main(){
    BT<char> bt1;
    Node<char>* root=nullptr;

   root=bt1.InsertNewNode(root,'F');
   root=bt1.InsertNewNode(root,'D');
   root=bt1.InsertNewNode(root,'J');
   root=bt1.InsertNewNode(root,'B');
   root=bt1.InsertNewNode(root,'E');
   root=bt1.InsertNewNode(root,'G');
   root=bt1.InsertNewNode(root,'K');
   root=bt1.InsertNewNode(root,'A');
   root=bt1.InsertNewNode(root,'C');
   root=bt1.InsertNewNode(root,'I');
   root=bt1.InsertNewNode(root,'H');
   bt1.SearchNode(root,'A');
   cout<<"DFS PREORDER: ";
   bt1.DFSPreOrder(root);
   cout<<endl;
   bt1.SearchNode(root,'A');
   cout<<"DFS INORDER: ";
   bt1.DFSInOrder(root);
   cout<<endl;
   cout<<"DFS POSTORDER: ";
   bt1.DFSPostOrder(root);
   cout<<endl;
   return 0;
}