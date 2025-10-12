#include<iostream>
using namespace std;
class Repeated
{
private:
    int s;
    int *arr,value,prev_val=0,count=0;
public:
    void rep_array()
    {
        cout <<"Enter The size of array :"<<endl;
        cin>>s;
        arr=new int[s];
            for(int i=0;i<s;i++)
            {
                cin>>*(arr+i);
            }

            for(int i=0;i<s;i++)
            {
                cout <<*(arr+i)<<" ,";
            }

        for(int i=0;i<s;i++)
        {
            int prev_count=0;

            
            for(int j=0;j<s;j++)
            {
                if(*(arr+i)==*(arr+j))
                {

                    prev_count++;
                    
                }
            }
            if(count<=prev_count)
            
            {
                value=*(arr+i);
                if(value>=prev_val){
                    prev_val=value;
                }

                count=prev_count;
                
                
            
            }
        }
        cout<<"\nThe Most Repeated Value is "<<prev_val<<" and it appears "<<count <<" Times "<<endl;

    }

    ~Repeated()
    {
            delete[] arr;
            arr=nullptr;
    }

};
int main()
    {
        Repeated r;
        r.rep_array();
    }