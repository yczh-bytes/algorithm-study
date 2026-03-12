#include <iostream>
using namespace std;
const int N = 100010;
//单调栈的模拟
class SeqStack
{
private:
int data[N];
int top;
public:
//初始化栈
SeqStack()
{
top = 0;
}

bool empty()
{
    return top==0; 
}
bool isFull()
{
    return top==N;
}

bool push(int x)
{
    if(isFull())return false;
    data[top++] = x;
    return true;
}

int gettop()
{
    if(empty())return -1;

    return data[top-1];
   
}
bool pop()
{

    if(empty())return false;
    top--;
    return true;
}
};
//链式栈的实现
class LinkStack
{
private:
struct Node
{
    int data;
    Node* next;
     Node(int data = 0) : data(data), next(nullptr) {}
};
int size;
Node* head;
public:
LinkStack()
{
    head = new Node();
    size = 0;
}
~LinkStack()
{
    Node* p = head->next;
    while(p!=nullptr)
    {
        head = p->next;
        delete(p);
       p = head;
    }
    delete(head);
}

void push(int x)
{
    Node* newNode = new Node(x);
    newNode = head->next;
    head->next=newNode;
    size++;
}

void pop()
{
    Node* p = head->next;
    head->next = p->next;
    delete(p);
    size++;
}

int top()
{
    return head->next->data;
}

int Size()
{
    return size;
}

bool isEmpty()
{
    if(head->next==nullptr)return true;
    return false;
}

};
//环形队列
class Qquene
{
private:
int *Qqu;//
int mcp;//队列大小
int fonst;//队头
int reat;//队尾
int Size;
public:
Qquene(int size = 10):mcp(size),fonst(0),reat(0),Size(0)
{
    Qqu = new int[size];
}
~Qquene()
{
    delete []Qqu;
    Qqu = nullptr;
}

void pusu(int x)
{
    if(((reat+1)%mcp)==fonst)
    {
        throw "队列满了";
        expand(2*mcp);
    }
    Qqu[reat] = x;
    reat = (reat+1)%mcp;
}
void pop()
{
    if(reat == fonst)
    {
        throw "队空";
    }
    fonst = (fonst+1)%mcp;
}
//获取队头元素
int getHead()
{
    return Qqu[fonst];
}
//获取队尾元素
int getBack()
{
    return Qqu[reat];
}
private:
void expand(int Tosize)
{

}
};
int main()
{
    SeqStack st;
    for(int i = 1;i<=10;i++)
    {
        st.push(i);
    }
    for(int i = 0;i<10;i++)
    {
        cout<<st.gettop()<<' ';
        st.pop();
    }

    LinkStack ls;
    for(int i = 1;i<=10;i++)
    {
        ls.push(i);
    }
    for(int i = 0;i<10;i++)
    {
        cout<<ls.top()<<' ';
        ls.pop();
    }

}
