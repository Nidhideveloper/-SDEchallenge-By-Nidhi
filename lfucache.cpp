#include<bits/stdc++.h>

struct Entry{ int val, freq; list<int>::iterator itr; };

class LFUCache
{
    unordered_map<int,Entry> entries;
    unordered_map<int,list<int>> lists;
    int caps, minm;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        caps = capacity;
        minm = 0;
    }

    int get(int key)
    {
        // Write your code here.
        if(!entries.count(key))    return -1;
        Entry entry = entries[key];
        //erase item in old frequency list
        lists[entry.freq].erase(entry.itr);  
        //update minm if no items is present in minm frequency list
        if(entry.freq==minm and lists[minm].empty()) minm++;
        //push item in new frequency list and save iterator
        lists[++entry.freq].push_back(key);
        entry.itr = --lists[entry.freq].end();
        entries[key] = entry;
        return entry.val;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(caps<=0) return;
        if(entries.count(key)) {
            //key is present
            entries[key].val = value;
            get(key);   //update frequency
            return;
        }
        if(caps==entries.size()) { 
            //if size is caps remove the element with least frequency
            int rkey = *lists[minm].begin();
            lists[minm].erase(lists[minm].begin());
            entries.erase(rkey);
        }
        minm = 1; //push item in minm = 1 frequency list
        lists[minm].push_back(key);
        entries[key] = {value,minm,--lists[minm].end()};
    }
};
