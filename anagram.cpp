#include<bits/stdc++.h>
using namespace std;
int main(){
char s1[10],s2[10];  //strcmp return 0 if character array are same :
cin>>s1;
sort(s1,s1+strlen(s1));   //
cin>>s2;
sort(s2,s2+strlen(s2));
if(strcmp(s1,s2)==0)
cout<<s1<<"  "<<s2<<endl;
}
