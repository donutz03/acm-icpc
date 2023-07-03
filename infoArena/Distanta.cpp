#include <bits/stdc++.h>

using namespace std;

ifstream fin("distanta.in");
ofstream fout("distanta.out");

void solve() {

	int a, b, x, y;
	fin >> a >> b >> x >> y;

	fout << setprecision(8) << fixed;
	if (a == 0)
		fout << abs(y - (long double)1 / b) << '\n';
	else if (b == 0)
		fout << abs(x - (long double)1 / a) << '\n';
	else
		fout << min(abs(y - (long double)1 / b + (long double)a * x / b), abs(x - (long double)1 / a + (long double)b * y / a)) << '\n';
}
 
int main() {
 
	int t = 1;
	fin >> t;
 
	for(register int test = 1; test <= t; ++test)
		solve();
	return 0;
}
