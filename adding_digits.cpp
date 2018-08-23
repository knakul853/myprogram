#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int size =10;
int N,M,x2,y2;
int g[size][size];
int visited[size][size];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int f=0;
bool invalid(int x,int y,int val)
{
    return x<0||y<0||x>=N||y>=M||visited[x][y]||g[x][y]<=val;

}
void dfs(int x,int y)
{
    //cout<<"SDG"<<endl;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        int val=g[x][y];
        if(invalid(nx,ny,val))continue;
        visited[nx][ny]=1;
        if(nx==x2&& ny==y2){
                cout<<"YES"<<endl;
                f=1;
                break;}
        dfs(nx,ny);

    }


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1,y1,t;
    cin>>t;
    while(t--){
            f=0;
    cin>>N>>M>>x1>>y1>>x2>>y2;
    --x1;--y1;--x2;--y2;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>g[i][j];
        }
    }

    dfs(x1,y1);
    if(f==0)
        cout<<"NO"<<endl;
    f=0;


    }
}
