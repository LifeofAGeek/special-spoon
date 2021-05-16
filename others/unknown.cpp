/*

Given a 2D array of size N x M (N = rows, M = cols), you have to choose exactly one element from each row. So total N elements right ?

You have to choose such N numbers such that the difference b/w min element and max element is minimized !

Example :

A = {
    {12,3,10,9,14}, 
    {6,5,6,8},
    {1,2,3,5},
    {6,9,4}
}

Answer = 2.  How ?
Numbers choosen from each row is 3,5,5,4 -> min = 3 and max = 5 and diff = 2 which is minimum among all possible combinations.


Input Constraints:

Subtask 1 : 
1 <= t <= 10
1 <= N <= 500
1 <= M <= 100
1 <= A[i][j] <= 1e6

Subtask 2 : 
1 <= t <= 10
1 <= N <= 5000
1 <= M <= 1000
1 <= A[i][j] <= 1e6

*/


#include<bits/stdc++.h>
using namespace std;

void solve(){
    //code goes here
    vector<vector<int>> sticks = {{12,3,10,9,14},{6,5,6,8},{1,2,3,5},{6,9,4}};
    int n = sticks.size(), m = sticks[0].size();

    for(auto& row:sticks){
        sort(begin(row),end(row)); // sort each row : O(nlogm)
    }  

    int globalDiff = INT_MAX;
    for(int j=0;j<m;j++){
        int val = sticks[0][j];
        int minn = val, maxx = val;
        cout<<"choosen "<<val<<" in row "<<1<<endl;
        for(int i=1;i<n;i++){
            auto it = lower_bound(sticks[i].begin(),sticks[i].end(),val);
            int currDiff = abs(val-*it);
            int choose = *it;

            if(it!=sticks[i].begin()){
                int a = *prev(it);
                if(abs(a-val)<currDiff){
                    currDiff = abs(a-val);
                    choose = a;
                }
                else if(abs(a-val)==currDiff){
                    choose = min(a,*it);
                }
            }
            if(it!=sticks[i].end()){
                int a = *next(it);
                if(abs(a-val)<currDiff){
                    currDiff = abs(a-val);
                    choose = a;
                }
                else if(abs(a-val)==currDiff){
                    choose = min(a,*it);
                }
            }
            cout<<"choosen "<<choose<<" in row "<<i+1<<endl;
            minn = min(minn, choose);
            maxx = max(maxx, choose);
        }
        globalDiff = min(globalDiff, maxx-minn);
        cout<<"----------------------------\n";
    }

    cout<<globalDiff;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
