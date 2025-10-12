#include <cmath>
#include <cstddef>
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next,*prev;
    node(int d):data(d),next(NULL),prev(NULL){}
};

class d_l_l{
    public:
    node *head;
    d_l_l()
    {
        head=NULL;
    }

    void push_at_end(int v)
    {
        node *n_node=new node(v);
        if(head==NULL){
            head=n_node;
            return;

        }
        node *tp=head;
        while(tp->next!=NULL){
            tp=tp->next;
        }
        tp->next=n_node;
        n_node->prev=tp;;
    }
    void triverse()
    {
         node *tp=head;
        while(tp->next!=NULL){
            cout<<tp->data<<"->";
            tp=tp->next;
        }

    }

    void count_even(){
        int c_e=0,count_nodes=0;
        node *tp=head;
        while(tp!=NULL){
            count_nodes++;
            tp=tp->next;
        }
        node *tp1=head;
        for(int i=0;i<count_nodes;i++)
        {
            node *tp2=head;
            for(int j=i+1;j<count_nodes;j++)
            {
                tp2=tp2->next;
                if((tp1->data+tp2->data)%2==0)
                {
                    c_e++;
                }
                
            }
            tp1=tp1->next;
        }
        cout<<"\nThe total number of even combinations of nodes are :"<<c_e<<endl;
    }
};
int main()
{
    d_l_l d;
    d.push_at_end(2);
    d.push_at_end(3);
    d.push_at_end(4);
    d.push_at_end(5);
    d.push_at_end(4);
    d.triverse();
    d.count_even();
}
