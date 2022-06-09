#include <bits/stdc++.h> 
void mergesort(vector<int> &arr,int st,int ed,int &tot)
{
    int size=ed-st+1;
    int *temp=new int[size];
    int mid=st+(ed-st)/2;
    int k=mid+1;
    int i=st;
    int t=0;
    int cnt=0;
    for(i=st;i<=mid;i++)
    {
        while(k<=ed && arr[i]>2LL *arr[k])
            k++;
        tot+=(k-(mid+1));
    }
    k=mid+1;
    i=st;
    while(i<=mid && k<=ed)
    {
        if(arr[k]>=arr[i])
        {
            temp[t++]=arr[i];
            i++;
        }
        else 
        {
            temp[t++]=arr[k];
            
            k++;
        }
    }
    while(i<=mid)
    {
        temp[t++]=arr[i];
        i++;
        
    }
    while(k<=ed)
    {
        temp[t++]=arr[k++];
    }
    t=0;
    for(int i=st;i<=ed;i++)
    {
        arr[i]=temp[t++];
//         cout<<arr[i]<<" ";
    }
//     cout<<endl;
    
}
void merge(vector<int> &arr,int st,int ed,int &tot)
{
    if(st>=ed)
        return;
    int mid=st+(ed-st)/2;
//     cout<<st<<" "<<mid<<" "<<ed<<endl;
    merge(arr,st,mid,tot);
    merge(arr,mid+1,ed,tot);
    mergesort(arr,st,ed,tot);
}
int reversePairs(vector<int> &arr, int n){
    // Write your code here.    
    int tot=0;
    merge(arr,0,n-1,tot);
    return tot;
}