#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void permutation(ll* a,ll l, ll r, set<ll> &arr, ll SUM, ll n){
    if(l==r){
        ll sum = 0;
        for(ll i=0;i<n;i++){
            sum += a[i];
            arr.insert(abs(2*sum-SUM));
        }
    }
    for(int i=l;i<=r;i++){
        swap(a[i],a[l]);
        permutation(a,l+1,r,arr,SUM,n);
        swap(a[i],a[l]); // backtracting
    }
}

int main(){
    
    ll n;cin >> n;
    ll s[n],SUM = 0,mn = 1e17;
    set<ll> arr;
    for(ll i=0;i<n;SUM+=s[i],i++) cin >> s[i];
    permutation(s,0,n-1,arr,SUM,n);
    for(auto itr : arr) mn = min(itr,mn);
    cout << mn << endl;
}