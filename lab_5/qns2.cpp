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
            head->next=head;
            head->prev=head;
            return;

        }
        node *tp=head;
        while(tp->next!=head){
            tp=tp->next;
        }
        tp->next=n_node;
        n_node->prev=tp;
        head->prev=n_node;
        n_node->next=head;
    }
    void triverse()
    {
         node *tp=head;
        while(tp->next!=head){
            cout<<tp->data<<"->";
            tp=tp->next;
        }

    }

    
};
void union_of_two_lists(d_l_l &d1_copy,d_l_l &d2_copy)
    {
        d_l_l unio_list;
        node *tp1=d1_copy.head;
       
        //to copy values in union at first 
        if(d1_copy.head!=NULL){
            do{
            unio_list.push_at_end(tp1->data);
                tp1=tp1->next;
            }
            while(tp1!=d1_copy.head);
        }

        //cheak if second list values already present in list then ignore that
        node *current = unio_list.head;
        if(d2_copy.head!=NULL){
        node *list2=d2_copy.head;
        do{
            bool number_not_present=false;
            current=unio_list.head;
            if(current!=NULL){
            do{
                if(current->data==list2->data){
                    number_not_present=true;
                    break;
                }
                else{
                    number_not_present=false;
                }
                current=current->next;
            }
            while(current!=unio_list.head);
            }

            if(!number_not_present){
                unio_list.push_at_end(list2->data);
            }

            list2=list2->next;
        }
        while(list2!=d2_copy.head);


        }
        

        
            //triverse data after union 
            cout<<"The List after union is :";
            current = unio_list.head;
            do{
             cout<<current->data<<"=>";
            current=current->next;
            }
        while(current!=unio_list.head);

       

    }
int main()
{
     d_l_l d1,d2;
        d1.push_at_end(1);
        d1.push_at_end(2);
        d1.push_at_end(3);
        d1.push_at_end(7);
        d2.push_at_end(3);
        d2.push_at_end(4);
        d2.push_at_end(5);
        d2.push_at_end(6);
        d2.push_at_end(7);
        d2.push_at_end(1);

        union_of_two_lists(d1,d2);

}