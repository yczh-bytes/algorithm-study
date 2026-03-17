#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    unordered_set<string>us;
    for(int i = 0;i<N;i++)
    {
        string s;
        cin>>s;
        us.insert(s);
    }
    cout<<us.size();
    return 0;
}