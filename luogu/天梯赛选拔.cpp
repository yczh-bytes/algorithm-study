#include <bits/stdc++.h>
using namespace std;
const int MAX=5001;
int father[MAX];

int find(int u)
{
  if(u==father[u])return u;
  int f=find(father[u]);
  return f;
}

void join(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return;
    father[a]=b;
}
bool isQ(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pre(string s1,string s2)
{
    if(s1.size()==0)
    {
        return;
    }
    char root = s2.back();

    cout<<root;

    int index = s1.find(root);

    pre(s1.substr(0,index),s2.substr(0,index));
    pre(s2.substr(index),s2.substr(index,s2.size()-index));
}
int main()
{
    //1.
    /*
    string s;
    cin>>s;
    vector<string>mouths={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    string mouth=s.substr(0,3);
    string day=s.substr(3,2);
    

    int m=0;
    
    for(int i=0;i<12;i++)
    {
        if(mouth==mouths[i])
        {
            m=i+1;
        }
    }

    int d = 0;
    for(char c:day)
    {
       d=d*10+(c-'0');
    }
    cout<<m<<' '<<d;
    */

    //2.
    /*
    int n = 0;
    cin>>n;
    for(int i=n;i>=0;i--)
    {
        int m=0;
        cin>>m;
       
        if(m==0)
        {
            continue;
        }
       
        if(m>0)
        {
            if(i!=n)
            {
                cout<<'+';
            }
           
        }
       
        if(m<0)
        {
            cout<<'-';
        }
         int m1=abs(m);
       
         if(i>0)
         {
            if(m1!=1)
            {
            cout<<m1;
            }
         }
         else
         {
            cout<<m1;
         }
       if(i>0)
       {
        cout<<'x';
        if(i>1)
        {
            cout<<'^'<<i;
        }
       }
        
    }
       */
      //3.
/*
      int n,k,m;
      cin>>n>>k>>m;
      int t=0;
      int count=n;
    
      while(count<m)
      {
        count*=(k+1);
        t++;
      
      }
cout<<t;
*/
//4

   /* int n = 0;
    cin>>n;

    if(n%2==1)
    {
        cout<<-1;
        return 0;
    }

   for(int i = 24;i>0;i--)
   {
    int m = 1<<i;
    if(n>=m)
    {
        cout<<m<<' ';
        n-=m;
    }

   }
    */
   /*
   int m=0;
   cin>>m;

   int l,r,sum;
   l=1;
   r=1;
   sum=1;
   while(l<=m/2)
   {
    if(sum<m)
    {
        r++;
        sum+=r;
    }
    else if(sum>m)
    {
        sum-=l;
        l++;
    }
    else
    {
    
        if(l<r)
        {
        cout<<l<<' '<<r<<endl;
        }
        sum-=l;
    l++;
    }
    
   }
    */
   //括号匹配
   /*
   int t;
   cin>>t;
   string s;
  
   for(int i = 0;i<t;i++)
   {
    cin>>s;
     stack<char>st;
     bool check=true;
    for(char c:s)
    {
        if(c=='('||c=='{'||c=='[')
        {
            st.push(c);
        }
        else
        {
            if(st.empty())
            {
                check=false;
                break;
            }
                if((c==')'&&st.top()=='(')||(c==']'&&st.top()=='[')||(c=='}'&&st.top()=='{'))
        {
            st.pop();
        }
        else
        {
            check=false;
            break;
        }
        }
    
    }
    if(!st.empty())
    {
        check=false;
    }
    if(check)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
   }
    */
   /*
   int n,m,p;
   cin>>n>>m>>p;
   for(int i = 1;i<=n;i++)
   {
    father[i]=i;
   }
   for(int i = 0;i<m;i++)
   {
    int m1,m2;
    cin>>m1>>m2;
    join(m1,m2);
   }
   for(int i = 0;i<p;i++)
   {
    int n1,n2;
    cin>>n1>>n2;
    if(isQ(n1,n2))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
   }
    */
   string s1,s2;
   cin>>s1>>s2;
   pre(s1,s2);
   return 0;
}