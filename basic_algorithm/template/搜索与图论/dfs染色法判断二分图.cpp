#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;

int n,m;
int e[N],h[N],ne[N],idx;
int color[N];

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool dfs(int u,int c)
{
	color[u] = c;
	
	for(int i = h[u]; i!=-1 ; i = ne[i])
	{
		int j = e[i];
		if(!color[j])
		{
			if(!dfs(j,~c))	return false;
		}
		if(color[j]==c)
			return false;
	}
	
	return true;
}


int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	
	bool flag = true;
	for(int i=1;i<=n;i++)
	{
		if(!color[i])
		{
			if(!dfs(i,1))
			{
				flag = false;
				break;
			}
		}
	}
	
	if(flag)	puts("Yes");
	else	puts("No");
} 
