#include<bits/stdc++.h>
bool static cmp(pair<int,int>a,pair<int,int>b )
{
  double r1 = (double)a.second/(double)a.first;
  double r2 = (double)b.second/(double)b.first;
  return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
   sort(items.begin(),items.end(),cmp);
   double profit = 0;
   for(int i=0;i<n;i++)
   {
       if(w>0)
       {
           if(w>=items[i].first)
           {
               w = w-items[i].first;
               profit = profit + (double)items[i].second;
           }
           else
           {
               profit = profit + (double)items[i].second*((double)w/(double)items[i].first);
               w=0;
           }
       }
       else break;
   }
   return profit;
}