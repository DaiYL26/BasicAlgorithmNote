#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 510,M = 1e5 + 10;

int h[N],e[M],ne[M],idx;
int n1,n2,m;
bool st[N];
int match[N]; //存妹子（n2）成功匹配对象

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool find(int u)
{
	for(int i=h[u]; ~i ;i = ne[i]) //扫描n1的每个对象（妹子）
	{
		int j = e[i];
		if(!st[j]) //没扫过且两者能匹配（有好感）
		{
			st[j] = true; //标记一下，这不标记对后面的 n1 抢前面的对象十分重要
			if(match[j] == 0 || find(match[j])) //n2没对象（妹子没对象）或者 
			{									//妹子的对象有备胎（妹子发现后抛弃原对象和 u 匹配了）
				match[j] = u; //将妹子 j 的对象置成 u
 				return true; //该点 u 匹配成功
			}
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	for(int i=1;i<=n1;i++)
	{
		memset(st,0,sizeof st); //这步给了n1里后面的兄弟挖墙脚的勇气~~
		if(find(i))	res ++; // 匹配到一对~~ 最大匹配res ++
	}
	return res;
}

int main()
{
	cin>>n1>>n2>>m;
	
	memset(h,-1,sizeof h);
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	cout<<hungary();
}
