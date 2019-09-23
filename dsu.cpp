#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
const ll INF=(1e18);
const int N=(2*(1e5));

int root[N+1],sz[N+1];
int find(int x) {
	if(root[x]!=x){
		x=find(root[x]);
	}
	return x;
}
void Union(int a, int b, ll &ans) {
	int r1=find(a),r2=find(b);
	if(r1==r2) return;
	if(sz[r1]<sz[r2])swap(r1,r2);
	root[r2]=r1;
	// update ans
	ll x1=sz[r1],x2=sz[r2];
	if(x1>=1) ans-= x1*(x1-1)/2;
	if(x2>=1) ans-= x2*(x2-1)/2;
	if(x1+x2>=1) ans+= (x1+x2)*(x1+x2-1)/2;

	sz[r1] += sz[r2];
	sz[r2] = 0;
}
int main() {
	fast
	int n,q;
	cin>>n>>q;
	int e=n-1;
	pair<int,pii> edgeList[e];
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edgeList[i]=mp(w,mp(u,v));
	}
	sort(edgeList,edgeList+e); // sort by weight
	pii qry[q]; // sort queries and apply dsu
	for(int i=0;i<q;i++) {
		cin>>qry[i].first;
		qry[i].second=i;
	}
	sort(qry,qry+q); 
	
	for(int i=0;i<=n;i++){
		root[i]=i;
		sz[i]=1;
	}
	int j=0;
	ll ans=0; // index of edge till which unioned
	ll arrAns[q];
	for(int i=0;i<q;i++) {
		int x=qry[i].first;
		while(j<e && edgeList[j].first<=x){
			Union(edgeList[j].second.first,edgeList[j].second.second,ans);
			j++;
		}
		arrAns[qry[i].second]=ans;
	}
	for(int i=0;i<q;i++){
		cout<<arrAns[i]<<" ";
	}cout<<endl;
}