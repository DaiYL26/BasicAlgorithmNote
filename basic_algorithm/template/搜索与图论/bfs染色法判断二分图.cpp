#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 2e5 + 10;

int n,m;
int h[N],e[N],ne[N],idx;
int color[N];

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool bfs(int u,int c)
{
    queue<int> q;
    q.push(u);
    color[u] = c;

    while(q.size())
    {
        int t = q.front();
        q.pop();

        for(int i = h[t]; ~ i ;i = ne[i])
        {
            int j = e[i];
            if(!color[j])
            {
                color[j] = ~color[t];
                q.push(j);  
            }
            else if(color[j] == color[t])
                return false;
        }       
    }
    return true;
}

int main()
{
    cin>>n>>m;

    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }

    for(int i = 1;i<=n;i++)
    {
        if(!color[i])
            if(!bfs(i,1))
            {
                puts("No");
                return 0;
            }
    }

    puts("Yes");        
    return 0;
}
