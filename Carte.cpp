#include <bits/stdc++.h>
#define LMAX 3002
#define P 101
#define Q 103

using namespace std;

char str[LMAX];
char dict[LMAX];
vector <short int> v[LMAX];
short int dp[LMAX];

void Rabin_Karp() {

	int l_dict = strlen(dict);
	int l_str = strlen(str);

	if (l_dict > l_str)
		return;

	int hash1_dict = 0, hash2_dict = 0;
	for (register int i = 0; i < l_dict; ++i)
		hash1_dict = hash1_dict * P + dict[i], hash2_dict = hash2_dict * Q + dict[i];

	int hash1_str = 0, hash2_str = 0;
	for (register int i = 0; i < l_dict; ++i)
		hash1_str = hash1_str * P + str[i], hash2_str = hash2_str * Q + str[i];

	int val1 = 1, val2 = 1;
	for (register int i = 1; i < l_dict; ++i)
		val1 = val1 * P, val2 = val2 * Q;

	for (register int i = l_dict; i < l_str; ++i) {

		if (hash1_dict == hash1_str && hash2_dict == hash2_str)
			v[i - 1].push_back(l_dict);

		hash1_str = (hash1_str - val1 * str[i - l_dict]) * P + str[i];
		hash2_str = (hash2_str - val2 * str[i - l_dict]) * Q + str[i];
	}

	if (hash1_dict == hash1_str && hash2_dict == hash2_str)
		v[l_str - 1].push_back(l_dict);
}

int main() {

    freopen("carte.in", "r", stdin);
    freopen("carte.out", "w", stdout);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {

		int n, l;
		cin >> str >> n;

		l = strlen(str);

		for (register int i = 0; i < n; ++i) {

			cin >> dict;
			Rabin_Karp();
		}
		
		dp[0] = 0;
		for (register int i = 1; i <= l; ++i) {

			dp[i] = dp[i - 1] + 1;
			for (int step : v[i - 1])
				dp[i] = min(dp[i], dp[i - step]);
		}

		cout << dp[l] << '\n';

		for (int i = 0; i < l; ++i)
			v[i].clear();
	}

	return 0;
}
