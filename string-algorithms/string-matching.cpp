#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

vector<ll> compute_prefix(string s){

    int n = s.size();
    vector<ll> prefix(n);
    int j = 0;
    prefix[0] = 0;
    for(int i=1;i<n;i++){

        while(s[i] != s[j] && j != 0){            
            
            j = s[j];
        }

        if(s[i] == s[j]){
            prefix[i] = j + 1;
            j++;    
        }else{
            prefix[i] = 0;
        }

    }

    return prefix;

}

int main(){

	string s,pattern;cin >> s >> pattern;

    vector<ll> prefix = compute_prefix(pattern);

    ll ans = 0;
    for(int j=0,i=0;j<s.size();){
        if(s[j] == pattern[i]){
            i++;
            j++;
        }else{
            if(i > 0) i = prefix[i-1];
            else j++;
        }

        if(i==pattern.size()){
            i = prefix[pattern.size()-1];
            ans++;
        }
    }

    cout << ans << endl;

}
