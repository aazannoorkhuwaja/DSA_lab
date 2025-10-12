#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int v):data(v),next(NULL){}
};
class stack{
public:
node *top;
stack():top(NULL){
}

bool is_empty()
{
 return(top==NULL);   
}
void push(int v)
{
    node* n_node =new node(v);
    n_node->next=top; // here first  node next is null and top points to first data
    top=n_node;
}
void pop(){
if(is_empty()){
    cout <<"Is already empty!!"<<endl;
    return;
}
  node*temp=top;
  top=top->next;
  delete temp;
}
int peek(){
    if(is_empty()){
    cout <<"Is empty!!"<<endl;
    return -1;
    }

    return top->data;
}
};
int main()
{
    stack s;
    s.push(1);
    cout<<s.peek();
    s.push(2);
    cout<<s.peek();
    s.push(3);
    cout<<s.peek();
    s.push(4);
    cout<<s.peek();
    s.pop();
    cout <<"\nAfter delete!\n";
    cout<<s.peek();
}