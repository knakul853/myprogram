#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin,s);
    int i;
    int mark[26]={0};
    int l = s.length();
    for(i=0;i<l;i++)
    {
        mark[s[i]-'a']=1;
    }
    for(int i=0;i<26;i++)
    {   if(mark[i]==0)
        cout<<char('a'+i);
    }
}

