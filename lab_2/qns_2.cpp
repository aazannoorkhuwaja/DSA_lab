#include<iostream>
using namespace std;
class dup_remove{
    private:
    int *aa,siz=0,uni_c;
    public:
    dup_remove(int s):siz(s),uni_c(0)
    {
    aa = new int[siz];
    cout<<"Enter The Values :"<<endl;
    for(int i=0;i<siz;i++)
    {
        cin>>*(aa+i);
    }

     for(int i=0;i<siz;i++)
    {
        cout<<*(aa+i)<<" ,";
    }
    cout<<endl;
    for(int i=0;i<siz;i++)
    {
        for(int j=i+1;j<siz;j++)
        {
            if(*(aa+i)==*(aa+j))
            {
                *(aa+j)=-1;
            }
        }
    }
       for(int i=0;i<siz;i++)
    {
        if(*(aa+i)!=-1)
        {
            uni_c++;
        }
    }
      cout<<endl;

    }
    void unique()
    {

        int *a=new int[uni_c];
        int j=0;
        for (int i=0;i<siz;i++)
        {
            if(*(aa+i)!=-1)
            {
                *(a+j)=*(aa+i);
                j++;
            }
        }
        for (int i=0;i<uni_c;i++)
        {
           cout <<*(a+i)<<" ,";
        }
        delete[] aa;
        aa=a;
    }

    ~dup_remove()
    {
        delete[] aa;
        aa=nullptr;
    }
    
};


int main()
{
    int size;
    cout <<"Enter The size of array :"<<endl;
    cin>>size;
    dup_remove d(size);
    d.unique();
    

}