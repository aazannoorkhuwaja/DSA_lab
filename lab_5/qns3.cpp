#include <cstddef>
#include <iostream>
using namespace std;
class node{
    public:
    char ch;
    node *next,*prev;
    node(char d):ch(d),next(NULL),prev(NULL){}
};

class d_l_l{
    public:
    node *head;
    d_l_l()
    {
        head=NULL;
    }

    void push_at_end(char v)
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
            cout<<tp->ch<<"->";
            tp=tp->next;
        }

    }

    void cheak_palindrome()
{
    bool palidrome=true;

       node *tp=head;
        while(tp->next!=head){
            tp=tp->next;
        }
        node *start=head;
        node *tail=tp;
        while(start->next!=head && tail->prev!=tp)
        {
            if(tail->ch!=start->ch)
            {
                palidrome=false;
            }
            start=start->next;
            tail=tail->prev;
        }
        if(palidrome)
        {
            cout<<"The given Word is palindrome in List!"<<endl;

        }
        else{
                 cout<<"The given is not a palindrome in List!"<<endl;
        }


}

    
};

       

    
int main()
{
     d_l_l d1;
    //  d1.push_at_end('M');
    //  d1.push_at_end('A');
    //  d1.push_at_end('D');
    //  d1.push_at_end('A');
    //  d1.push_at_end('M');

     d1.push_at_end('C');
     d1.push_at_end('A');
     d1.push_at_end('T');
     d1.cheak_palindrome();

}
