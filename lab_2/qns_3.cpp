#include<iostream>
using namespace std;
class matrix_diag
{
private:
    int siz=3,**a=new int*[siz],add_main_d=0,sec_diagonal=0;
public:
    matrix_diag(){
    for(int i=0;i<siz;i++)
    {
        *(a+i)=new int[siz];
    }
    }

    void input_matrices(){
    cout <<"Enter values in Matrix:"<<endl;
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++)
        {
            cin>>*(*(a+i)+j);
        }
    }

    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++)
        {
            cout <<*(*(a+i)+j)<<" ,";
        }
    }
    }
    void sum_of_diagonals(){
    for(int i=0;i<siz;i++)
    {
        add_main_d+=*(*(a+i)+i);
    }
    for(int i=0;i<siz;i++)
    {
        sec_diagonal+=*(*(a+i)+siz-(i+1));

    }
    cout <<"\nThe Main diagonal sum is :"<<add_main_d<<" \nThe secondaey diagonal sum is:"<<sec_diagonal<<endl;
    }

    ~matrix_diag(){
    for(int i=0;i<siz;i++)
    {
        delete[] *(a+i);
    }
    delete[] a;
    }
};
int main()
{
    matrix_diag m;
    m.input_matrices();
    m.sum_of_diagonals();
}


