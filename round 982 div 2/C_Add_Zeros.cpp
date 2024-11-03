#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll u, map<ll,vector<ll> > &g, map<ll,bool> &vis, ll &res){
    if(vis.find(u) != vis.end()) return;
    vis[u] = true;
    res = max(res, u);
    for(auto v : g[u]){
        dfs(v, g, vis, res);
    }
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    map<ll, vector<ll> > g;
    for(ll i = 0; i < n; i++){
        g[a[i]+i].push_back(a[i]+i+i);
    }

    map<ll,bool> vis;
    ll res = 0;

    dfs(n, g, vis, res);

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++)
    {
        solve();
    }
}