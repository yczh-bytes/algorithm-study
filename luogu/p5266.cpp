#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int>stu;
    int Q;
    cin>>Q;
    for(int i = 0;i<Q;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            string name;
            int score;
            cin>>name>>score;
            stu[name]=score;
            cout<<"OK"<<endl;
        }
        else if(x==3)
        {
            string name;
            cin>>name;
            if(stu.count(name))
            {
            stu.erase(name);
            cout<<"Deleted successfully"<<endl;
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        else if(x==2)
        {
            string name;
            cin>>name;
            if(stu.count(name))
            {
                cout<<stu[name]<<endl;
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        else if(x==4)
        {
           cout<<stu.size() <<endl;
        }
    }
   
    return 0;
}