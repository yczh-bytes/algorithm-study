#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class trie
{
private:
struct treeNode
{
    treeNode(char ch,int freq):ch(ch),freq(freq){}
char ch;//存储的字符
int freq;//每个单词末尾加一代表之前是一个单词
map<char,treeNode*> treemap;//存储孩子节点数据以及相应的对应关系
};
public:
//初始化头结点
trie()
{
  root = new treeNode('\0',0);
}

void add(const string& s)
{
    //创建一个指针指向头结点
    treeNode* cur = root;
for(int i = 0;i<s.size();i++)
{
    auto childT = cur->treemap.find(s[i]);
    //如果指向的是头结点
    if(childT==cur->treemap.end()) 
    {
        //如果没有这个字符就创建一个
        treeNode* child = new treeNode(s[i],0);
        cur->treemap.emplace(s[i],child);
        cur = child;
    }
    else
    {
        //如果存在就指向下一个孩子节点
        cur = childT->second;
    }
}

//循环结束证明添加了一个单词，此时记录一下单词数
cur->freq++;
}

//查询接口
int query(const string& s)
{
    treeNode* cur = root;
    for(int i = 0;i<s.size();i++)
    {
        //查询字符
        auto childQ = cur->treemap.find(s[i]);
        if(childQ==cur->treemap.end())
        {
            return 0;
        }
        //将字符指针移动
        cur = childQ->second;
    }
    //返回统计频率的数
    return cur->freq;
}
//查询前缀
bool stratsWith(string prefix)
{
    treeNode* node=root;
    for(char c:prefix)
    {
       auto it=node->treemap.find(c);
       if(it==node->treemap.end())return false;
       node=it->second;
    }
    return true;
}
//前序遍历字典树
//公共接口
void getPer()
{
    
}
private:
//定义一个头结点
treeNode* root;
};

int main()
{
    trie t;
    t.add("hello");
    t.add("hel");
    t.add("hello");
    t.add("cello");
    t.add("llo");
    t.add("afdllo");
    t.add("heafllo");
    t.add("heldlo");
    t.add("hel");

    cout<<t.query("hello")<<endl;

    return 0;
}