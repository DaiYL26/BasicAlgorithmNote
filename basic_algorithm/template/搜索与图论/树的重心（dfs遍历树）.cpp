#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010,M = 2*N;

int val[M],h[N],ne[M],idx;
int n,ans = N;
bool st[N];

void add(int a,int b) //邻接表 
{
	val[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int x)
{
	st[x] = 1;	//标记已遍历过 
	
	int sum = 1,res = 0;
	for(int i=h[x];i!=-1;i = ne[i])
	{
		int j = val[i];
		if(!st[j])
		{
			int t = dfs(j); // 子树节点数 
			res = max(res,t); //最大子树节点数 
			sum += t; //已该点为根节点的树的节点数 
		}
	}
	
	res = max(res,n-sum);
	ans = min(ans,res);	
	return sum;
}

int main()
{
	memset(h,-1,sizeof(h));
	cin>>n; 
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	
	dfs(1);
	
	cout<<ans;
} 
