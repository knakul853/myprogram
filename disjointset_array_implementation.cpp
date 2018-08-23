#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int rnk[1000];
void make_set(int x){
parent[x]=x;
rnk[x]=0;
return;
}
int find_parent(int x){

if(parent[x] == x) return x;

find_parent(parent[x]);
}


void make_unioin(int x,int y){

int x_parent = find_parent(x);
int y_parent = find_parent(y);
if(x_parent == y_parent)
return;

if(rnk[x_parent]<rnk[y_parent]){
    parent[x_parent] = y_parent;
}

else if(rnk[x_parent]>rnk[y_parent]){
    parent[y_parent] = x_parent;
}

else{

parent[x_parent] = y_parent;
rnk[y_parent]++;

}
}
int main(){
int n,k;
scanf("%d%d",&n,&k);
for(int i=0;i<n;i++){
    make_set(i);
}

while(k--){
    int x,y;
    scanf("%d%d",&x,&y);
    make_unioin(x,y);

}

int ans =0 ;
for(int i=0;i<n;i++){

    int x = find_parent(x);
    if(x!=i)ans++;
}
printf("%d\n",ans);
return 0;

}
