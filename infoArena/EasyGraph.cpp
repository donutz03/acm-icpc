#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;
ifstream f("easygraph.in");
ofstream g("easygraph.out");
vector<int>v;
vector<vector<int>>ListaAdiacenta;
vector<bool>vizitat;
vector<long long int> suma;
long long int val_max = INT_MIN;

void DFS(int x)
{
    vizitat[x]=true;
    suma[x]=v[x];

    for(auto y : ListaAdiacenta[x])
    {
        if(vizitat[y]==false)
            DFS(y);
        if(suma[x]< v[x]+suma[y])
            suma[x] = v[x]+suma[y];
    }
    if(val_max < suma[x])
        val_max = suma[x];
}
int main()
{
    int T, N, M, x, y;
    f>>T;
    for(int i=0; i<T; i++)
    {
        f>>N>>M;
        v.clear();
        ListaAdiacenta.clear();
        vizitat.clear();
        suma.clear();
        v.resize(N+1);
        ListaAdiacenta.resize(N+1);
        vizitat.resize(N+1, false);
        suma.resize(N+1);
        val_max = INT_MIN;
        for(int j=1; j<=N; j++)
        {
            f>>v[j];
            //v.push_back(x);
        }
        for(int j=0; j<M; j++)
        {
            f>>x>>y;
            //g<<x<<' '<<y<<'\n';
            ListaAdiacenta[x].push_back(y);
        }

        for(int j=1;j<=N;j++)
            if(vizitat[j]==false)
                DFS(j);
        g<<val_max<<'\n';

    }

    return 0;
}
