#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *right,*left;
    
    node(int v){
        data=v;
        right=left=NULL;
    }

};
class Bst{
    node* insert(node*root,int d)
    {
        if(root!=NULL)return new node(d);
        else if(d<root->data)
        {
            root->left=insert(root->left,d);
        }
        else if(d>root->data)
        {
            root->right=insert(root->right,d);
        }
        return root;
    }
    node* find_val(node *temp,int target)
    {
        if(temp==nullptr)return nullptr;
        if(temp->data==target)return temp;
        node *left_subtree=find_val(temp->left,target);
        
        
        return find_val(temp,target);
    }
};