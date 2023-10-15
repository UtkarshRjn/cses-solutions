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

ll count(ll n){

    vector<ll> digits;

    while(n){
        digits.push_back(n%10);
        n/=10;
    }

    ll numDigit = digits.size();
    
    vector<bool> waste;
    bool inValid = false;
    waste.push_back(0);
    for(int i=numDigit-2;i>=0;i--){
        waste.push_back(inValid);
        if(digits[i] == digits[i+1]) inValid = true;
    }

    reverse(waste.begin(),waste.end());

    ll ans = (digits.back()-1)*powl(9,numDigit-1);

    for(int i=0;i<numDigit-1;i++){
        ll d = digits[i];
        if(d > digits[i+1]) d--;
        if(!waste[i]) ans += d*powl(9,i);
    }

    for(int numSize=1; numSize < numDigit; numSize++)
        ans += powl(9,numSize);
    
    return ans;

}

void solve(){
 
    ll a,b; cin >> a >> b;
    b++;

    ll cntA  = (a) ? count(a) : -1;
    ll cntB = count(b);

    cout << cntB - cntA << endl;
    
}

int main(){
	solve();
}