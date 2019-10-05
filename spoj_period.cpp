#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
const ll INF=(1e18);
const int N=((1e5));
int n;
string s;
void preKMP(int lps[],int period[],int n) {
    int id=0;
    lps[0]=0;
    period[0]=1;
    // we will have to update period too
    for(int i=1;i<n;) {
        if(s[id]==s[i]) { // 
            //cout<<"i="<<i<<" in 1"<<endl;
            lps[i]=++id;
            int k=period[i-lps[i]];
            if(k>0&&(i+1)%k==0) period[i]=k;
            else if((i+1)%(i-lps[i]+1)==0) period[i]=(i-lps[i]+1);
            // else if(lps[i]*2==(i+1)) period[i]=lps[i];
            else period[i]=0;
            i++;
        }
            
        else {
            if(id>0) {
                //cout<<"i="<<i<<" in 2"<<endl;
                id=lps[id-1]; // we will go for next lesser index match
            }
            else {
                //cout<<"i="<<i<<" in 3"<<endl;
                lps[i]=0; // can't go more backwards so lps[i]=0;
                period[i]=0;
                i++;
            }
        }
    }
}
int main() {
    fast
    int t;cin>>t;
    for(int w=1;w<=t;w++) {
        cin>>n;
        cin>>s;
        int lps[n],period[n];
        preKMP(lps,period,n);
        for(int i=0;i<n;i++){
            if(period[i]>0)
                period[i]=(i+1)/period[i];
        }
        // cout<<"lps:-";
        // for(int i=0;i<n;i++){
        //     cout<<lps[i]<<" ";
        // }
        cout<<"Test case #"<<w<<endl;
        for(int i=0;i<n;i++){
            if(period[i]>1){
                cout<<i+1<<" "<<period[i]<<endl;
            }
        }
        cout<<endl;
    }
}
