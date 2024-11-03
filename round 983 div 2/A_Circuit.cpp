#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

void start(){
    int n; cin >> n;
    int a = 0, b = 0;
    
    for(int i = 0; i < 2*n; i++){
        int val; cin >> val;
        a += val == 0;
        b += val == 1;
    }

    cout << b%2 << " " << min(a, b) << endl; 
}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++){
        start();
    }
}