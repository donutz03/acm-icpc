#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("popcnt")

using namespace std;

ifstream fin  ("frumusete.in");
ofstream fout ("frumusete.out");

const int MOD = 666013;
const int MAX_N = 1'000;
string s;
int n, k, f, sol;
int dp[MAX_N + 5][MAX_N + 5][2];


int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i=1; i < 1000; i++)
        for(int j=0; j < i; j++){
            dp[i+1][j  ][0] += dp[i][j][0], dp[i+1][j  ][0] %= MOD;
            dp[i+1][j  ][1] += dp[i][j][0], dp[i+1][j  ][1] %= MOD;
            dp[i+1][j  ][0] += dp[i][j][1], dp[i+1][j  ][0] %= MOD;
            dp[i+1][j+1][1] += dp[i][j][1], dp[i+1][j+1][1] %= MOD;
        }

    int teste;
    fin>>teste;
    while(teste--){
        fin>>k>>s;
        n = (int)s.size();

        sol = f = 0;
        for(int i=0; i < n; i++){
            if(s[i] == '1'){
                if(k >= f)
                    sol += dp[n - i][k - f][0], sol %= MOD;

                if(i != 0 && s[i-1] == '1')
                    f++;
            }
        }
        if(f == k)
            sol++, sol %= MOD;

        fout<<sol<<"\n";
    }
    return 0;
}
