#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,x = 1;cin >> n;
    while(n--) x = x*2%(int(1e9+7));
    cout << x;
}