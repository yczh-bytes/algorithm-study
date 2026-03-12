#include <bits/stdc++.h>
using namespace std;



int main()
{
    int m,target;
    int n;
    cin>>n>>m;
    vector<long long> num(n);

    for(int i = 0;i<n;i++)
    {
        cin>>num[i];
    }
    for(int j = 0;j<m;j++)
    {
        cin>>target;
        //index实际上是一个指针
        auto index = lower_bound(num.begin(),num.end(),target);
       if(*index == target)
       {
        cout<<(index - num.begin()+1)<<' ';
       }
       else
       {
        cout<<-1<<' ';
       }
    }

    
    return 0;
}