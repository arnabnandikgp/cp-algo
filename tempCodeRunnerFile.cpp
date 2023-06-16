
    if(rec(level+1,left))
    {
        ans=1;
    }
    else if(rec(level+1,left-items[level]))
    {
        ans=1;
    }

    return dp[level][left]=ans;