#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//高精度加法
vector<int>add(vector<int>& A,vector<int>& B)
{
    vector<int>C;//储存结果
    int t = 0;//进位
   for(int i = 0;i<A.size()||i<B.size()||t;i++)
   {
    if(i<A.size())t+=A[i];//将数字取出加入t
    if(i<B.size())t+=B[i];

    C.push_back(t%10);//存储小于t中十的部分
    t/=10;//去掉存进去的那位
   }
   return C;
}

int main()
{
    string a,b;
    cin>>a>>b;

    vector<int>A,B;
    //字符串转为数字，倒着存入vector数组
    for(int i = a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i = b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    auto C=add(A,B);
    //倒序输出
    for(int i = C.size()-1;i>=0;i--)cout<<C[i];
    return 0;
}