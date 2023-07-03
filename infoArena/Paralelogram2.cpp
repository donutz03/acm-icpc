#include <cstdio>
struct pt
{
    int x, y;
};
pt A[6];
int tests;

int main()
{
    freopen("paralelogram2.in", "r", stdin);
    freopen("paralelogram2.out", "w", stdout);

    scanf("%d", &tests);
    while (tests--)
    {
        for (int i = 1; i <= 4; i++)
            scanf("%d%d", &A[i].x, &A[i].y);
        A[5] = A[1];
        for (int i = 1; i <= 4; i++)
            printf("%lf %lf ", ((double)A[i].x + A[i + 1].x) / 2, ((double)A[i].y + A[i + 1].y) / 2);
        printf("\n");
    }
    return 0;
}
