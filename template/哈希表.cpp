#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_set<int>us;
    unordered_map<int,string>um;//key和value对

    //公共接口
    us.insert(1);
    us.insert(1);//重复不会存入
    us.insert(4);
    us.insert(9);

    for(auto x:us)
    {
        cout<<x<<' ';
    }
    us.erase(9);
      for(auto x:us)
    {
        cout<<x<<' ';
    }
    int size = us.size();
    cout<<us.empty();
    auto x1 = us.find(1);//返回迭代器，未找到返回end()
    auto x2 = us.find(2);

    cout<<us.count(1);
    cout<<us.count(10);//找到返回1，未找到返回0

    us.clear();
    cout<<us.size();
    //begin() end()迭代器

    //unordered_map特有接口

    um[0]="fds";
    //um.operator[0] = "fds";//访问或创建键值对应的值
    //at(0);//安全访问

    return 0;
}