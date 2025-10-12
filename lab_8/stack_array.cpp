#include<iostream>
using namespace std;
class stack{
public:
int *arr;
int capacity;
int top;
stack(int cap)
{
    arr = new int[cap];
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

int peek()
{
    if(is_empty())
{
    cout<<"Stack is empty!\n";
    return -1;
}
    return arr[top];
}
};
int main() {
    stack s(3);
    s.push(10);
    s.push(20);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;  
    s.pop();
    s.pop(); 
}
