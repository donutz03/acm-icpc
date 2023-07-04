#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

ifstream cin("triangulare.in");
ofstream cout("triangulare.out");

const int MAXN = 50;

struct Point {
    int x;
    int y;

    Point(const int _x = 0, const int _y = 0):
        x(_x),
        y(_y) {}

    bool operator == (const Point &other) const {
        return x == other.x && y == other.y;
    }
};

int Determinant(const Point &a, const Point &b, const Point &c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
}

struct Segment {
    Point a;
    Point b;

    Segment(const Point _a, const Point _b):
        a(_a),
        b(_b) {
            if (a.y > b.y)
                swap(a, b);
        }
};

bool Common(int x1, int x2, int y1, int y2) {
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x1 > y1) {
        swap(x1, y1);
        swap(x2, y2);
    }
    return y1 < x2;
}

bool Intersection(const Segment &p, const Segment &q) {
    if (p.a == p.b || q.a == q.b)
        return false;
    if (!Determinant(p.a, p.b, q.a) && !Determinant(p.a, p.b, q.b)) {
        if (Common(p.a.x, p.b.x, q.a.x, q.b.x))
            return true;
        if (Common(p.a.y, p.b.y, q.a.y, q.b.y))
            return false;
        return false;
    }
    return (1LL * Determinant(p.a, p.b, q.a) * Determinant(p.a, p.b, q.b) < 0 && 1LL * Determinant(q.a, q.b, p.a) * Determinant(q.a, q.b, p.b) < 0);
}

Point v[MAXN];

bool Inside(int n, const Point &p) {
    bool ok = false;
    for (int i = 0; i < n; i++) {
        Segment s = Segment(v[i], v[(i + 1) % n]);
        if (s.a.y < p.y && p.y <= s.b.y && Determinant(s.a, s.b, p) < 0)
            ok ^= 1;
    }
    return ok;
}

vector<pair<int, int> > triangulation;

bool Check(int n, const Segment &s) {
    for (int i = 0; i < n; i++)
        if (Intersection(Segment(v[i], v[(i + 1) % n]), s))
            return false;
    for (auto &t : triangulation)
        if (Intersection(Segment(v[t.first], v[t.second]), s))
            return false;
    return Inside(n, Point((s.a.x + s.b.x) / 2, (s.a.y + s.b.y) / 2));
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
            v[i].x *= 2;
            v[i].y *= 2;
        }
        triangulation.clear();
        for (int i = 0; i < n; i++)
            for (int j = (i + 2) % n; i != (j + 1) % n; j = (j + 1) % n)
                if (Check(n, Segment(v[i], v[j])))
                    triangulation.push_back(make_pair(i, j));
        sort(triangulation.begin(), triangulation.end());
        for (auto &it : triangulation)
            cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
