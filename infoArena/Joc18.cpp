#include <bits/stdc++.h>
using namespace std;

string solve(vector<int>& v)
{
	int n = v.size(), cnt = 0;
	
	for(int i = 0;i < n;++i)
		if(v[i] > 1)
			++cnt;
	if(!cnt)
		return "Aurel";
	if(cnt < (int) v.size())
		return "Bianca";
	vector<int> tmp;
	for(size_t i = 0;i < v.size();++i)
	{
		int pw = 0, nr = v[i];
		
		for(int j = 2;j * j <= nr && nr > 1;++j)
		{
			while(nr % j == 0)
			{
				++pw;
				nr /= j;
			}
		}
		if(nr == 1)
			--pw;
		tmp.push_back(pw);
	}
	for(int i = 0;i < 20;++i)
	{
		int sum = 0;
		for(size_t j = 0;j < tmp.size();++j)
			sum = (sum + (tmp[j] & (1 << i))) % n;
		if(sum)
			return "Bianca";
	}
	return "Aurel";
}

int main() {
	freopen("joc18.in", "r", stdin);
	freopen("joc18.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;++i)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int j = 0;j < n;++j)
			cin >> v[j];
		cout << solve(v) << "\n";
	}
}
