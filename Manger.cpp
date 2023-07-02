include <fstream>
#include <algorithm>

using namespace std;

int g, x1, y1, z1, x2, y2, z2;
int pw3[100], V[100];

inline bool inter(int a, int b, int c, int d) {
    return max(a, c) < min(b, d);
}

int solve(int g, int xa, int ya, int za, int xb, int yb, int zb) {
    if(inter(xa, xb, x1, x2) == 0 || inter(y1, y2, ya, yb) == 0 || inter(z1, z2, za, zb) == 0) {
        return 0;
    }
    if(x1 <= xa && xb <= x2 && y1 <= ya && yb <= y2 && z1 <= za && zb <= z2) {
        return V[g];
    }
    if(g == 0) {
        return 1;
    }
    int ans = 0, l = pw3[g - 1];
    for(int a = 0; a < 3; a++) {
        for(int b = 0; b < 3; b++) {
            for(int c = 0; c < 3; c++) {
                int cnt = (a == 1) + (b == 1) + (c == 1);
                if(cnt >= 2) continue;
                ans += solve(g - 1, xa + l * a, ya + l * b, za + l * c, xa + l * (a + 1), ya + l * (b + 1), za + l * (c + 1));
            }
        }
    }
    return ans;
}

int main() {
    ifstream cin("menger.in");
    ofstream cout("menger.out");
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pw3[0] = 1, V[0] = 1;
    for(i = 1; i <= 10; i++) {
        pw3[i] = pw3[i - 1] * 3;
        V[i] = 20 * V[i - 1];
    }

    cin >> t;
    while(t--) {
        cin >> g >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << solve(g, 0, 0, 0, pw3[g], pw3[g], pw3[g]) << "\n";
    }

    return 0;
}
