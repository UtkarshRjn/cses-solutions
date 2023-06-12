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

const ll mod = 1e9 + 7;

ll modularBinaryExponentiation(int base, int exponent){

    if(exponent == 0){
        return 1;
    }
    ll result = modularBinaryExponentiation(base, exponent/2);
    if(exponent%2==1)
        return (((result*result)%mod) *base) %mod;
    else 
        return (result*result)%mod;

}

int main(){
	
    int n;
    cin >> n;
    int totalSum = (n*(n+1))/2;

    if(totalSum % 2){
        cout << 0;
        return 0;
    }

    int setSum = totalSum / 2;
    vector<ll> sumCount(setSum+1);

    sumCount[0] = 1;
    for(int value = 1; value <= n; value++){
        for(int sum = setSum; sum >= value; sum--){
            sumCount[sum] = (sumCount[sum] + sumCount[sum-value])%mod;
        }
    }
    cout << (sumCount[setSum] * modularBinaryExponentiation(2,mod - 2)) %mod << endl;

}