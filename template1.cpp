#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
const ll INF=(1e18);
const int N=((1e5+1));
const int mod=((1e9+7));
ll power(ll a, ll b, ll mod) {
    ll ans=1,mul=a;
    while(b>0) {
        if(b%2==1){
            ans=(ans*mul)%mod;
        }
        mul=(mul*mul)%mod;
        b/=2;
    }
    return ans;
}
ll inv(ll a){
    return power(a,mod-2,mod);
}
ll prod_g(ll p,ll h,ll x,ll n) {
    if(h==0) return 1;
    ll s1=0,s2=0,s3=0;
    if(h>=2) {
        s1=(x-p)/(p-1);
    }
    if(h>=2){
        s2=(h-1)*(x);
    }
    s3=h*(n-x+1);
    cout<<"p="<<p<<" h="<<h<<" x="<<x<<" n="<<n<<endl;
    cout<<"s1="<<s1<<" s2="<<s2<<" s3="<<s3<<endl;
    return power(p,-s1+s2+s3,mod);
}
int main(){
    fast
    ll x,n,ans=1;
    cin>>x>>n;
    // memset(m,0,sizeof(m));
    // cout<<power(2,x,mod)<<" "<<power(3,x,mod)<<endl;
    ll i=2,p=x;
    while(i<=N&&p>0){
        if(p%i==0)
        cout<<"p="<<p<<endl;
        int n1=0;
        while(p%i==0){
            p/=i;
            n1++;
        }
        // i is the prime
        if(n1>0){
            ll aa=1,h=0;
            while(aa<=n){
                aa=aa*i;
                h++;
            }
            ll temp1=prod_g(i,h-1,aa/i,n);
            ans=(ans*temp1)%mod;
        }
        i++;
    }
    if(p>0){
        i=p;
        ll aa=1,h=0;
        if(n<i)h=0;
        else if(n<i*i)h=1;
        else if(i>(ll)(1e6))h=2;
        else if(n<i*i*i)h=2;
        else h=3;
        for(int i=0;i<h;i++)aa*=i;
        ll temp1=prod_g(i,h-1,aa,n);
        ans=(ans*temp1)%mod;
    }
    cout<<ans<<endl;
}
/*
small :- 
med :-
large:- 
*/