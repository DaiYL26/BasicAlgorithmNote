#include<iostream>
#include<string.h>
using namespace std;
const int N = 510,M = 1e4 + 10;

int n,m,k;
int dist[N],backup[N];

struct Edge{
	int a,b,w;
}edge[M];

int bellman_ford()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	for(int i=0;i<k;i++)
	{
		memcpy(backup,dist,sizeof dist);
		for(int j=1;j<=m;j++)
		{
			int a = edge[j].a,b = edge[j].b,w = edge[j].w;
			if(dist[b] > backup[a] + w)
				dist[b] = backup[a] + w;
		}
	}
	
	if(dist[n] > 0x3f3f3f3f / 2 )	return -1;
	else	return dist[n];
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edge[i] = {a,b,w};
	}
	
	int t = bellman_ford();
	
	if(t==-1)	puts("impossible");
	else	cout<<t;
} 
