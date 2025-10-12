#include<iostream>
#include<string>
using namespace std;
class queue_circular{
    public:
    string *arr;
    int cap, siz_cap;
    int f,r;
    string name ;
    queue_circular()
    {
        cap=5;
        arr=new string[cap];
        f=r=-1;
        siz_cap=0;
    }
    bool is_full(){
    return (((r+1)%cap == f));
}
    bool is_empty()
    {
        return (f==-1);
    }
    void add_patient(string n)
    {
        if(is_full())
        {
            cout <<"waiting is already FUll! \n Can't add more!"<<endl;
            return;
        }
        if(is_empty())
        {
            f=r=0;
        }
        else {
            r=(r+1)%cap;
        }
        arr[r]=n;
        siz_cap++;
        cout <<"Patient: "<<n<<" Appointment Given!"<<endl;
    }
    void send_to_doctor()
    {
        if(is_empty())
        {
            cout <<"No patients in waiting !"<<endl;
        }
        else {
            cout<<"sending "<<arr[f]<<" to Docter \nSend Next Patient!"<<endl;
        }
        if(f==r)
        {
            f=r=-1;
        }
        else{
            f=(f+1)%cap;
        }
        siz_cap--;
    }

    void next_patient()
    {
        if(is_empty())
        {
            cout <<"No patient Waiting !"<<endl;
        }
        else{
            cout<<"Next Patient is :"<<arr[f]<<endl;
        }
    }

    void display_patients()
    {
        if(is_empty()){
            cout<<"No patients currently waiting"<<endl;;
            return;
        }
        cout <<"Total Waiting patients are:"<<endl;
        int i=f;
        while(true)
        {
            cout <<"Patient: "<<arr[i]<<endl;
            if(i==r)break;
            i=(i+1)%cap;
        }
    }

};
int main()
{
    queue_circular q;
    int c;
    string name;
    while(true)
    {
        cout<<"***Doctor System*** \n1.Add patient\n"<<"2.Send next patient to doctor\n"<<"3.See who is next\n4.Exit"<<endl;
        cin>>c;
        switch (c)
        {
        case 1:{
        cout <<"Enter the name of patient:"<<endl;
        cin.ignore();
        getline(cin,name);
        q.add_patient(name);
    }
        break;
        case 2:
        q.send_to_doctor();
        break;
        case 3:
        q.next_patient();
        break;
        case 4:
        return 0;
        break;
        default:
        cout <<"Not a valid Choice!\n try again!"<<endl;
            break;
        }
    }
}