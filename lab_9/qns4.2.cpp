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
                if(root==NULL)return new node(d);
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
                //here it goes in left tree nodes and if find target return it to left subtree
                //if there null will return also to leftsubtree then we cheak if its not null then return other wise wil cheak 
                //right subtree.
                node *left_subtree=find_val(temp->left,target);
                if(left_subtree!=NULL)
                {
                    return left_subtree;
                }
                //here we are going in right sub tree there if we find null will return also that other wise will return that target node.
                return find_val(temp->right,target);
            }
            public:
            node*root;
            Bst():root(nullptr){}
        void create_nodes()
        {
            int t;
            cout <<"Enter the value for Tree insertion:"<<endl;
            cin>>t;
            root=insert(root,t);
        }
        void insert_after_val()
        {
            int t;
            cout <<"Enter the target value after which you want to insert:"<<endl;
            cin>>t;
            node *target=find_val(root,t);
            if(target==nullptr)
            {
                cout <<"Target not found!"<<endl;
                return;
            }
            int p;
            cout <<"Enter the value which you want to insert:"<<endl;
            cin>>p;
            //this is the case where order does not matter but just insert after val
            if(target->left==nullptr)
            {
                target->left=new node(p);
            }
            else if(target->right==nullptr)
            {
                target->right=new node(p);
            }
            //here missing case is when we have the right and left node alredy there then how we insert 
            
        }
        };

