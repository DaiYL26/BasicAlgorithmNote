#include<iostream>
#include<string>
using namespace std;
const int N = 100010;
int heap[N],ph[N],hp[N],cnt=0,m=0;

void heap_swap(int a,int b)
{
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(heap[a],heap[b]);
}

void down(int x)
{
	int u = x;
	if(2*x<=cnt && heap[2*x]<heap[u])
		u = 2*x;
	if(2*x+1<=cnt && heap[2*x + 1]< heap[u])
		u = 2*x + 1;
	if(u!=x)
	{
		heap_swap(u,x);
		down(u);
	}
}

void up(int x)
{
	while(x/2 && heap[x/2] > heap[x])
	{
		heap_swap(x/2,x);
		x/=2;
	}
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x,k;
		string op;
		cin>>op;
		if(op=="I")
		{
			cin>>x;
			cnt++,m++;
			heap[cnt] = x;
			hp[cnt] = m;
			ph[m] = cnt;
			up(cnt);
		}
		if(op=="PM")
			cout<<heap[1]<<endl;
		if(op=="DM")
		{
			heap_swap(1,cnt);
			cnt--;
			down(1);
		}
		if(op=="D")
		{
			cin>>k;
			k = ph[k];
			heap_swap(k,cnt);
			cnt--;
			up(k);
			down(k);
		}
		if(op=="C")
		{
			cin>>k>>x;
			k = ph[k];
			heap[k] = x;
			up(k);
			down(k);
		}
	}
}
