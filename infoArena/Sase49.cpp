#include <bits/stdc++.h>
using namespace std;
ifstream in("sase49.in");
ofstream out("sase49.out");
int f[20];
int tst,x;
void solve()
{
    for(int d=16;d>=1;--d)
    {
        int cnt=0;
        for(int i=d;i<=16;i+=d)
            cnt+=f[i];
        if(cnt>=6)
        {
            int ind=d;
            out<<d<<'\n';
            for(int i=1;i<=6;++i)
            {
                while(f[ind]==0)
                    ind+=d;
                --f[ind];
                out<<ind<<' ';
            }
            out<<'\n';
            return ;
        }
    }
}
int main()
{
    in>>tst;
    while(tst--)
    {
        for(int i=1;i<=16;++i)
            f[i]=0;
        for(int i=1;i<=49;++i)
            in>>x,f[x]++;
        solve();
    }
    return 0;
}
