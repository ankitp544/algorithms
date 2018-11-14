#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<double> a[100];
int pi[101];
int flag=0;
void lup(vector<double> a[],int n)
{
    //go in column and find the max element column
    for(int k=0;k<n;k++)
    {
        int maxi=k;double maxe=abs(a[k][k]);
        for(int i=k;i<n;i++)//iterating on col
        {
            if(abs(a[i][k])>maxe)
            {
                maxe=abs(a[i][k]);
                maxi=i;
            }
        }
        if(maxe==0)
        {
            cout<<"Unsolveable"<<endl;
            flag=1;
            return ;
        }
        swap(a[k],a[maxi]);
        swap(pi[k],pi[maxi]);
        for(int i=k+1;i<n;i++)
        {
            a[i][k]/=a[k][k];
            for(int j=k+1;j<n;j++)
            {
                a[i][j]-=(a[i][k]*a[k][j]);
            }
        }
    }
}
void solve(double l[100][100],double u[100][100],double x[100],int n,double b[100])
{
    double y[n];
    for(int i=0;i<n;i++)
    {
        double sum=0;
        for(int j=0;j<i;j++)
        {
            sum+=l[i][j]*y[j];
        }
        y[i]=(b[pi[i]]-sum)/l[i][i];
    }
    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int j=n-1;j>i;j--)
        {
            sum+=u[i][j]*x[j];
        }
        x[i]=(y[i]-sum)/u[i][i];
    }
}
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            double x;cin>>x;
            a[i].pb(x);
        }
    }
    cout<<"enter b\n";double b[n];
    for(int i=0;i<n;i++)
    {
        pi[i]=i;
        cin>>b[i];
    }
    lup(a,n);
    if(flag)
    exit(1);
    double l[100][100],u[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j)
            {
                l[i][j]=a[i][j];
                u[i][j]=0;
            }
            else if(i==j)
            {
                l[i][j]=1;
                u[i][j]=a[i][j];
            }
            else
            {
                l[i][j]=0;
                u[i][j]=a[i][j];
            }
        }
    }
    double x[100];
    solve(l,u,x,n,b);
    for(int i=0;i<n;i++)
    {
        int a=ceil(x[i]),b=x[i];
        if(a-x[i]>x[i]-b)x[i]=b;else x[i]=a;
        //cout.precision(5);
        cout<<x[i]<<" ";
    }cout<<endl;
}