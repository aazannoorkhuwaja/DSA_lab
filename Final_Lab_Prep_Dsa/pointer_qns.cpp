#include<iostream>
using namespace std;    
int main()
{
    int students=3,subjects=4,**matrix;
    matrix=new int*[students];
    for(int i=0;i<students;i++)
    {
        matrix[i]=new int[subjects];
    }
    for(int i=0;i<students;i++)
    {
        for(int j=0;j<subjects;j++)
        {
        cout<<"Enter the Subjects of the student:"<<i+1<<endl;
        cin>>*(*(matrix+i)+j);
        }
    }
    for(int i=0;i<students;i++)
{
    for(int j=0;j<subjects;j++)
    {
    cout<<"The Data of Student "<<i+1<<" And Subject:"<<*(*(matrix+i)+j)<<endl;
    }
}
    // to swap data
    swap(*(matrix+0),*(matrix+2));

    //display
    for(int i=0;i<students;i++)
    {
        for(int j=0;j<subjects;j++)
        {
        cout<<"The Data of Student "<<i+1<<" And Subject:"<<*(*(matrix+i)+j)<<endl;
        }
    }
// deleting data 
    for(int i=0;i<students;i++)
    {
        delete[] *(matrix+i);
    }
    delete[] matrix;

    return 0;

}
