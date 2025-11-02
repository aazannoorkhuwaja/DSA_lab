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
class BST {
private:

node *root;
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
    if(t==NULL) return ;
    inorder(t->left);
    cout<<t->data<<" ";
    inorder(t->right);
}
int count_nodes(node *k)
{
    if(k==NULL)return 0;
    return 1+ count_nodes(k->right)+count_nodes(k->left);
}
node *right_most_left_subtree(node* n)
{
    while(n->right!=NULL){
    n=n->left;
    }
    return n;
}
node *left_most_right_subtree(node* n)
{
    while(n->left!=NULL){
    n=n->right;
    }
    return n;
}
void get_pre_succ(node *root,int target)
{
    node *pre,*succ;
    node* current=root;
    pre=succ=NULL;
    while(current!=NULL)
    {
        if(target<current->data)
        {
            succ=current;
            current=current->left;
        }
        else if(target>current->data)
        {
            pre=current;
            current=current->right;
        }
        else{
            if(current->left!=NULL)
            {
                pre=right_most_left_subtree(current->left);
            }
            if(current->right!=NULL)
            {
                succ=left_most_right_subtree(current->right);
            }
            break;
        }

    }

    if (pre != NULL)
        cout<<"The Predecessor is:"<<pre->data<<endl;
    else
        cout << "No Predecessor exist"<<endl;
    if (succ != NULL)
        cout << "The Successor is:"<<succ->data <<endl;
    else
        cout<< "No Successor exist" << endl;

}

public:
   
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


void cheak_nodes_both_sides()
{
    int right_count=count_nodes(root->right);
    cout<<right_count<<endl;
    int left_count=count_nodes(root->left);
     cout<<left_count<<endl;
    if(right_count==left_count)
    {
        cout<<" Both side childrens are equal!"<<endl;
    }
    else{
        cout<<" Childrens are not equal"<<endl;
    }
}

void pre_and_succ_target()
{
    int n;
    cout<<"Enter the target :"<<endl;
    cin>>n;
    get_pre_succ(root,n);
}



};
int main()
{
    BST tree;
    int choose;
    while(true)
    {
        cout<<endl;
         cout <<"enter the value to choose : \n1.Insert In Tree\n2.Inorder Traversal\n3.Cheak Equal Childs or not\n4.Find Successor and Predecessor\n5. exit...."<<endl;
         cin>>choose;
        switch(choose)
        {
            case 1:
                tree.create_insert_tree();
                break;
            case 2:
                tree.inorder_traversal();
                break;
            case 3:
                tree.cheak_nodes_both_sides();
                break;
            case 4:
                tree.pre_and_succ_target();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Not a valid input!"<<endl;
                break;
        }
    }
}
