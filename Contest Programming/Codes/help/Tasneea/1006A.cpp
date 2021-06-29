#include<bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b){
return ( *(int*)a - *(int*)b);
}
int main()
{
int n,mx=0;
cin>>n;
 int arr[n+100];
 int cpy[((n)*2)+100],k=1;
for(int i=1;i<=n;i++)
{
    scanf("%d",&arr[i]);
   cpy[k]=arr[i];
   cpy[k+1]=arr[i]+1;
   k+=2;
    if(arr[i]>mx)mx=arr[i];
}
k=k-2;
cout<<"before sort"<< endl;
for(int i = 1; i<=2*n ; i++){
    cout<<"cpy "<<i<<" "<<cpy[i]<<endl;
    //cout<<diff[i]<<" ";
}

cout<<"after sort"<<endl;
cpy[0]=0;
///cout<<sizeof(cpy)/sizeof(int)<<endl;
cout<<k<<endl;
///jetai korina ken after sorting cpy[1] ultapalta value ashe :/
///qsort(cpy,k+1,sizeof(int),compare);
///cpy[1]=cpy[2];
///cout<<"frigging cpy [1]"<<cpy[1]<<endl;
///int m = sizeof(cpy)/sizeof(cpy[1]);
sort(cpy+1, cpy+k+1); /// k ek beshi  e ase bole increment kortesina r
///iterate through the sorted array to find the minimum difference between adjacent numbers
int diff[n+1];
for(int i = 1 ; i <= (2*n) ; i++)
{

  //cout<<"cpy "<<cpy[i]<<" "<<endl;
  diff[i]=cpy[i+1]-cpy[i];
 // cout<<diff[i]<<" ";
}
///ekhane eshe abr value change hocche kemne??????????? :@
for(int i = 1; i<=(2*n) ; i++){
    cout<<"cpy "<<i<<" "<<cpy[i]<<endl;
  //  cout<<diff[i]<<" ";
}
cout<<endl;
int i=1;
k=1;/*
///for(int i=1;i<=mx;i++)
while(k!=(2*(n+1)))
{


{
    for(int j=1;j<=n;j++)
    {
        if(i%2!=0){
            if(arr[j]==i)arr[j]=i+1;
        }
         else if(i%2==0){
            if(arr[j]==i)arr[j]=i-1;
        }
    }
}
i=i+diff[k];
k++;
}
for(int i=1;i<=n;i++)
{
   printf("%d",arr[i]);
   cout<<" ";
//    if(arr[i]>mx)mx=arr[i];*/
}
////}
