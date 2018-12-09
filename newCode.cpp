#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define mi map<int,int>
#define mii map<pii,int>
#define N 100002
//variables
int main()
{
    int n,c;cin>>n>>c;
    int t=1000,curr=1,prev;
    while(1)
    {
        prev=curr;
        curr=min(curr+t-c+1,n);
        cout<<1<<" "<<curr<<endl;
        int x;cin>>x;
        if(x==0)
        {
            t--;
            curr++;
        }
        else
        {
            cout<<2<<endl;
            t-=c;
            int ans=-1;
            for(int i=prev;i<curr;i++)
            {
                cout<<1<<" "<<i<<endl;
                cin>>x;
                if(x==1)
                {
                    ans=i;
                    break;
                }
                else t--;
            }
            if(ans==-1)ans=curr;
            cout<<3<<" "<<ans<<endl;
            break;
        }
    }
}
/*
A, cache = linear_activation_forward(A_prev,parameters[W+str(l)],parameters[b+str(l)],"relu")
small-
medium-
large-
*/