#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

void start(){
    int n, k; cin >> n >> k;
    
    if(n == 1){
        cout << 1 << endl <<  1 << endl;
        return;
    }

    if(k == 1 || k == n){
        cout << -1 << endl;
        return;
    }


    vector<int> res;
    if(k == (n+1)/2){
        for(int i = 1; i <= n; i++) res.push_back(i);
    }
    else if(k <= n/2){
        for(int i = 1; i <= 2*k-1; i++) res.push_back(i);
    }else {
        res.push_back(1);
        for(int i = 2*k-n+1; i <= n; i++) res.push_back(i);
    }

    cout << res.size() << endl;
    for(auto it : res) cout << it << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++){
        start();
    }
}