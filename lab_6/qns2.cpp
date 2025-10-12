#include<iostream>
using namespace std;
class node
{
    public:
    char data;
    node *next,*previous;
    node(char d){
        data=d;
        next=previous=NULL;
    }
};

class word{
public:
node *head,* tail;
    word()
    {
    head=tail=NULL;
    }
    void insert(char ins)
    {
        node *n_node=new node(ins);
        if(head==NULL)
        {
            head=tail=n_node;
            return ;
        }
        tail->next=n_node;
        n_node->previous=tail;
        tail=n_node;
    }
    void cipher_the_msg()
    {
        int shift;
        cout<<"\nEnter the position with which you want to shift:"<<endl;
        cin>>shift;
        node *temp=head;
        shift=shift%26;
        while(temp!=NULL)
        {
            //for capital letters
            if(temp->data >= 'A' && temp->data <='Z')
            {   
                if(shift>='Z' ){
                    shift =('A'-1) + (shift%'Z');
                     temp->data=temp->data+shift;
                }
                else{
                      temp->data=temp->data+shift;
                      if(temp->data>'Z'){
                        temp->data=('A'-1)+(temp->data%'Z');
                      }
                }

            }
            

            //for small letters
            if(temp->data >='a' && temp->data<='z'){
                if(shift>'z'){
                    shift=('a'-1)+(shift%'z');
                     temp->data=temp->data+shift;
                }
                else{
                      temp->data=temp->data+shift;
                      if(temp->data>'z'){
                        temp->data=('a'-1)+(temp->data%'z');
                      }
                }
            }
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }

        //now for decode
        char c;
        cout <<"\nDo you want to decode: y/n "<<endl;
        cin >> c;
        temp=head;
        switch(c){
        case 'y':
        {
        while(temp!=NULL)
        {
            //for capital letters
            if(temp->data >= 'A' && temp->data <='Z')
            {   
                if(shift>='Z'){
                    shift =('A'-1) + (shift%'Z');
                     temp->data=temp->data-shift;
                }
                else{
                      temp->data=temp->data-shift;
                      if(temp->data<'A'){
                        temp->data=temp->data+ 26;
                      }
                      if(temp->data>'Z'){
                        temp->data=('A'-1)+(temp->data%'Z');
                      }
                }

            }
            

            //for small letters
            if(temp->data >='a' && temp->data<='z'){
                if(shift>'z'){
                    shift=('a'-1)+(shift%'z');
                     temp->data=temp->data-shift;
                }
                else{
                      temp->data=temp->data-shift;
                       if(temp->data<'a'){
                        temp->data=temp->data+ 26;
                       }
                      if(temp->data>'z'){
                        temp->data=('a'-1)+(temp->data%'z');
                      }
                }
            }
            temp=temp->next;
        
        }
        temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
            break;
    }
        
        case 'n':
        {
            break;
        }
        default:
        {
            cout <<"Not a valid input!"<<endl;
            break;
        }
    }
        

    }

   
    

    void display()
    {
         node *temp=head;
        while(temp!=NULL){
           cout<<temp->data;
            temp=temp->next;
        } 
    }

};

int main()
{
    word w;
    w.insert('A');
      w.insert('a');
      w.insert('z');
       w.insert('Z');
        w.insert('n');
        w.display();
        w.cipher_the_msg();
        
}