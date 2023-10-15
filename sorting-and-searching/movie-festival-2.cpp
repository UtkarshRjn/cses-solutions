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
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
void solve(){
 
    ll n,k; cin >> n >> k;
    vector<pll> v(n);
    multiset<ll> st;
 
    for(auto &x: v)  
        cin >> x.second >> x.first;
 
    sort(v.begin(),v.end());
 
    int count = 0;
    for(auto e: v){
 
        if(st.empty()){
            st.insert(e.first);
            count++;
        }else{
            auto t = st.upper_bound(e.second);
 
            if(t != st.begin()){
                st.erase(--t);
                st.insert(e.first);
                count++;
            }else if(st.size() < k){
                st.insert(e.first);
                count++;
            }
 
        }
    }
 
    cout << count << endl;
 
 
}
 
int main(){
	solve();
}