#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<ll,ll>
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define mi map<ll,ll>
#define mii map<pii,ll>
#define N 50002
ll mod=(1e9)+7;
struct node
{
    ll sum,pSum,sSum,ms;
};
node create(ll x,ll y)
{
    node p;
    p.sum=y;p.pSum=p.sSum=p.ms=x;
    return p;
}
node st[4*N];
ll a[N],n,q;
node call(node p,node q)
{
    node c=create(0,0);
    c.sum=p.sum+q.sum;
    c.pSum=max(p.sum+q.pSum,p.pSum);
    c.sSum=max(p.sSum+q.sum,q.sSum);
    c.ms=max(max(p.ms,q.ms),p.sSum+q.pSum);
    return c;
}
void build(ll s,ll e,ll id)
{
    if(s>e)return;
    if(s==e){st[id]=create(a[s],a[s]);return;}
    ll mid=s+(e-s)/2;
    build(s,mid,2*id);
    build(mid+1,e,2*id+1);
    st[id]=call(st[2*id],st[2*id+1]);
}
node query(ll s,ll e,ll ss=0,ll ee=n-1,ll id=1)
{
    if(s>e||ss>ee)return create(INT_MIN/2,0);
    if(s>ee||e<ss)return create(INT_MIN/2,0);
    if(s==ss&&e==ee){return st[id];}
    ll mid=ss+(ee-ss)/2;
    node p=query(s,min(mid,e),ss,mid,2*id);
    node q=query(max(mid+1,s),e,mid+1,ee,2*id+1);
    node r=call(p,q);
    return r;
}
void update(ll ss,ll ee,ll id,ll k)
{
	if(ss>ee)return;
	if(k<ss||k>ee)return;
	if(ss==ee&&ss==k){st[id]=create(a[k],a[k]);return;}
	ll mid=ss+(ee-ss)/2;
	update(ss,mid,2*id,k);
    update(mid+1,ee,2*id+1,k);
    st[id]=call(st[2*id],st[2*id+1]);
}
int main()
{
    fast
	int t;cin>>t;
	while(t--){
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    cin>>q;
    build(0,n-1,1);
    while(q--)
    {
        ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		if(x2>y1)
		{
			node a1=query(x1,y1),a2=query(x2,y2),a3=query(y1+1,x2-1);
			cout<<a1.sSum+a3.sum+a2.pSum<<endl;
		}
		else
		{
			ll r1,r2,r3;
			r1=query(x1,x2-1).sSum+query(x2,y2).pSum;
			r2=query(x2,y1).ms;
			r3=query(x2,y1).sSum+query(y1+1,y2).pSum;
			cout<<max(r1,max(r2,r3))<<endl;
		}
    }
	}
}
/*
    //st[id]=st[2*id]+st[2*id+2];
    //cout<<"id="<<id<<" st= "<<st[id].ms<<endl;
//cout<<"s="<<s<<" e="<<e<<" id="<<id<<endl;
8 -3 8 4 -5 3 9 -15 1
small-
medium-
large-
*/
