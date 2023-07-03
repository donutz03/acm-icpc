#include<cstdio>
const int NMAX=1<<20;
const long long int MOD=1000000007;

long long int f[NMAX];

long long int fastExp(long long int x, long long int y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x;
	long long int a=fastExp(x, y>>1);
	a=a*a%MOD;
	if(y&1)
		a=a*x%MOD;
	return a;
}

void precalc()
{
	int i;

	f[0]=1;
	for(i=1;i<NMAX;++i)
		f[i]=f[i-1]*i%MOD;
}

int get(long long int N, int K)
{
	return fastExp(f[K], N/K+1)*fastExp(f[K-N%K], MOD-2)%MOD;
}

int main()
{
	FILE* f=fopen("cabana.in", "r"), *g=fopen("cabana.out", "w");
	//FILE* f=stdin, *g=stdout;
	int i, K;
	long long int N;

	precalc();
	fscanf(f, "%d", &i);
	do
	{
		fscanf(f, "%lld%d", &N, &K);
		fprintf(g, "%d\n", get(N, K));
	}while(--i);

	fclose(f);
	fclose(g);
	return 0;
}
