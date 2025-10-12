#include<iostream>
#include<string>
using namespace std;
class stack{
public:
char *arr;
int capacity;
int top;
stack(int cap)
{
    arr=new char[cap];
    capacity=cap;
    top=-1;

}
bool is_empty(){
    return (top==-1);
}
bool is_full()
{
    return (top==capacity-1);
}
void push(int v)
{
    if(is_full())
    {
        cout <<"Is already full cant insert more in stack!"<<endl;
        return ;
    }
    arr[++top]=v;
}
void pop()
{
    if(is_empty())
{
    cout <<"stack is already empty cant delete further!"<<endl;
    return ;
}
    --top;
}

char peek()
{
    if(is_empty())
{
    cout<<"Stack is empty!\n";
    return '\0';
}
    return arr[top];
}

bool chaek_palindrome(stack &t)
{
    //for single element
    if(t.top==0)
    {
    return true;
    }   

    //for even
    if (t.capacity%2==0){
    stack d(t.capacity/2);
    for(int i=0;i<t.capacity/2;i++)
    {
    d.push(t.peek());
    t.pop();
    }
    while(d.peek()==t.peek())
    {
        d.pop();
        t.pop();
        if(t.is_empty() || d.is_empty()){ 
        return true;
        }
    }

}
    //for odd
    else{
    stack d(t.capacity/2);
    for(int i=0;i<t.capacity/2;i++)
    {
    d.push(t.peek());
    t.pop();
    }
    t.pop();



    while(d.peek()==t.peek())
    {
        d.pop();
        t.pop();
        if(t.is_empty() || d.is_empty()){ 
        return true;
        }
    }
   
}

  return false;
}

};
int main() {
    string wor;
    cout<<"Write the Word To cheak for palidrome: "<<endl;
    getline(cin,wor);
    stack s(wor.length());
    for(int i=0;i<wor.length();i++)
    {
        s.push(wor[i]);
    }
    if(s.chaek_palindrome(s)){
        cout<<"Yes palindrome!"<<endl;
    }
    else{
        cout<<"Not a palindrome!"<<endl;
    }
}
