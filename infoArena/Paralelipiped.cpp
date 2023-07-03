#include <bits/stdc++.h>
#define ll long long

using namespace std;

short sp[2 * 75 + 1][2 * 75 + 1][2 * 75 + 1];

int main() {
	ifstream cin("paralelipiped.in");
	ofstream cout("paralelipiped.out");
	int t, i, j;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {	

		int n;
		cin >> n;

		vector <int> x[2], y[2], z[2];
		for(i = 0; i < 2; i++) {
			x[i].resize(n), y[i].resize(n), z[i].resize(n);
		}

		vector <int> nrmx, nrmy, nrmz;
		for(i = 0; i < n; i++) {
			for(j = 0; j < 2; j++) {
				cin >> x[j][i] >> y[j][i] >> z[j][i];
				nrmx.push_back(x[j][i]);
				nrmy.push_back(y[j][i]);
				nrmz.push_back(z[j][i]);
			}
		}
		
		auto norm = [&](vector <int> &nrm, map <int, int> &mp, vector <int> &vals) {
			sort(nrm.begin(), nrm.end());
			int last = -1e9, val = 0;
			for(auto it : nrm) {
				val += (last != it);
				mp[it] = val;
				vals[val] = it;
				last = it;
			}
		};
		
		vector <int> valsx(2 * n + 1), valsy(2 * n + 1), valsz(2 * n + 1);
		map <int, int> mpx, mpy, mpz;
		norm(nrmx, mpx, valsx);
		norm(nrmy, mpy, valsy);
		norm(nrmz, mpz, valsz);

		for(int a = 0; a <= 2 * n; a++) {
			for(int b = 0; b <= 2 * n; b++) {
				for(int c = 0; c <= 2 * n; c++) {
					sp[a][b][c] = 0;
				}
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < 2; j++) {
				x[j][i] = mpx[x[j][i]];
				y[j][i] = mpy[y[j][i]];
				z[j][i] = mpz[z[j][i]];
			}
			for(int conf = 0; conf < (1 << 3); conf++) {
				int a = (conf >> 2), b = ((conf >> 1) & 1), c = (conf & 1);
				int sgn = 1;
				if(__builtin_popcount(conf) & 1) sgn = -1;
				sp[x[a][i]][y[b][i]][z[c][i]] += sgn;
			}
		}

		ll ans = 0;
		for(int a = 1; a < 2 * n; a++) {
			for(int b = 1; b < 2 * n; b++) {
				for(int c = 1; c < 2 * n; c++) {
					sp[a][b][c] += sp[a - 1][b][c] + sp[a][b - 1][c] + sp[a][b][c - 1] - sp[a - 1][b - 1][c] - sp[a][b - 1][c - 1] - sp[a - 1][b][c - 1] + sp[a - 1][b - 1][c - 1];
					ans += 1LL * (sp[a][b][c] > 0) * (valsx[a + 1] - valsx[a]) * (valsy[b + 1] - valsy[b]) * (valsz[c + 1] - valsz[c]);
				}
			}
		}
		cout << ans << "\n";
	}
		
	return 0;
}
