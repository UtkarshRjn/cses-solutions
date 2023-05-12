#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll n, p;
vector<ll> cost_from_deleting;
vector<ll> cost_from_adding;
vector<ll> sticks;

void solve(){
	
    cin >> n;
    while(n--){
        cin >> p;
        sticks.push_back(p);
    }

    sort(sticks.begin(), sticks.end());

    ll curr = 0;
    cost_from_adding.push_back(curr);
    for(ll i=1;i<sticks.size();i++){
        curr += i*(sticks[i]-sticks[i-1]);
        cost_from_adding.push_back(curr);
    }    

    curr = 0;
    ll cnt = 1;
    cost_from_deleting.push_back(curr);
    for(ll i=sticks.size()-2;i>=0;i--){
        curr += cnt*(sticks[i+1] - sticks[i]);
        cost_from_deleting.push_back(curr);
        cnt++;
    }

    ll min_cost = INT_MAX;
    for(ll i=0;i<sticks.size();i++){
        min_cost = min(min_cost,cost_from_adding[i] + cost_from_deleting[sticks.size()-i-1]);
    }

    cout << min_cost << endl;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}