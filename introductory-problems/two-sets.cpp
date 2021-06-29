#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void display(vector<ll> &v){
    for(auto i:v) cout << i << " ";
    cout << "\n";
}

int main(){
    ll n;cin >> n;
    if(n%8 == 0 || n%8 == 3 || n%8 == 4 || n%8 == 7){
        cout << "YES" << endl;
        ll h_sum = (n*(n+1))/4,sum=0;
        vector<ll> set1,set2;
        while(n>0){
            if(sum + n <= h_sum){
                set1.push_back(n);
                sum = sum +n;
            }
            else set2.push_back(n);
            n--;
        }
        cout << set1.size() << endl;
        display(set1);
        cout << set2.size() << endl;
        display(set2);
    }
    else cout << "NO" << endl;
}