#include <bits/stdc++.h>
using namespace std;
long long n,m;


//设置检查函数，查看树木高度是否达标
bool check(vector<int>& num,int mid)
{
    //错误点1，将sum设置为全局变量，应该设置为check里面的局部变量
    long long sum = 0;
    for(auto x : num)
    {
        if(x>mid)
        {
            sum+=x-mid;
        }

        if(sum>=m)
        {
            return true;
        }
    }
    return false;
}

int main()
{
     ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<int>tree(n);
    
    for(int i = 0;i<n;i++)
    {
        cin>>tree[i];
    }
    int tree_max = *max_element(tree.begin(),tree.end());
    //逐个遍历从0开始到最大值
    //错误点二，使用遍历而非二分
    int l = 0;
    int r = tree_max;
     while(l<r)
     {
        //循环应该加一防止死循环
        int mid = (l+r+1)>>1;
       
        if(check(tree,mid))
        {
            l = mid;
        }
        else
        {
            r = mid-1;
        }
     }

        //最后遍历出的l就为最后的结果
        cout<<l;
    
    return 0;
}