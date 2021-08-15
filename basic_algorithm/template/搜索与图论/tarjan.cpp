#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;
int n,m,mod;
int h[N],hs[N],e[M],ne[M],idx;
int stk[N],top,id[N],f[N],g[N];
bool in_stk[N];
int dfn[N],low[N],scc_size[N],scc_cnt,timestamp;

typedef long long LL;

void add(int a,int b,int h[])
{
	e[idx] = b, ne[idx] = h[a] , h[a] = idx++;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u,in_stk[u] = true;
	
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u],low[j]);
		}
		else if(in_stk[j])	low[u] = min(low[u],dfn[j]);
	}
	
	if(dfn[u] == low[u])
	{
		++ scc_cnt;
		int y;
		do
		{
			y = stk[top --];
			in_stk[y] = false;
			scc_size[scc_cnt] ++;
			id[y] = scc_cnt;
		} while(y != u);
	}
}

int main()
{
	cin >> n >> m >> mod;
	
	memset(h,-1,sizeof h);
	memset(hs,-1,sizeof hs);
	
	for(int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		add(a,b,h);
	}
	
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);
	
	unordered_set<LL> S;
	
	for(int u = 1; u <= n; u++)
		for(int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			int a = id[u] , b = id[j];
			LL hash = a * 1000000ll + b;
			if(a != b && !S.count(hash))
			{
				add(a,b,hs);
				S.insert(hash);
			}
		}
	
	for(int i = scc_cnt; i; i--)
	{
		if(!f[i])
		{
			f[i] = scc_size[i];
			g[i] = 1;
		}
	}
	
	for(int i = scc_cnt; i; i--)
		for(int j = h[i]; j != -1; j = ne[j])
		{
			int k = e[j];
			if(f[i] + scc_size[k] > f[k])
			{
				f[k] = f[i] + scc_size[k];
				g[k] = g[i];
			}
			else if(f[i] + scc_size[k] == f[k])
			{
				g[k] = (g[k] + g[i]) % mod;
			}
		}
	
	int maxf = 0,sum = 0;
	for(int i = 1; i <= scc_cnt; i++)
		if(maxf < f[i])	maxf = f[i];
	
	for(int i = 1; i <= scc_cnt; i++)
		if(f[i] == maxf)	sum = (sum + g[i]) % mod;
	
	cout << maxf << endl;
	cout << sum << endl;
	
	return 0;
}
