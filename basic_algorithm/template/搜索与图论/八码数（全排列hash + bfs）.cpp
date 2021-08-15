#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<queue>
#include<unordered_map>
using namespace std;

int fact[10];
bool st[500000];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct MP{
	int x,y,k;
	char str[10];
	void set()  { x = k/3,y = k%3; } //一维坐标转化成二维 
	void setk() { k = x*3 + y; } //二维坐标转化成一维 
};
typedef pair<MP,int> PII;
int permutation_hash(char str[]) //全排列哈希 
{
	int hash_val = 0;
	for(int i = 0;i<9;i++)
	{
		int cnt = 0;
		for(int j = 0;j<i;j++)
			if(str[j] > str[i]) //逆序对判断 
				cnt++;
		hash_val += cnt * fact[i]; //全排列哈希处理 
	}
	return hash_val;
}
 
int bfs(PII start)
{
	queue<PII> q;
	q.push(start);
	st[permutation_hash(start.first.str)] = 1;
	int ans_hash = permutation_hash("12345678x"); //答案哈希值
	char s[10]; //临时地图 
	while(q.size())
	{
		auto t = q.front();
		int pre_step = t.second, step;
		MP p = t.first;
		
		strcpy(s,t.first.str); //拷贝地图 
		q.pop();				
	
		for(int i=0;i<4;i++)
		{
			int xx = t.first.x + dx[i];
			int yy = t.first.y + dy[i];
			if(xx>=0 && xx<3 && yy>=0 && yy<3) //判断越界 
			{
				p.x = xx,p.y = yy,p.setk(); //处理 p 结构体 
				swap(s[p.k],s[t.first.k]); //处理移动后的地图 
				int key = permutation_hash(s);	//处理移动后的哈希值 
				if(!st[key])	//没有尝试过 
				{
					step = pre_step + 1; //当前步数 
					if(key == ans_hash)	return step;
					st[key] = true;
					strcpy(p.str,s); //更新地图			
					q.push({p,step});
				}
				swap(s[p.k],s[t.first.k]); //还原地图 
			}
		}
	}
	return -1;
}

int main()
{
	MP start;
	fact[0] = 1;
	for(int i=1;i<=9;i++)	fact[i] = fact[i-1] * i; //预处理阶乘值 
	
	for(int i=0;i<9;i++)
	{
		cin>>start.str[i];
		if(start.str[i] == 'x')	start.k =  i;
	}
	start.str[9] = '\0';
	start.set();
	
	int t = bfs({start,0});
	cout<<t<<endl;
} 
