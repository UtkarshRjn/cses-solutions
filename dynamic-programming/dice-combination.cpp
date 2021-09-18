#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fac = 1e9 + 7;

void findWays(ll N)
{
	ll dp[N + 1];

	dp[0] = 1;

	for (ll i = 1; i <= N; i++) {

		dp[i] = 0;

		for (int j = 1; j <= 6; j++) {

			if (i - j >= 0) {
				dp[i] = (dp[i])%fac + (dp[i - j])%fac;
			}
		}
	}

	cout << (dp[N])%fac << endl;
}

int main()
{
	ll N; cin >> N;

	findWays(N);

	return 0;
}
