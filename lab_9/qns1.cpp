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
node* find_maximum(node* r)
{
        if(r->right!=NULL) r=find_maximum(r->right);
        return r;
}
node* find_minimum(node* r)
{
        if(r->left!=NULL) r=find_minimum(r->left);
        return r;
}
node* insert(node* r,int val)
    {
        if(r==NULL)return new node(val);
        else if(val < r->data)
        {
            r->left = insert(r->left,val);
        }
        else if(val > r->data)
        {
            r->right = insert(r->right,val);
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

void max_show()
{
    node*max=find_maximum(root);
    cout<<" The MAX value is:"<<max->data<<endl;
}
void min_show()
{
    node*min=find_minimum(root);
    cout<<" The MIN value is:"<<min->data<<endl;
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
    tree.max_show();
    tree.min_show();
}