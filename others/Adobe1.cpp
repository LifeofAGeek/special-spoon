/*
Problem Statement : 

Input Constraints : 1<=N<=90.

Example Input :   3

Example Output :  5
                  2/5
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    //code goes here
    int n; cin>>n;
    int dp[n+1][2];
    
    memset(dp,0,sizeof(dp));
    dp[0][0]=0; dp[0][1]=1;

    for(int i=1;i<=n;i++){
        dp[i][1] += dp[i-1][0] + dp[i-1][1];
        dp[i][0] += dp[i-1][1];
    }

    int totalWays = dp[n][0]+dp[n][1];
    cout<<totalWays<<endl;
    cout<<dp[n][0]<<'/'<<totalWays;
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
