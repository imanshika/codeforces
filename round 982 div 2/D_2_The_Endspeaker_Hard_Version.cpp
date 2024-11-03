#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

int solve(int i, int k, int n, int m, vector<int> &a,  vector<int> &b, vector<vector<int> > &dp){
    if(i == n) return 0;
    if(k == m) return n*m;
    if(dp[i][k] != -1) return dp[i][k];

    dp[i][k] = solve(i, k+1, n, m, a, b, dp);

    ll sum = 0;

    for(int j = i; j < n; j++){
        sum += a[j];
        if(sum > b[k]) break;
        dp[i][k] = min(dp[i][k], solve(j+1, k, n, m, a, b, dp)+m-k-1);
    }

    return dp[i][k];
}

void start(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < m; i++) cin >> b[i];

    if(b[0] < *max_element(a.begin(), a.end())) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int> > dp(n+1, vector<int>(m+1, n*m));
    vector<vector<int> > cnt(n+1, vector<int>(m+1, 0));

    for(int k = 0; k <= m; k++) {
        dp[0][k] = 0;
        cnt[0][k] = 1;
    }

    for(int k = 1; k <= m; k++){
        long long sum = 0;
        map<int, int> mp;
        for(int i = 1, l = 1; i <= n; i++){
            sum += a[i-1];
            while(sum > b[k-1]) {
                sum -= a[l-1];
                mp[dp[l][k]] = (mp[dp[l][k]] - cnt[l][k] + mod)%mod;
                l++;
            }
            
            dp[i][k] = min(dp[i][k-1], dp[l-1][k]+m-k);

            if(dp[i][k] == dp[i][k-1]) cnt[i][k] = (cnt[i][k] + cnt[i][k-1])%mod;

            if(dp[i][k] == dp[l-1][k]+m-k && i != l-1) {
                cnt[i][k] = (cnt[i][k] + cnt[l-1][k])%mod;
                if(mp.find(dp[l-1][k]) != mp.end()) cnt[i][k] = (cnt[i][k] + mp[dp[l-1][k]])%mod;
                /*
                for(int j = l; j < i; j++){
                    if(dp[j][k] == dp[l-1][k]) cnt[i][k] = (cnt[i][k] + cnt[j][k])%mod;
                }
                */
            }

            if(l <= i) mp[dp[i][k]] = (mp[dp[i][k]] + cnt[i][k])%mod;
        }
    }

    cout << dp[n][m] << " " << cnt[n][m] << endl;
}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++){
        start();
    }
}