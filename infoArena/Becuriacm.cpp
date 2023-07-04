#include <bits/stdc++.h>
#define NMAX 505

using namespace std;

ifstream fin("becuriacm.in");
ofstream fout("becuriacm.out");

int K[NMAX];
int A[NMAX][NMAX];
int nec[NMAX];

int main() {
	int t,n,m,l,i,j,bec,where,k,lin,col;
	vector<int> ans;

	fin >> t;
	while(t--) {
		fin>>n>>m>>l;

		memset(A, 0, sizeof(A));

		for(i=1;i<=m;++i) fin >> K[i];

		for(i=1;i<=l;++i) {
			fin>>bec;
			A[bec][m+1] = 1;
		}

		for(i=1;i<=m;++i) {
			for(j=1;j<=K[i];++j) {
				fin>>bec;

				A[bec][i] = 1;
			}
		}

		lin=col=1;

		while(lin<=n && col<=m) {
			where = -1;
			for(k=lin;k<=n;++k) {
				if(A[k][col] == 0) continue;

				where = k;
				break;
			}

			if(where == -1) {
				++col;
				continue;
			}

			for(k=1;k<=m+1;++k)
				swap(A[lin][k], A[where][k]);

			for(i=lin+1;i<=n;++i) {
				if(A[i][col] == 0) continue;

				for(j=1;j<=m+1;++j)
					A[i][j] = (A[i][j] + A[lin][j])%2;
			}

			++lin;
			++col;
		}

		bool ok = 1;

		memset(nec, 0, sizeof(nec));
		for(i=n;i>0 && ok;--i) {
			for(j=1;j<=m+1 && ok;++j)
				if(A[i][j] != 0) break;

			if(j == m+2) continue;
			if(j == m+1) ok = 0;

			nec[j] = A[i][m+1];
			for(k=j+1;k<=m;++k)
				nec[j] = (nec[j]+(A[i][k]&nec[k]))%2;
		}

		if(ok == 0)
			fout << "-1\n";
		else {
			ans.clear();

            for(i=1;i<=m;++i)
                if(nec[i] != 0)
                    ans.push_back(i);

            fout << ans.size() << '\n';
            for(auto it:ans)
                fout << it << ' ';
            fout << '\n';
		}
	}

	return 0;
}
