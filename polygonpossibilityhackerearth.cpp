#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
         sort(a,a+n);
         long long int sum=0;
         for(i=0;i<n-1;i++)
                sum+=a[i];
         if(sum>a[n-1])
         cout<<"Yes"<<endl;
         else
            cout<<"No"<<endl;
    }
}
