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
         if(m1!=1)
         {
        cout<<m1;
         }
        if(i!=0)
        {
        cout<<'x'<<'^'<<i;
        }
        
    }