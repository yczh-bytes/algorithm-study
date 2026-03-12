#include <bits/stdc++.h>
using namespace std;

vector<int>getnext(string s)
{
    int n = s.size();
    vector<int>next(n,0);
    for(int i = 1,j=0;i<n;i++)
    {
        while(j&&s[i]!=s[j]) j= next[j-1];

        if(s[i]==s[j])
        {
            j++;
        }
        next[i] = j;
    }
    return next;
}

vector<int>kmp(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int>next = getnext(s2);
    vector<int>res;
    for(int i = 0,j=0;i<n;i++)
    {
        while(j&&s1[i]!=s2[j])j=next[j-1];

        if(s1[i]==s2[j])
        {
            j++;
        }
 

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
    string s1,s2;
    cin>>s1>>s2;

    vector<int>result1=kmp(s1,s2);
    vector<int>result2=getnext(s2);
    for(int x:result1)
    {
        cout<<x+1<<endl;
    }
    for(int x:result2)
    {
        cout<<x<<' ';
    }
    return 0;
}