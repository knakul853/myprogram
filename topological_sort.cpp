#include<bits/stdc++.h>
#define vii vector<vector<int>>
#define Max 10005
using namespace std;
vii g(Max);
vector<bool>visit(Max,false);
stack<int>st;
void dfs(int sv)
{
    visit[sv]=true;
    for(auto i:g[sv]){
        if(!visit[i]){

            dfs(i);
        }
    }
    st.push(sv);
}

int main(){
int v,e;
cin>>v>>e;

int x,y;
for(int i=0;i<e;i++){

    cin>>x>>y;
    x--;y--;
    g[x].push_back(y);

}
for(int i=0;i<v;i++){
    if(!visit[i])
      dfs(i);
}
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}

}
