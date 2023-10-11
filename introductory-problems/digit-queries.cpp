#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
     
    ll q; cin >> q;

    while(q--){
        ll k; cin >> k;
        if(k <= 9){
            cout << k << endl;
            continue;
        }
        ll temp = 0;
        ll sum = 0;
        int i;
        for(i=1; temp<k; i++){
            sum = temp;
            temp += (powl(10,i) - powl(10,i-1))*i;
        }

        i-=2;
        ll divisor = i+1;
        ll dividend = k - sum;

        dividend--;

        ll q = dividend / divisor;
        ll r = dividend % divisor;

        ll num = powl(10,i) + q;

        string s = to_string(num);

        cout << s[r] << endl;

    }    

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;

}