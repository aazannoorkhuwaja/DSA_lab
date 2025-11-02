#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;
    node(int d):data(d){
        left=right=NULL;
    }
};
class BST{
private:
node* insert(node* r,int val)
{
    if(r==NULL)return new node(val);
    else if(val<r->data)
    {
        r->left=insert(r->left,val);
    }
    else if(val>r->data)
    {
        r->right=insert(r->right,val);
    }
    return r;
}
void inorder(node *t)
{
    if(t==NULL)return;
    inorder(t->left);
    cout<<t->data<<",";
    inorder(t->right);
}
node* insert_after_val(node* r, int val)
{
    if(r==NULL)return new node(val);
    if(val<r->data)r->left=insert_after_val(r->left,val);
    else if(val>r->data)r->right=insert_after_val(r->right,val);
    return r;
}
node* insert_after_target(node* r,int target,int new_val)
{
    if(r==NULL)return NULL;
    if(r->data==target)
    {
        if(r->right==NULL)r->right=new node(new_val);
        else r->right=insert_after_val(r->right,new_val);
        return r;
    }
    if(target<r->data)r->left=insert_after_target(r->left,target,new_val);
    else r->right=insert_after_target(r->right,target,new_val);
    return r;
}
public:
    node *root;
    BST()
    {
        root=NULL;
    }
void create_insert_tree()
{
    int d;
cout<<" Enter the value:"<<endl;
cin>>d;
   root=insert(root,d);
}
void inorder_traversal(){
    inorder(root);
}
void insert_after()
{
    int target,new_val;
    cout<<"Enter target and new value:"<<endl;
    cin>>target>>new_val;
    root=insert_after_target(root,target,new_val);
}
};
int main()
{
    BST tree;
    tree.create_insert_tree();
     tree.create_insert_tree();
      tree.create_insert_tree();
       tree.create_insert_tree();
        tree.create_insert_tree();
         tree.create_insert_tree();
          tree.create_insert_tree();
    tree.inorder_traversal();
    cout<<endl;
    tree.insert_after();
    tree.inorder_traversal();
}
