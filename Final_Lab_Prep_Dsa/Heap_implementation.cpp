#include<iostream>
using namespace std;
class order{
public:
int price,priority,quantity;
string item_name,cust_name;
order(){}





};

class heap{
    order arr[10];
    int current;
    public:
    heap(){
        current=0;
    }
    void heapify_up(int &i)
    {
        while(i!=0 && arr[i].priority>arr[parent(i)].priority)
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void heapify_down(int &i)
    {
        while(true)
        {
            int largest=i;
            int left_child=left(i);
            int right_child=right(i);
            if(left_child<current && arr[left_child].priority>arr[right_child].priority)
            {
                largest=left_child;
            }
            if(right_child>current && arr[right_child].priority>arr[left_child].priority)
            {
                largest=right_child;
            }
            if(largest==i){
                cout<<"means root is largest"<<endl;
                return;
            }
            swap(arr[i],arr[largest]);
            i=largest;
        }

    }

    void insert()
    {
        //insert at end
        if(current>=10)return;
        cout<<"Enter item name:"<<endl;
        cin>>arr[current].item_name;
        cout<<"Enter Price: "<<endl;
        cin>>arr[current].price;
        cout<<"Enter the quantity "<<endl;
        cin>>arr[current].quantity;
        cout<<"Enter Customer Name:"<<endl;
        cin>>arr[current].cust_name;
        cout<<"Enter Priority: "<<endl;
        cin>>arr[current].priority;

        int i=current;
        current++;
        heapify_up(i);
    }
    int parent(int i){return ((i-1)/2);}
    int left(int i){return((2*i)+1);}
    int right(int i){return((2*i)+2);}
    
    void deletion()
    {
        if(current==0)return;
        order dlt_num=arr[1];
        arr[1]=arr[current-1];
        --current;

        int i=1;
        heapify_down(i);
    }
    void display()
    {
        for(int i=1;i<current;i++)
        {
            cout<<i<<". Data:"<<"Item name:"<<arr[i].item_name<<", Price:"<<arr[i].price<<", Quanity:"<<arr[i].quantity<<", Customer Name:"<<arr[i].cust_name<<", Priority:"<<arr[i].priority<<endl;
        }
    }



};

int main()
{
    heap h;
    h.insert();
    h.insert();
    h.insert();
    h.insert();
    h.insert();
    cout<<"Insertions:\n";
    h.display();
    h.deletion();
    cout<<"After Deletion\n";
    h.display();
}