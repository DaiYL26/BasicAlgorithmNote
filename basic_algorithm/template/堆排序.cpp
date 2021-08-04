#include<iostream>
using namespace std;

const int N = 1e5+5;
int heap[N],Size;

void down(int u)
{
	int t = u;
	if(2*t <= Size && heap[2*t] < heap[u] )
		u = 2*t;
	if(2*t + 1 <=Size && heap[2*t + 1] < heap[u] )
		u = 2*t + 1;
	if(u!=t)
	{
		swap(heap[u],heap[t]);
		down(u);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>heap[i];
	Size = n;
	
	for(int i = n/2; i ;i--)
		down(i);
	
	while(m--)
	{
		cout<<heap[1]<<' ';
		heap[1] = heap[Size--];
		down(1);
	}
	cout<<endl;
	
} 
