//this is closed hashing
//limited space
//Cannot hold more elements than the table size.
#include<iostream>
using namespace std;
class linear_hashing{
public:
int *table;
int size;
int current;

linear_hashing(int s):size(s),current(0){
    table=new int[size];
    for(int i=0;i<size;i++)
    {
        table[i]=-1;
    }
}
int hashing_function(int k)
{
    return (k % size);
}

void insert(int key)
{
    int ind=hashing_function(key);
    if(current==size){
        cout<<"The hashing list is full";return;
    }
    //to handle collision (Loop while the spot is NOT Empty AND NOT Deleted)
    while(table[ind]!=-1 && table[ind]!=-2)
    {
        ind=(ind+1)%size;
    }
    table[ind]=key;
    current++;
    cout<<"Value inserted at index"<<ind<<endl;
}
void search(int key){
    int ind=hashing_function(key);
    //lets save start so when it come back to start we stop loop
    int start=ind;
    while(table[ind]!=-1)
    {
        if(table[ind]==key){
            cout << "Found " << key << " at index " << ind << endl;
            return;
        }
        //cheak next
        ind=(ind+1)%size;
        if(ind==start){
            break;
        };
    }
    cout <<"key not found !"<<endl;
}
void display()
{
    for (int i=0;i<size;i++){
        if(table[i]!=-1)
        {
            cout <<"The key at index:" <<i<<" is:"<<table[i]<<endl;
        }
        else if(table[i] == -2) // FIX: Display Tombstone clearly means that -2
            cout<<i<<" is [DELETED]"<<endl;
        else{
            cout<<i<<" is empty"<<endl;
        }
    }
}
void deletion(int key)
{
    //for deletion we will use -2 not -1 because -1 shows empty in this way we may lose value after deleted bcz loop stops before reaching next value on the deleted bcz if we put -1
     int ind=hashing_function(key);
    //lets save start so when it come back to start we stop loop
    int start=ind;
    while(table[ind]!=-1)
    {
        if(table[ind]==key)
        {
            //assign -2 so will not lose its next value 
            table[ind]=-2;
            cout<<"value deleted at "<<ind<<" Successfullt"<<endl;
            return;
        }
            ind=(ind+1)%size;

        if(ind==start){
            break;
        }
            
    }
    cout<<"The value to delete is not found!"<<endl;
}

};
int main()
{
    int n;
    cout<<"Enter the size of hashtable:"<<endl;
    cin>>n;
    linear_hashing ht(n);
    ht.insert(10); // goes to index 0
    ht.insert(20); // Collision! Should go to index 1
    ht.insert(14); // goes to index 4
    
    ht.display();
    ht.search(20);
    return 0;
}
