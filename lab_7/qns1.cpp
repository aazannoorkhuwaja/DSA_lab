#include<iostream>
using namespace std;
class node{
    public:
    int id;
    string name;
    float price;
    node *next;
    node(int i,string n,float f):id(i),price(f),name(n){
        next=nullptr;
    }
};
class menu
{
    public:
    node *head;
    menu()
    {
        head=nullptr;
    }
    bool is_empty()
    {
        return (head==nullptr);
    }
    void insert(int in_id,string in_na,float in_pr)
    {
        node *n_node=new node(in_id,in_na,in_pr);
        if(is_empty())
        {
            head=n_node;
            return;
        }
        node*temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n_node;
    }

    node* find_that_order()
        {
            int search_id;
            cout <<"Enter the id of the item to order: "<<endl;
            cin>>search_id;

            node *temp=head;
            while(temp!=nullptr && temp->id!=search_id){
                temp=temp->next;
            }
            return temp;
    }
    

    void display_menu(){
    if (is_empty()){
        cout<<"menu is empty.\n";
        return;
    }
    node*temp=head;
    cout<<"---- cafeteria Menu ----\n";
    while(temp!=nullptr){
        cout<<"ID: "<<temp->id<<". \nName:"<<temp->name<<" \nRs. "<<temp->price<<endl;
        cout<<"--------------------------"<<endl;
        temp=temp->next;
    }

}

};

class order_node{
public:
    int id;
    string name;
    float price;
    order_node *next;

    order_node(int i,string n,float f):id(i),price(f),name(n){
        next=nullptr;
    }
};

class queue{
    public:
    order_node*front,*rear;
    queue()
    {
        front=rear=nullptr;
    }
    bool is_empty_queue()
    {
        return (front==nullptr);
    }
    void inseart(order_node* new_order)
    {
        if(is_empty_queue()){
            front=rear=new_order;
            return;
        }
        rear->next=new_order;
        rear=new_order;
    }

    void out()
    {
        if(is_empty_queue()){
        cout <<"No Orders to process!"<<endl;
        return;
        }
        order_node*temp=front;
        cout<<"processing order ID: "<<temp->id<<" -> "<<temp->name<<" recieve your Order!\n";
        front=front->next;
        delete temp;
        if(!front)
        {
            rear=nullptr;
        }
    }

    void show_order()
    {
        if(is_empty_queue())
        {
            cout<<"No order in waiting!"<<endl;
            return ;
        }
        order_node*temp=front;
        while(temp!=nullptr){
        cout<<"ID: "<<temp->id<<"\nName: "<<temp->name<<"\nRs: "<<temp->price<<endl;
        temp=temp->next;
        }   
    }

};


int main(){
    menu d;
    d.insert(1,"Chiken Biryani",250);
    d.insert(2,"Fries",120);
    d.insert(3,"Half Biryani",180.9);
    d.insert(4,"Nashta",150.4);
    d.insert(5,"Shake",300.50);
    d.insert(6,"Daal",100);
    d.insert(7,"Tea",80);
    d.insert(8,"Cold Drink",90);
    d.insert(9,"Lobya",130);
    d.insert(10,"Roti",20);

    queue q_cafetaria;
    int ch;
       while(true){
        cout<< "\n======Cafeteria-System======\n";
        cout<< "1.Display Menu\n"<<"2.place order\n"<<"3.show pending ordrs\n"<< "4.Process next Order\n"<< "5.Exit\n";
        cout<< "Pick your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            d.display_menu();
            break;
        case 2:{
            node* order=d.find_that_order();
            if(order!=nullptr)
            {
                order_node* n_order=new order_node(order->id,order->name,order->price);
                q_cafetaria.inseart(n_order);
                cout <<"Your Order placed with this id:" <<order->id<<endl;           
            }
            else {
                cout <<"Not a valid ID!\n Try again!"<<endl;
            }
        }
            break;
        case 3:
            q_cafetaria.show_order();
            break;
        case 4:
            q_cafetaria.out();
            break;
        case 5:
        cout <<"Leaving Cafeteria System ..."<<endl;
        return 0;
            break;
        default:
            cout<<"Not a valid choice so try again !"<<endl;
            break;
        }
    }

}
