#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

void start(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int res = INT_MAX;

    for(int i = 0, r = 0; i < n-1; i++){
        int low = a[i];
        while(r < n && a[r] < a[i]+a[i+1]) r++;
        res = min(res, i+n-r);
    }

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++){
        start();
    }
}