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
    // int node_c_1=0,node_c_2=0;
    node *head1,*head2;
    sslist():head1(NULL),head2(NULL){};
    bool is_first_head_empty()
    {
        return(head1==NULL);
    }
    bool is_second_head_empty()
    {
        return(head2==NULL);
    }
    void insert_in_first(){
        int n;
        cout<<"Enter values for first list:"<<endl;
        cin>>n;
        cin.ignore();
        node *n_node=new node(n);
        if(is_first_head_empty())
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
        //  node_c_1++;
    }

        void display_l1() 
    {
        node *temp = head1;
        do {
        cout << temp->data << " , ";
        temp = temp->next;

        }
        while (temp != head1);
    }

      void insert_in_second(){
        int n;
        cout<<"\nEnter values for second list:"<<endl;
        cin>>n;
        cin.ignore();
        node *n_node=new node(n);
        if(is_second_head_empty())
        {
            head2=n_node;
            head2->next=head2;
            return;
        }
        node *tp2=head2;
        while(tp2->next!=head2){
          
            tp2=tp2->next;
        }
        tp2->next=n_node;
        n_node->next=head2;
        //   node_c_2++;
    }
          void display_l2() 
    {
        node* temp = head2;
        do {
        cout << temp->data << " -> ";
        temp = temp->next;

        }
        while (temp != head2);
    }
    void c_values()
    {   
        int count_c=0;
        node *temp1=head1;
        // if(node_c_1>node_c_2){
        //     for(int i=0;i<node_c_1;i++)
        //     {
        //         int st1=temp1->data;
        //        for(int j=0;j<node_c_2;j++){
        //         if(st1==temp2->data)
        //         {
        //             count_c++;

        //         }
        //          temp2=temp2->next;
        //     }
        //         temp1=temp1->next;
               
        //     }
        // }
        // else{
        //     for(int i=0;i<node_c_2;i++)
        //     {
        //         int st1=temp2->data;
        //        for(int j=0;j<node_c_1;j++){
        //         if(st1==temp1->data)
        //         {
        //             count_c++;

        //         }
        //          temp1=temp1->next;
        //     }
        //         temp2=temp2->next;
               
        //     }
        // }
       
        cout<<"\nTotal common values are ="<<count_c<<endl;
        
    }


};
int main()
{
    sslist l;
    l.insert_in_first();
    l.insert_in_first();
    l.insert_in_first();
    l.insert_in_first();
    l.insert_in_first();
    l.display_l1();
    l.insert_in_second();
    l.insert_in_second();
    l.insert_in_second();
    l.insert_in_second();
    l.insert_in_second();
    l.display_l2();
    l.c_values();


}

