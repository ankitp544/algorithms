#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define pii pair<int,int>
#define S second
#define INF 100
vector<pii> g[100];
void bell(int h[],int n)
{
    for(int i=1;i<=n;i++)
    h[i]=INF;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                int v=g[i][j].F,w=g[i][j].S;
                if(h[i]+w<h[v])
                {
                    h[v]=h[i]+w;
                }
            }
        }
    }
}
void dij(int pred[],int dis[],int n,int s)
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,s));
    bool vis[n+1];
    for(int i=0;i<=n;i++)vis[i]=0;
    while(!pq.empty())
    {
        int u=pq.top().S,d=pq.top().F;pq.pop();
        if(!vis[u])
        {
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i].F,w=g[u][i].S;
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    pred[v]=u;
                    pq.push(mp(dis[v],v));
                }
            }
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb(mp(b,c));
    }
    for(int i=1;i<=n;i++)
    {
        g[0].pb(mp(i,0));
    }
    int h[n+1];
    bell(h,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            int u=i,v=g[i][j].F;
            g[i][j].S+=h[u]-h[v];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int pred[n+1],dis[n+1];
        for(int j=1;j<=n;j++){pred[j]=-1,dis[j]=INF;}
        pred[i]=i;dis[i]=0;
        dij(pred,dis,n,i);
        for(int j=1;j<=n;j++)
        {
            if(dis[j]==INF)
            printf("dis b/w %d and %d is:no path\n",i,j);
            else printf("dis b/w %d and %d is:%d\n",i,j,dis[j]-h[i]+h[j]);
        }
    }
}