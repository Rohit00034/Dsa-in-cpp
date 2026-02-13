/*Implemented binary search tree with recursion NOTE:WHILE REVISING DO CHECK THE VIDEO AGAIN OR DRAW THE 
RECURSION TREE*/
#include <iostream>
using namespace std;
class BST;
class BSTNode{
private:
int data;
BSTNode* left;
BSTNode* right;
public:
BSTNode(){
    data=0;
    left=right=nullptr;
}
friend class BST;
};
class BST{
    BSTNode* GetNewNode(int x){
        BSTNode* NewNode=new BSTNode;
        NewNode->data=x;
        return NewNode;
    }
    public:
    BSTNode* InsertNode(BSTNode* root,int data){
        if(root==nullptr){
            root=GetNewNode(data);
        }else if(data<=root->data){
            root->left=InsertNode(root->left,data);
        }else{
            root->right=InsertNode(root->right,data);
        }
        return root; 
    }
    bool Search(BSTNode* root,int data){  //IMPLEMENTED USING RECURSION
        if(root==nullptr) return false;//tree empty
        if(root->data==data) return true;
        if(data<=root->data){
            return Search(root->left,data);
        }else{
            return Search(root->right,data);
        }
    }
};
int main(){
    BSTNode* root=nullptr;
    BST bst1;
    root=bst1.InsertNode(root,10);
    root=bst1.InsertNode(root,15);
    root=bst1.InsertNode(root,6);
    root=bst1.InsertNode(root,1);
    root=bst1.InsertNode(root,29);
    bst1.Search(root,14)? cout<<"found 15 in tree\n":cout<<"Not found 15 in tree\n";
    return 0;
}