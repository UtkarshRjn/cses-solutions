#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

vector<ll> preprocess(string p){

    ll i = 1, j = 0;
    ll n = p.size();
    vector<ll> lps(n);
    lps[0] = 0;
    while(i < n){
        if(p[i] == p[j]){
            lps[i++] = ++j;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i++] = 0;
            }
        }
    }

    return lps;

}

int main(){

    string p; cin >> p;

    ll n = p.size();
    vector<ll> lps = preprocess(p);

    vector<ll> ans;
    ll j = n - 1;
    while(lps[j]){

        ans.push_back(lps[j]);
        j = lps[j] - 1;

    }

    sort(ans.begin(), ans.end());
    for(auto e: ans){
        cout << e << " ";
    }
    cout << endl;

}
