//IMPLEMENTED FUNCTIONS TO FIND MAXVAL AND MINVAL IN A BST
#include <iostream>
using namespace std;
class BST;
class BSTNODE{
int data;
BSTNODE* left;
BSTNODE* right;
public:
BSTNODE(){
    data=0;
    left=right=nullptr;
}
friend class BST;
};
class BST{
    BSTNODE* GetNewNode(int x){
        BSTNODE* NewNode=new BSTNODE;
        NewNode->data=x;
        return NewNode;
    }
    public:
    BSTNODE* InsertNode(BSTNODE* root,int data){
        if(root==nullptr){
            root=GetNewNode(data);
            }
        else if(data<=root->data){
            root->left=InsertNode(root->left,data);
        }
        else{
            root->right=InsertNode(root->right,data);
        }
        return root;
    }
    bool Search(BSTNODE* root,int data){
        if(root==nullptr){
            cout<<"TREE IS EMPTY\n";
            return false;
        }
        else if(data==root->data){
            
            return true;
        }
        else if(data<=root->data){
            return Search(root->left,data);
        }else{
            return Search(root->right,data);
        }
    }
    //ITERRATIVE APPROACH TO FIND MAX AND MIN IN TREE
    int FindMaxIter(BSTNODE* root){//root here is a local variable so we can use root to travers the tree
        if(root==nullptr){
            cout<<"EMPTY TREE\n";
            return -1; //cannot return null
        }
        else{
            while(root->right!=nullptr){
                root=root->right; //go as right as possible
            }

        }
        return root->data;
    }
    int FindMinIter(BSTNODE* root){//root here is a local variable so we can use root to travers the tree
        if(root==nullptr){
            cout<<"EMPTY TREE\n";
            return -1; //cannot return null
        }
        else{
            while(root->left!=nullptr){
                root=root->left;//go as left as possible
            }

        }
        return root->data;
    }
    //RECURSIVE APPROACH TO FIND MAX AND MIN IN THE TREE
    int FindMaxRecur(BSTNODE* root){
        int maxval;
        if(root==nullptr){
            cout<<"TREE IS EMPTY\n";
        }
        else {
            if(root->right!=nullptr){
                 maxval=FindMaxRecur(root->right);//if i call FindMinRecur here(root->right) i will get the min element in the right tree
            }else{
                maxval=root->data;
            }
        }
        return maxval;
    } 
    int FindMinRecur(BSTNODE* root){
        int minval;
        if(root==nullptr){
            cout<<"TREE IS EMPTY\n";
        }
        else {
            if(root->left!=nullptr){
                 minval=FindMinRecur(root->left); //if i call FindMaxRecur here(root->left) i will get the max element in the left tree
            }else{
                minval=root->data;
            }
        }
        return minval;
    } 
};
int main(){
    BST b1;
    BSTNODE* root=nullptr;
    root=b1.InsertNode(root,20);
    root=b1.InsertNode(root,21);
    root=b1.InsertNode(root,28);
    root=b1.InsertNode(root,5);
    root=b1.InsertNode(root,1);
    root=b1.InsertNode(root,0);
    root=b1.InsertNode(root,-1);
    root=b1.InsertNode(root,8);
    int data=0;
    b1.Search(root,data)? cout<<"Found "<<data<<" in tree\n":cout<<"NOT Found "<<data<<" in tree\n";
    cout<<"MAX ELEMENT IN THE TREE IS : "<<b1.FindMaxIter(root)<<endl;
    cout<<"MIN ELEMENT IN THE TREE IS : "<<b1.FindMinIter(root)<<endl;
    cout<<"Max ELEMENT IN THE TREE IS : "<<b1.FindMaxRecur(root)<<endl;
    cout<<"Min ELEMENT IN THE TREE IS : "<<b1.FindMinRecur(root)<<endl;
    return 0;
}