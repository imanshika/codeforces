#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int maxW = 0, maxH = 0, w, h;
    for(int i = 0; i < n; i++) {
        cin >> w >> h;
        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }

    cout << 2*(maxW+maxH) << endl;

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