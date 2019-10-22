#include<bits/stdc++.h>
using namespace std;
int prime(int x)
{ int j,flag=1;
     for(j=2;j<=sqrt(x);j++)
        {
          if(x%j==0)
          {
          flag=0;
          break;
          }
        }
        if(flag==1)
            cout<<x;
    return flag;
}
int main()
{long long int i,j,k;
int arr[1000000];
long long int sum=0;
long long output=0,n=0;
    for(i=2;i<1000;i++)
    {
       if(prime(i)==1)
       {
           arr[n]=i;
           n+=1;
           cout<<i;
       }
    }
for(i=0;i<n-1;i++)
{sum=0;
    for(j=i;j<n;j++)
    {
        sum+=arr[j];
        if(sum>1000000)
            break;
        if(prime(sum)==1&&sum<1000000)
        {
            output=max(output,sum);
        }
    }
}
cout << output;



}

