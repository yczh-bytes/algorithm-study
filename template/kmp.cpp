#include <bits/stdc++.h>
using namespace std;

//构建next数组
vector<int>getNext(string s)
{
    int n = s.size();
    vector<int>next(n,0);
    for(int i = 1,j=0;i<n;i++)//从i==1开始因为i等于0 next[i]一定等于0
    {
        //当j》0表示至少匹配了一个字符，当前字符不匹配时回退j
        //回退到next[j-1]
        while(j&&s[i]!=s[j]) j = next[j-1];

        if(s[i]==s[j])
        {
            j++;
        }
        next[i]=j;
    }
    return next;
}

//kmp匹配
vector<int>kmp(string t,string p)
{
    vector<int>res;//存储结果
    vector<int>next=getNext(p);//获取next数组

    int n = t.size();
    int m = p.size();
    //i遍历文本串，j遍历匹配串
    for(int i=0,j=0;i<n;i++)
    {
        while(j&&t[i]!=p[j])j=next[j-1];

        if(t[i]==p[j])j++;

        if(j==m)
        {
            res.push_back(i-m+1);
            j=next[j-1];
        }
    }
    return res;
}

int main()
{
    string a = "abcabckadsjlabc";
    string p = "abc";
    
    vector<int>result=kmp(a,p);
    for(int x:result)
    {
        cout<<x<<endl;
    }
    return 0;
}