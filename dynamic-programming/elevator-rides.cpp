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
 
    int n, x; cin >> n >> x;
 
    int peopleWeights[n];
    for (auto &x : peopleWeights) cin >> x;
 
    //We need to use bitmasking to compute the dp table
 
    vector <pair <int, int> > dp (1 << n);
    // Pair : {NumberOfElevatorRides , WeightOfLastRide} for the 
    // chosen subset of people
 
    dp[0] = make_pair(1, 0);
    //First ride with no people for empty subset of chosen people
 
    for (int subset = 1; subset < (1 << n); subset++) {
 
        dp[subset] = make_pair(21, 0);
        //We consider that the chosen subset of people need 21 rides
        //(since we know , n <= 20) with an empty last ride.
 
        for (int person = 0; person < n; person++) {
 
            //We check if the person is a part of the chosen subset of people
            
            if ((subset >> person) & 1) {
                auto rw = dp[subset ^ (1 << person)];
                //gets the state of the elevator rides upto the last chosen person
                int rides = rw.first;
                int weight = rw.second;

                if (weight + peopleWeights[person] > x) {
                    rides++;
                    weight = min(peopleWeights[person], weight);
                }
 
                else weight += peopleWeights[person];
                dp[subset] = min (dp[subset], make_pair(rides, weight));
 
            }
 
        }
    }
 
    cout << dp[(1 << n) - 1].first;
    
}
 
int main(){
	solve();
}