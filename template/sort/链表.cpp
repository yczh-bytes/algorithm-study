#include <iostream>
using namespace std;

//创建链表
struct Node
{

    int data;
    Node* next;//指向后一节点的地址
     Node(int val = 0) : data(val), next(nullptr) {}
};
class LinkedList{
    private:
    Node* head;//定义虚拟头结点
    public:
    //构造函数
    LinkedList()
    {
        head = new Node();
    }
    //析构函数
    ~LinkedList()
    {
        Node* p = head;
        while(p!=nullptr)
        {
            Node*q = p->next;
            delete(p);
            p = q;
        }
    }
//单链表的尾插法
void Inserttail(int val)
{
    Node* newNode = new Node(val);
    Node* p = head;
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    p->next = newNode;

}
//单链表的头插法
void Inserthead(int val)
{
    Node* p = head->next;
    Node* newNode = new Node(val);
    head->next = newNode;
    newNode->next = p;
}
//删除链表中元素
void eleDelete(int val)
{
    Node* p = head->next;
    Node* q = head;
    while(p!=nullptr)
    {
        if(p->data==val)
        {
            q->next = p->next;
            delete(p);
            p = q->next;
            return;
        }
        else
        {
          q = p;
          p = p->next;
        }
    }
    return;
}
//连续删除链表中元素
void eleDeletes(int val)
{

    Node* p = head->next;
    Node* q = head;
    while(p!=nullptr)
    {
        if(p->data==val)
        {
            q->next = p->next;
            delete(p);
            p = q->next;
            
        }
        else
        {
          q = p;
          p = p->next;
        }
    }
   
}
//打印
void show()
{
    Node*p = head->next;
    while(p!=nullptr)
    {
        cout<<p->data<<' ';
        p = p->next;
    }
}
};
int main()
{
    LinkedList list;
    for(int i = 0;i<10;i++)
    {
       int val = i;
       list.Inserttail(val);
       int val2 = i+10;
       list.Inserthead(val2);
    }
    list.eleDelete(15);
    list.show();
    return 0;
}