#include<bits/stdc++.h>
using namespace std;
int main(){
    int mask1;
//clear bit form lowest bit to ith bit
int n=27,i=5;
int mask=~((1<<i+1)-1); //creating a mask from i+1 th bit and sub 1 from the nuber and than xor it with given number
//printf("%d ",mask&n);
//clear all bit from msb bit to ith bit:
i=3;
mask1 = ((1<<i)-1);
printf("%d ",mask1&n);
}
