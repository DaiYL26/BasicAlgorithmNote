#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;

int p[N];

struct Edge{
	int a,b,w;
	bool operator < (Edge & q)
	{
		return w < q.w;
	}
};

int find(int x)
{
	if(p[x]!=x)	p[x] = find(p[x]);
	return p[x];
}

int main()
{
	Edge edges[N];
	int n,m,cnt=0,res=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[i] = {a,b,w};
	}
	
	sort(edges,edges + m);
	
	for(int i=1;i<=m;i++)
		p[i] = i;
	
	for(int i=0;i<m;i++)
	{
		int a = edges[i].a,b = edges[i].b,w = edges[i].w;
		int pa = find(a),pb = find(b);
		if(pa!=pb)
		{
			p[pa] = pb;
			res += w;
			cnt++;
		}
	}
	
	if(cnt!=n-1) puts("impossible");
	else	cout<<res;
}
