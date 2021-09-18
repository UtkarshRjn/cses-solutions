#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int C = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll fact(ll n);
 
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n- r));
}

// Returns factorial of n
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}



ll binarySearch(ll arr[], ll l, ll r, ll x)
{

    if (r >= l) {

        ll mid = l + (r - l) / 2;

        if (arr[mid] == x){
            return mid;
            }

        if (arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return r;
}

int main(){
    ll T;cin >> T;
    for(ll i=0;i<T;i++){
        ll N,Q;cin >> N >> Q;
        ll a[N];
        ll arr[N][2];
        ll odd = 0,even = 0;
        for(ll i=0;i<N;i++){
            cin >> a[i];
            if(abs(a[i])%2==0) even++;
            else odd++;
            arr[i][1] = even;
            arr[i][0] = odd;
        }
        sort(a , a + N);
        
        for(ll i=0;i<Q;i++){
            ll L,R;cin >> L >> R;
            ll s1 = binarySearch(a, 0, N-1, L);
            // cout << s1 << endl;
            ll s2 = binarySearch(a, 0, N-1, R);
            // cout << s2 << endl;
            ll ans_odd,ans_even;
            

            if(s1 == 0){
                ans_odd = arr[s2][0];
                ans_even = arr[s2][1];              
            }
            else{
                if(a[s1] == L){
                    ans_odd = arr[s2][0] - arr[s1-1][0];
                    ans_even = arr[s2][1] - arr[s1-1][1];
                }
                else{
                    ans_odd = arr[s2][0] - arr[s1][0];
                    ans_even = arr[s2][1] - arr[s1][1];
                }
            }
            // cout << ans_even << "=even " << ans_odd << "=odd" << endl;
            if(s1==s2) cout << 0 << endl;
            else{
                if(ans_even >=3  && ans_odd >= 2){
                    cout << ans_even * (ans_odd * (ans_odd-1)) / 2 + (ans_even * (ans_even-1) * (ans_even -2))/6 << endl;
                }
                else if(ans_even >= 3 && ans_odd <2){
                    cout <<(ans_even * (ans_even-1) * (ans_even -2))/6<< endl;
                }
                else if(ans_even >=1 && ans_even < 3 && ans_odd>=2){
                    cout << ans_even * (ans_odd * (ans_odd-1)) / 2 << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }
        }
    }
}

