#include<bits/stdc++.h>
using namespace std;
void mycopy(char s1[],char s2[])
{  int i=0;
    while(s1[i]!='\0')
        s2[i]=s1[i++];
        s2[i]='\0';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s1[100];
    char s2[100];
    cin>>s1;
    mycopy(s1,s2);
    cout<<s2;

}
