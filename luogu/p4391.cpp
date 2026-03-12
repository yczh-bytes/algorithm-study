#include <bits/stdc++.h>
using namespace std;

char c[1000010];
int ne[1000010];
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>c+1;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&c[i]!=c[j+1])j=ne[j];

        if(c[i]==c[j+1])
        {
            j++;
        }

        ne[i]=j;
    }
    
    int ans = n-ne[n];
    cout<<ans;
    return 0;
}