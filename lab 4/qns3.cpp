#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val):data(val),next(NULL){}
};
class sslist{
    public:
    node *head1;
    sslist():head1(NULL){};
    bool is_empty()
    {
        return(head1==NULL);
    }
    void insert_in_first(){
        int n;
        cout<<"Enter values for list:"<<endl;
        cin>>n;
        cin.ignore();
        node *n_node=new node(n);
        if(is_empty())
        {
            head1=n_node;
            head1->next=head1;
            return;
        }
        node *tp1=head1;
        while(tp1->next!=head1){
           
            tp1=tp1->next;
        }
        tp1->next=n_node;
        n_node->next=head1;
    }
    void del_dup()
   
    }
     void display() 
    {
        node *temp = head1;
        do {
        cout << temp->data << " , ";
        temp = temp->next;

        }
        while (temp != head1);
    }

};
int main() {
    sslist l;
    int n;
    cout<<"how many values you want to put in list:";
    cin>>n;
    for (int i=0;i<n;i++) {
        l.insert_in_first();
    }
    cout << "\nList (before):";
    l.display();
    l.del_dup();
    cout << "\nList (after):";
    l.display();
    return 0;
}
