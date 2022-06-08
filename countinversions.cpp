#include <bits/stdc++.h> 
long long merge(long long *arr, int si, int mid, int ei){

   long long inv = 0;

   int m = mid - si + 1;

   int n = ei - mid;

   int k=0, a[m], b[n];

   for(int i=si; i<=mid; i++){

       a[k++] = arr[i];

   }

   k=0;

   for(int i=mid+1; i<=ei; i++){

       b[k++] = arr[i];

   }

   int i=0, j=0;

   k = si;

   while(i<m && j<n){

       if(a[i] > b[j]){

           inv += m - i;

           arr[k++] = b[j++];

       }else{

           arr[k++] = a[i++];

       }

   }

   while(i<m){

       arr[k++] = a[i++];

   }

   while(j<n){

       arr[k++] = b[j++];

   }

   return inv;

}

 

long long getInversionsHelper(long long *arr, int si, int ei){

   long long inv = 0;

   if(si < ei){

       int mid = (si+ei)/2;

       inv += getInversionsHelper(arr, si, mid);

       inv += getInversionsHelper(arr, mid+1, ei);

       inv += merge(arr, si, mid, ei);

   }

   return inv;        

}

 

long long getInversions(long long *arr, int n){

   return getInversionsHelper(arr, 0, n-1);

}