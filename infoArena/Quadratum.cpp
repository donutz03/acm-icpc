#include <bits/stdc++.h>
using namespace std;

__int128 solve(__int128 n)
{
	return (n * (n + 1) * (2 * n + 1)) / 6;
}

void print(__int128 n)
{
	if(!n)
		return;
	print(n / 10);
	cout << (int) (n % 10);
}

int main() {
	freopen("quadratum.in", "r", stdin);
	freopen("quadratum.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;++i)
	{
		uint64_t nr;
		cin >> nr;
		print(solve(nr));
		cout << "\n";
	}
}
