from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)
def countWaysToMakeChange(d, value) :
    
	# Your code goes here
    dp=[0]*(value+1)
    dp[0]=1;
    for i in range(len(d)):
        for j in range(d[i], len(dp)):
            dp[j]+=dp[j-d[i]];
    return dp[-1];































#taking inpit using fast I/O
def takeInput() :
    numDenominations = int(input())

    denominations = list(map(int, stdin.readline().strip().split(" ")))

    value = int(input())
    return denominations, numDenominations, value


#main
denominations, numDenomination, value = takeInput()
print((countWaysToMakeChange(denominations, value)))