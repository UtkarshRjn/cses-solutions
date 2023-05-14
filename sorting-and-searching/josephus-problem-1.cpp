#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
ll n, x;
vector<ll> v;

void solve(){
	
    cin >> n;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }

    int index = 0;
    while(v.size() != 1){
        index = (index+1) % v.size();
        cout << v[index] << " ";
        v.erase(v.begin() + index);
    }

    cout << v[0] << endl;    

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}