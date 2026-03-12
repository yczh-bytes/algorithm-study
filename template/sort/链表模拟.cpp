#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
/*
head指向头结点
data数组储存值
next数组储存下一个节点地址
index指当前指针所在地址
*/
int head,index;
int data[N];
int ne[N];

void start()
{
    //初始化
    head = -1;
    index = 0;//从0开始分配内存
}

//从头结点开始添加元素
void add_head(int x)
{
    data[index] = x;//储存值
    ne[index] = head;//新节点指向头结点
    head = index;//将头结点移动
    index++;//指向下一位
}
//将元素插入到k节点之后
void Insert(int x,int k)
{
    data[index] = x;
}
int main()
{
    for(int i = 0;i<10;i++)
    {
        start();
        add_head(i);
    }
    for(int i = 0;i<10;i++)
    {
        cout<<data[i]<<' ';
        cout<<ne[i]<<endl;
    }
    return 0;
}