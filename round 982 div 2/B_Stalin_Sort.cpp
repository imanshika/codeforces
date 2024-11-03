#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int res = n;

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i+1; j < n; j++){
            if(a[j] > a[i]) cnt++;
        }
        res = min(res, cnt+i);
    }

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