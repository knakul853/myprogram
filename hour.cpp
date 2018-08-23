
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define io ios::sync_with_stdio(false)
using namespace std;

int main()
{
    io;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mt[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mt[i][j];
            }

        }
        int f=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(mt[i][j]==mt[i][j+1] ||mt[i][j]==mt[i+1][j])
                {
                    cout<<"No"<<endl;
                    f=1;
                    break;
                }

            }
            if(f)
            {
                break;
            }
        }
        if(!f)
        cout<<"Yes"<<endl;


    }

}

