#include <bits/stdc++.h>
#define int long long
#define sqr(x) ((x) * (x))

using namespace std;

ifstream fin("progresie.in");
ofstream fout("progresie.out");

void min_self(int &a, int b) {
  a = min(a, b);
}

void test_case() {
  int n, r;
  fin >> n >> r;
  for (int i = 1; ; ++i) {
    int V = i * (i - 1) + 1, rem = i - 1; 
    bool ok = true;
    for (int j = 1; j < n && ok; ++j) {
      int val = V + j * r;
      int block = sqrt(val - 1) + 1; 
      int start_block = block * (block - 1) + 1, end_block = sqr(block); 
      if (val < start_block) { 
        V += start_block - val; 
        rem -= start_block - val; 
        val = start_block; 
      } else min_self(rem, end_block - val); 
      if (val + rem < start_block) 
        ok = false;
    }
    if (ok) { /// am gasit solutia
      fout << V << '\n';
      return;
    }
  }
}

void solve() {
  int T;
  fin >> T;
  for (int tc = 0; tc < T; ++tc)
    test_case();
}

void close_files() {
  fin.close();
  fout.close();
}

int32_t main() {
  solve();
  close_files();
  return 0;
}
