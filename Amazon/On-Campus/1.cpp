/*
Count of ways to split a given number into prime segments.
*/

const int MAX = 1e6 + 5;
bool prime[MAX];
int spf[MAX];
int dp[MAX];

void sieve()
{
    fill(prime, prime + MAX, true);
    for (int i = 1; i < MAX; i++)spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                if (prime[j]) spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

//Multiple Query
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

bool isPrime(string n){
    int num = stoi(n);
    return prime[num];
}

int f(string s, int i){
    if(i==s.size()) return 1;

    int &ans=dp[i];
    if(ans!=-1) return ans;
    
    ans=0;
    for(int dig=1;dig<=6;dig++){
        if(i+dig<=s.size() and s[i]!='0' and isPrime(s.substr(i,dig))){
            ans+=f(s,i+dig);
            ans%=MOD;
        }
    }
    return ans;
}

void solve(string s){
    //code goes here
    sieve();
    mem(dp,-1);
    cout<<f(s,0);
}
