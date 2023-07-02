#include <bits/stdc++.h>
#define mod 9907
using namespace std;
fstream f1("abcacm.in", ios::in);
fstream f2("abcacm.out", ios::out);
int nrt;
long long a, b, c, poz, rez[5][5], aa[5][5];
void inm(long long a[5][5], long long b[5][5])
{
    long long r[5][5];
    int i, j, k;
    for(i=1; i<=3; i++)
        for(j=1;j<=3; j++)
    {
        r[i][j]=0;
        for(k=1; k<=3; k++)
        {
            r[i][j]+=(a[i][k]*b[k][j])%mod;
            r[i][j]%=mod;
        }
    }
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
            a[i][j]=r[i][j];
}
void ridica(long long b)
{
    rez[1][1]=1; rez[1][2]=0; rez[1][3]=0;
    rez[2][1]=0; rez[2][2]=1; rez[2][3]=0;
    rez[3][1]=0; rez[3][2]=0; rez[3][3]=1;
    while(b!=0)
    {
        if(b%2) inm(rez, aa);
        b/=2;
        inm(aa, aa);
    }
}
int main()
{
    f1>>nrt;
    while(nrt--)
    {
        f1>>a>>b>>c>>poz;
        aa[1][1]=b; aa[1][2]=1; aa[1][3]=0;
        aa[2][1]=a; aa[2][2]=0; aa[2][3]=0;
        aa[3][1]=c; aa[3][2]=0; aa[3][3]=1;
        if((poz==1)||(poz==2)) f2<<0<<"\n";
        else
        {
        ridica(poz-2);
        f2<<rez[3][1]<<"\n";
        }
    }
    return 0;
}
