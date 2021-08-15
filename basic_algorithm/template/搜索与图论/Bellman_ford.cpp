#include<iostream>
#include<string.h>
using namespace std;
const int N = 1e4 + 10,M = 5e5 + 10;

int n,m,s;
int dist[N],backup[N];

struct Edge{
	int a,b,w;
}edge[M];

void bellman_ford(int s)
{
    int num = -(1<<31 | 1);
	for(int i=1;i<=n;i++)
        dist[i] = num;
	dist[s] = 0;
	
	for(int i=0;i<n-1;i++)
	{
		//memcpy(backup,dist,sizeof dist);
		for(int j=1;j<=m;j++)
		{
			int a = edge[j].a,b = edge[j].b,w = edge[j].w;
			if(dist[b] > dist[a] + w)
				dist[b] = dist[a] + w;
		}
	}
	
	/*if(dist[n] == 0x3f3f3f3f )	return -1;
	else	return dist[n];*/
}

int main()
{
	cin>>n>>m>>s;
	
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edge[i] = {a,b,w};
	}
	
	bellman_ford(s);
	
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
} 
