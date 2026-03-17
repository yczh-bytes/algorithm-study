#include <iostream>
#include <vector>
using namespace std;
vector<int>father;//定义父数组

//查询祖宗
int find(int u)
{
if(father[u]==u) return u;
    int f = find(father[u]);
    //路径压缩，将找到的根节点直接赋给父节点，减少递归层数
    father[u]=find(father[u]);
return father[u];
}

//查询两个元素是否为亲戚
bool isrelative(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a==b)
    {
        return true;
    }
    else{
    return false;
    }
}
//设置两人为亲戚关系
void join(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    {
        return ;
    }
father[a]=b;
}
int main()
{
    return 0;
}