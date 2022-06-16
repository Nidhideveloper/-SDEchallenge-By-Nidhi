int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> c ={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int required = 0;
    
    while(amount>0){
        int l =0, h= 8, mid, t, flag = 0;
        while(h>=l){
            mid = l+(h-l)/2;
            if(c[mid] == amount){
                t = c[mid];
                flag = 1;
                break;
            }
            else if(c[mid]>amount)
                h = mid-1;
            else
                l = mid+1;
        }
        if(!flag)
            t = c[l-1];
        required++;
        amount -= t;
    }
    return required;
}
