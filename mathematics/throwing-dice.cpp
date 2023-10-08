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
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
ll mod = 1e9 + 7;
 
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

#define SZ 1000005
const ll MOD = 1e9 + 7;

vector<vector<ll> > Identity(ll n){

    vector<vector<ll> > I(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        I[i][i] = 1;
    }

    return I;

}

vector<ll> matmul(const vector<vector<ll> >& mat,const vector<ll>& v){
    
    int m = mat.size();
    int n = mat[0].size();
    vector<ll> ans;
    for(int i=0;i<m;i++){
        ll curr = 0;
        for(int j=0;j<n;j++){
            curr = (curr + mat[i][j] * v[j] % MOD) %  MOD;
        }
        ans.push_back(curr);
    }

    return ans;

}

vector<vector<ll> > matmul2(const vector<vector<ll> >& mat1,const vector<vector<ll> >& mat2){
    
    int m = mat1.size();
    int n = mat1[0].size();
    int p = mat2[0].size();
    vector<vector<ll> > ans(m,vector<ll>(p));
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            ll curr = 0;
            for(int k=0;k<n;k++){
                curr = (curr + mat1[i][k] * mat2[k][j] % MOD) %  MOD;
            }
            ans[i][j] = curr;
        }
    }

    return ans;

}

vector<vector<ll> > Matpow(vector<vector<ll> >& mat, ll n){ // mat ^ n
    
    vector<vector<ll> > ans = Identity(mat.size());
    while(n){
        
        if(n%2) ans = matmul2(ans, mat);
        mat = matmul2(mat, mat);
        n/=2;

    }

    return ans;
}

void solve() {

    ll n; cin >> n;
    vector<ll> F(6,1); // F[0] -> number of ways to get 1
    vector<vector<ll> > M(6,vector<ll>(6,0));
    
    for(int i=0;i<6;i++){
        M[0][i] = 1;
        if(i < 5) M[i+1][i] = 1;
    }

    for(int i=1;i<=6;i++){
        for(int j=1;j<i;j++){
            F[i-1] += F[j-1];
        }
    }

    if(n <= 6){
        cout << F[n-1] << endl;
        return;
    }
    reverse(F.begin(),F.end());
    vector<ll> Fn = matmul(Matpow(M,n-6),F);

    cout << Fn[0] << endl;

}

int main(){

	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}