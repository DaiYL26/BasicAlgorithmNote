#include<iostream>
#include<string>
using namespace std;

const int N = 1e6 + 5;

int a[N],q[N];
int head = 0,rear = -1;

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
        
		if(head<=rear && i - k +1 > q[head])
			head++;
		while(head<=rear && a[q[rear]]>=a[i])
			rear--;
		q[++rear] = i;
		if(i >= k-1)
			cout<<a[q[head]]<<' ';
	}
	cout<<endl;
	head = 0,rear = -1;
	for(int i=0;i<n;i++)
	{
        
		if(head<=rear && i - k +1 > q[head])
			head++;
		while(head<=rear && a[q[rear]]<=a[i])
			rear--;
		q[++rear] = i;
		if(i >= k-1)
			cout<<a[q[head]]<<' ';
	}
} 
