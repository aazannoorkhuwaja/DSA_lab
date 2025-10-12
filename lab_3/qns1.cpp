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

    void insert_value_append()
    {
        cout <<"Enter Target value after whaich you want to input:"<<endl;
        cin>>Target;
        node *temp=head;
        int count=0;
        while(temp!=NULL)
        {
            if(Target==temp->data)
            {
                count++;
                if(count==3)
                {
                    cout<<"Target found 3 times\n enter the value for new node:"<<endl;
                    cin>>val;
                    node *new_node=new node(val);
                    new_node->next=temp->next;
                    temp->next=new_node;
                    
                    if(temp==tail)
                    {
                        tail=new_node;
                    }
                    return;

                }

            }
            temp=temp->next;

            
            
        }
        cout<<"Your target value is not appeard 3 times"<<endl;

        

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

    list.insert_value_append();
    list.display_values();

    return 0;
}