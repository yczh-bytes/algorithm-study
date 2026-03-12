#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N,M;
   cin>>N>>M;

   //存储去的M个城市
   vector<int>city(M);
   for(int i = 0;i<M;i++)
   {
    cin>>city[i];
   }
   //存储票价
  
   vector<vector<int>>price(N,vector<int>(3));
   for(int i = 1;i<N;i++)
   {
     cin>>price[i][0]>>price[i][1]>>price[i][2];
   }
   
  
    
   
    
   //构建差分数组统计每段铁路乘坐次数
   //原理为，每一段铁路都是从from 到to，通过统计from到to区间每次加一的差分数组，实现统计
   vector<int>diff(N+2,0);

   //从第二个城市开始
   for(int i = 1;i<M;i++)
   {
     int from = city[i-1];
     int to = city[i];

     if(from>to)
     {
        swap(from,to);
     }

     //因为此处是铁路的原因，to不需要-1
     diff[from] +=1;
     diff[to] -=1;
   }

   //通过前缀和计算每段铁路乘坐
   vector<int> cnt(N+1,0);

   cnt[1] = diff[1]; 
   for(int i = 2;i<=N;i++)
   {
    cnt[i] = cnt[i-1] + diff[i];
   }

   //通过乘坐次数来计算票价
   long long result = 0;



   for(int i = 1;i<N;i++)
   {
    long long A = price[i][0];
    long long B = price[i][1];
    long long C = price[i][2];

    long long price1 = cnt[i]*A;
    long long price2 = C+cnt[i]*B;

    result += min(price1,price2);
   }

   cout<<result<<endl;
   

}
