#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

void start(){
    int n; cin >> n;
    vector<ll> a(n), x(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < n; i++) cin >> x[i];

    vector<int> minPlay(n, -1);
    vector<int> setBit(n, 0);
    vector<int> greaterBit(n, 0);

    for(int i = 0 ; i < n; i++){
        ll bit = 1;
        while(bit <= a[i]) bit = bit*2;
        x[i] = x[i]&(bit-1);

        for(int j = bit/2; j > 0; j/2){

            setBit[i] += j&x[i] ? 1 : 0;

            if((j&a[i]) && !(j&x[i])) {
                minPlay[i] = minPlay[i] == -1 ? 1 : minPlay[i];
            }else if(!(j&a[i]) && (j&x[i])){
                minPlay[i] = minPlay[i] == -1 ? 2 : minPlay[i];
                greaterBit[i] += minPlay[i] == 2 ? 1 : 0;
            }
        }

        minPlay[i] = max(minPlay[i], 1);

    }

}

int main()
{
    ios::sync_with_stdio(false);   
    int test; cin>>test;
    for(int t = 1; t <= test; t++){
        start();
    }
}