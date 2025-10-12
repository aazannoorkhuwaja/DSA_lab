#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int val):data(val),next(NULL){}
};
class ll{
    public:
    node *head,*tail;
    int val, Target;

    ll():head(NULL),tail(NULL){

    }

    bool is_it_empty()
    {
        return (head==NULL);
    }

    void insert_at_end()
    {
        cout <<"Enter the value :"<<endl;
        cin>>val;
        node *new_node=new node(val);
        if(is_it_empty()){
            head=new_node;
            tail=new_node;
            return;
        }
        
        tail->next=new_node;
        tail=new_node;
        
    }

    void display_values()
    {
        if(is_it_empty())
        {
            cout <<"List is already empty first insert values."<<endl;
            return;
        }
        node *temp=head;
        while(temp!=NULL)
        {
            cout <<temp->data<<" ";
            temp=temp->next;
        }
    }

    void middle_node()
    {
        int count=0;
        int middle = 0;
         node *temp=head;
         node *t2=head;
         
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        middle = (count/2) +1;
        count = 1;
        while (t2!=NULL){
            if(count == middle) {
                cout<<t2->data<<endl;
                return;
            }
            count++;
            t2 = t2->next;
        }
    }


};

int main()
{
    ll list;
    char c;
   cout << "Insert values" << endl;
    while (true) {
        list.insert_at_end();
        cout << "(Enter 'q' to quit | if want to continue then press any key except q): ";
        cin >> c;
        cin.ignore(1000,'\n');
        if (c == 'q' || c == 'Q') {
            break;
        }
    }

    // list.odd_one_node();
    list.display_values();

    list.middle_node();

    return 0;
}