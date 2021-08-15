#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
queue<int> q;
int n,m;
bool vis[N];
int val[N],ne[N],h[N],p[N],idx=0;

void add(int a,int b) //�ڽӱ� 
{
	val[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int bfs()
{
	memset(p,-1,sizeof(p));
	q.push(1);	//��ͷ��ʼ 
	vis[1] = 1,p[1] = 0;
	
	while(q.size())
	{
		int t = q.front(); //ȡ������ 
		q.pop();
		for(int i=h[t];i!=-1;i = ne[i]) //�����ڽӱ� 
		{
			int j = val[i];
			if(!vis[j])
			{
				q.push(j); //ѹ�� 
				vis[j] = 1;
				p[j] = p[t] + 1; //�����ߵ�j�Ĳ��� 
			}
		}
	}
	
	return p[n];
}

int main()
{
	memset(h,-1,sizeof(h));
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	cout<<bfs();
}
