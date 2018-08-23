#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m[n],w[n];
        for(int i=0;i<n;i++)
        {
            cin>>m[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        sort(m,m+n);
        sort(w,w+n);
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans+=m[i]*w[i];

        }
        cout<<ans<<endl;
    }


}
