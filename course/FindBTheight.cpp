//Implemented a FindHeight() function to get the height of the tree here this works for all the trees(bt,bst)
#include <iostream>
#include <algorithm>
using namespace std;
class BT;
class Node{
    int data;
    Node* leftAdd;
    Node* rightAdd;
    public:
    Node(){
        data=0;
        leftAdd=nullptr;
        rightAdd=nullptr;
    }
    friend class BT;
};
class BT{
    public:
Node* GetnewNode(int dat){
    Node* NewNode=new Node;
    NewNode->data=dat;
    return NewNode;
}
Node* InsertNewNode(Node* root,int num){ /*this function is based on binary search tree as the
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
void SearchNode(Node* root,int Numtosearch){
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
int FindHeight(Node* root){
    if(root==nullptr){
        return -1;
    }
    int leftHeight=FindHeight(root->leftAdd);
    int rightHeight=FindHeight(root->rightAdd);
    return max(leftHeight,rightHeight)+1;
}
};

int main(){
    BT bt1;
    Node* root=nullptr;

    root=bt1.InsertNewNode(root,3);
    root=bt1.InsertNewNode(root,4);
    root=bt1.InsertNewNode(root,7);
    root=bt1.InsertNewNode(root,0);
    root=bt1.InsertNewNode(root,5);
    bt1.SearchNode(root,-1);
    cout<<"Height of the tree is "<<bt1.FindHeight(root)<<endl;
    
    return 0;
}