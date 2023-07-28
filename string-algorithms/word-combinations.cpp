#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int main(){

	string s; cin >> s;
    ll n = s.size();
    vector<ll> dp(n,0);

    ll k; cin >> k;
    set<string> dict;
    while(k--){
        string sub; cin >> sub;
        dict.insert(sub);
    }

    string str = "";
    for(int i=0;i<n;i++){

        str += s[i];

        if(dict.find(str) != dict.end()){
            dp[i] = 1;
        }

        for(int j=1;j<=i;j++){

            string sub_str = str.substr(j,i-j+1);
            if(dict.find(sub_str) != dict.end()){
                dp[i] = (dp[i] + dp[j-1])%mod;
            }

        }
    }

    cout << dp[n-1] << endl;

}
