#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const int mod = 1e9+7;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}

bool lexo_inc(string a, string b) {
	return a < b;
}

bool lexo_dec(string a, string b){
	return a > b;
}

bool isP(int ni, int nj, ll n ,ll m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void solve(){

    ll n; cin >> n;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<vector<char>> mat(n,vector<char>(n));
    dp[0][0] = 1;


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];

            if(i==0 && j==0) continue;
            dp[i][j] = (((i>0) ? dp[i-1][j] : 0) + ((j>0) ? dp[i][j-1] : 0))%mod; 
            if(mat[i][j] == '*') dp[i][j] = 0;
        }
    }


    cout << ((mat[0][0] != '*') ? dp[n-1][n-1] : 0) << endl;

}

int main(){
	solve();
}