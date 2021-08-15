#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
int n,m;
int h[N],val[N],ne[N],idx;
int d[N],q[N],head,rear = -1;

int add(int a,int b)
{
	val[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool topsort()
{
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
			q[++rear] = i;
	}
	
	while(head<=rear)
	{
		int t = q[head++];
		for(int i=h[t];i!=-1;i=ne[i]) //ö�����еĵ� 
		{
			int j = val[i];
			if(--d[j] == 0) //ֱ�����Ϊ0˵����j�ĵ��ѳ����� 
				q[++rear] = j;
		}
	}
	return rear == n-1; //���е㶼������ 
}

int main()
{
    memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		d[b]++; //��� 
	}
	
	if(!topsort())
		puts("-1");
	else
		for(int i=0;i<n;i++)
			cout<<q[i]<<' ';
} 
