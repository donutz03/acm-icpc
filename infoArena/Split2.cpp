#include <iostream>
#include <fstream>
#include <limits.h>
#define mod 1000000007
using namespace std;
ifstream f("split2.in");
ofstream g("split2.out");

int fact[1000001],lastFact=1;

void solve(){
    int n,m,a[1001],b[1001]={0},dp[1001];
    f>>n>>m;
    int maxx=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
        b[i]=b[i-1]+a[i];
        if(a[i]>maxx)
            maxx = a[i];
    }
    int st = maxx;
    int dr = b[n];
    
    while(st < dr ){
        
        int mij = (st+dr)/2;
        for(int i=1;i<=n;i++){
            dp[i] = mod;
        }
        for(int i=2;i<=n;i=i+2){
            for(int j=i;j<=n;j=j+2){
                if((b[j]-b[j/2 + i/2 - 1])<=mij && (b[j/2 + i/2 - 1] - b[i-2]) <= mij){
                    dp[j] = min(dp[j],dp[i-2]+1);
                }else j=n+1;
                
            }
        }
       
        if(dp[n]<=m){
            dr = mij;
        }else{
            st = mij+1;
        }
        
    }
    g<<dr<<endl;
    
    
}


int main()
{   
    int t;
    f>>t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}
