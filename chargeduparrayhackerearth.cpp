#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;

        long long int a[n];

        for(i=0;i<n;i++)
            cin>>a[i];
        long long int x;
        if(n<64)
         x=pow(2,n-1);
        else
        x=pow(2,64);
        long long int sum=0;
        long long int q=pow(10,9)+7;
        for(i=0;i<n;i++)
        {
            if(a[i]>=x)
            {   sum+=a[i]%q;

            }
        }

        sum=sum%q;
      cout<<sum<<endl;
    }

}
