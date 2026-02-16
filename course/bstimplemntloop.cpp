/*Implemented binary search tree without recursion using loops */
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
        for(BSTNode* temp=root;true;){
        if(root==nullptr){
            root=GetNewNode(data);
            break;
        }else if(data<=temp->data){
            if(temp->left==nullptr){
                temp->left=GetNewNode(data);
                break;
            }else{
                temp=temp->left;
            }
            
        }else{
            if(temp->right==nullptr){
                temp->right=GetNewNode(data);
                break;
            }else{
                temp=temp->right;
            }
        }
    }
        return root; 
    }
    bool Search(BSTNode* root,int data){  
        if(root==nullptr)return false;
        BSTNode*temp=root;
        while(temp!=nullptr){
            if(temp->data==data) return true;
            if(temp->data>data){
                temp=temp->left;
                
            }else{
                temp=temp->right;
                
            }
        }
        return false;
    
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
    root=bst1.InsertNode(root,-1);
    int data=0;
    if(bst1.Search(root,data)) {cout<<"found "<<data<<" in tree\n";}
    else{cout<<"Not found "<<data<<" in tree\n";}
    return 0;
}