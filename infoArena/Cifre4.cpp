#include <bits/stdc++.h>
#define INF (1LL << 40)
using namespace std;
ifstream fin("cifre4.in");
ofstream fout("cifre4.out");

int n, r, imp;
long long ans;

void solve(long long x){
  if (x > ans)
    return;
  if (x % imp == r)
    ans = x;
  solve(x * 10 + 2);
  solve(x * 10 + 3);
  solve(x * 10 + 5);
  solve(x * 10 + 7);
}

int main(){
  fin >> n;
  for (int i = 0; i < n; i++){
    fin >> r >> imp;
    ans = INF;
    solve(0LL);
    if (ans == INF)
      ans = -1;
    fout << ans << "\n";
  }
  return 0;
}
