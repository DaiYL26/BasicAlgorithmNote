#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 510;
int n,m;
bool st[N];
int g[N][N];//�ڽӾ��� 
int dist[N];// 1 �� N �ľ��� 

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	for(int i=0;i<n;i++)
	{
		int t = -1;
		for(int j=1;j<=n;j++)
		{
			if(!st[j] && (t == -1 ||dist[t] > dist[j]))
				t = j; //���������ĵ� 
		}
		
		st[t] = true;
		
		for(int j=1;j<=n;j++) //���µ�ǰ���· (ÿ�α�֤�뼯��st��ĵ���ͨ�����) 
			dist[j] = min(dist[j],dist[t] + g[t][j]);
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin>>n>>m;
	
	memset(g,0x3f,sizeof g);
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = min(g[a][b],c);
	} 
	
	int t = dijkstra();
	
	cout<<t;
} 
