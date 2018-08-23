#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rep(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long int li;          typedef long long int lli;
typedef long double ld;       typedef pair< int,int > ii;
typedef vector<int> vi;       typedef vector<ii> vii;
const int MAXN = (1<<21);     const int MAXLOG = 21;
typedef vector<vi> graph;     lli MOD=1000000007;long double EPS=1e-9;



void pre(){

}

void solve(){
	int n,a,b;
	cin>>n;
	int arr[n];
	unordered_map<int,int> mp;
	fr(i,n){cin>>arr[i];mp[arr[i]]=i+1;}
	graph g(n);
	fr(i,n-1){
		cin>>a>>b;
		g[a-1].EB(b-1);
		g[b-1].EB(a-1);
	}
	set<lli> st;
	fr(i,n)st.insert(arr[i]);
	fr(i,n){
		st.erase(arr[i]);
		fr(j,g[i].size()){
			st.erase(arr[g[i][j]]);
		}
		auto it=st.rbegin();
		cout<<mp[*it]<<" ";

		st.insert(arr[i]);
		fr(j,g[i].size()){
			st.insert(arr[g[i][j]]);
		}
	}
	cout<<"\n";
}

int main(){
	fastIO;
	pre();
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}
