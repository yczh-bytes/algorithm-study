#include <bits/stdc++.h>
using namespace std;



int main()
{
   int n,m;
   int ans = 0;
   int x;
   cin>>n>>m;
   queue<int>q;
   vector<int>vec(1001,0);
   for(int i = 0;i<m;i++)
   {
    cin>>x;
    if(vec[x])continue;
    if(q.size()>=n)
    {
        vec[q.front()]=0;
        q.pop();
    }
    q.push(x);
    vec[x]=1;
    ans++;
   }
   cout<<ans;
    return 0;
}