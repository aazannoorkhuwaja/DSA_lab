#include<iostream>
using namespace std;
class student_record{
    string stu_id,stu_name;
    float stu_gpa;
    public:
    student_record():stu_id(""),stu_name(""),stu_gpa(0){

    }

    void set_stu_id(){
     string id;
     cout<<"Enter student ID:"<<endl;
     getline(cin,id);
     stu_id=id;   
    }

    void set_stu_name(){
     string name;
     cout<<"Enter student name:"<<endl;
     getline(cin,name);
     stu_name=name;   
    }

    void set_stu_gpa(){
     float gpa;
     cout<<"Enter student GPA:"<<endl;
     cin>>gpa;
     cin.ignore();
     stu_gpa=gpa;   
    }

    string get_id()
    {
        return stu_id;
    }

    string get_name()
    {
        return stu_name;
    }

    float get_gpa(){
        return stu_gpa;
    }
};

class node {
    public:
    student_record data;
    node *next;
    node():next(NULL){}
};

class stu_list{
public:
node *head,*tail;
stu_list():head(NULL),tail(NULL){}

bool is_list_empty()
{
    return (head==NULL);
}

void add_student(){
    node *n_node=new node;
if(is_list_empty()){

    n_node->data.set_stu_id();
    n_node->data.set_stu_name();
    n_node->data.set_stu_gpa();
    head=n_node;
    tail=n_node;
    tail->next=head;
    return;
}
    n_node->data.set_stu_id();
    n_node->data.set_stu_name();
    n_node->data.set_stu_gpa();
    tail->next=n_node;  
    tail = n_node;
    tail->next=head;
}

void dlt_student(){
     if(is_list_empty())
    {
        cout <<"List is empty there is no student!"<<endl;
        return ;
    }
    cout<<"Enter the id of the student you want to delete: "<<endl;
    string id_d;
    getline(cin,id_d);
    if(head->data.get_id()==id_d && head->next==head)
    {
        delete head;
        head=NULL;
        cout<<id_d<<" Student Removed!"<<endl;
        return;
    }
    node *temp=head;
    while(temp->next!=head )
    {
        temp=temp->next;
    }
    tail=temp;
    node *temp2=head;
    head=head->next;
    temp->next=head;
    delete temp2;
    node *previous=NULL,*current=head;
    do {
        previous=current;
        current=current->next;
        if(current->data.get_id() == id_d)
        {
            previous->next=current->next;
            if(current==head){
            tail=previous;
            }
            delete current;
            return;
        }
    }
    while(current!=head);
}

void search_students(){
    if(is_list_empty())
    {
        cout <<"List is empty there is no student!"<<endl;
        return ;
    }
    string search_id;
    cout<<"Enter student id to searh: "<<endl;
    getline(cin,search_id);
    node *tp=head;
    do {
        if(tp->data.get_id()==search_id){
            cout<<" student milgaya: \n ID:"<<tp->data.get_id()<<", Name:"<<tp->data.get_name()<<", GPA: "<<tp->data.get_gpa()<<endl;
            return;
        }
        tp=tp->next;
    }
    while(tp!=head);
}

void display_students(){
     if(is_list_empty())
    {
        cout <<"List is empty there is no student!"<<endl;
        return ;
    }
 node *tp=head;
    do {
            cout<<"we found student : \n ID:"<<tp->data.get_id()<<", Name:"<<tp->data.get_name()<<", GPA: "<<tp->data.get_gpa()<<endl;
            tp=tp->next;
        }
    while(tp != head);

}

void cal_avg_gpa(){
    if(is_list_empty())
    {
        cout <<"List is empty there is no student!"<<endl;
        return ;
    }
node *tp=head;
int count=0;
float avg_g=0;
    do {
            avg_g=avg_g+tp->data.get_gpa();
            count++;
            tp=tp->next;
    } 
    while(tp != head);
    avg_g=avg_g/count;
    cout<<"Average GPA :"<<avg_g<<endl;
}

};
int main()
{
    stu_list s;
    int chose;
    cout<<"Welcome to the Student Registration System!"<<endl;
    while(true)
    {
        cout<<"\n1. Add a student\n2. Remove a student\n3. Search for a student\n4. Display all students\n5. Calculate average GPA\n6. Exit"<<endl;
        cin>>chose;
        cin.ignore();
        switch(chose)
        {
            case 1:
                s.add_student();
                break;

            case 2:
                s.dlt_student();
                break;

            case 3:
                s.search_students();
                break;

            case 4:
                s.display_students();
                break;

            case 5:
                s.cal_avg_gpa();
                break;
            
            case 6:
                exit(0);
                break;

            default:
                cout<<"Your input is not valid !"<<endl;
                break;
        }
    }

}
