// KRUSKAL(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n, m, d[10000], c[10000], ts[10000];
int vs[100], t[100], a[100][100];
void KRUSKAL(int a[][100]) {
    int inf=9999;
    int id=0;
    for(int i=1; i<=n-1; i++) {
        for(int j=i+1; j<=n; j++) {
            if(a[i][j]!=inf) {
                id++;
                d[id]=i;
                c[id]=j;
                ts[id]=a[i][j];
            }
        }
    }
    int m=id;
    for(int i=1; i<=m-1; i++) {
        for(int j=i+1; j<=m; j++) {
            if(ts[i]>ts[j]) {
                swap(ts[i],ts[j]);
                swap(d[i],d[j]);
                swap(c[i], c[j]);
            }
        }
    }
    int wt=0, k=0;
    bool cocaykhung=false;
    for(int i=1; i<=n; i++) vs[i]=0;
    for(int i=1; i<=m; i++) {
        if(!(vs[d[i]]!=0 && vs[d[i]]==vs[c[i]])) {
            k++;
            t[k]=i;
            wt+=ts[i];
            if(k==n-1) {
                cocaykhung=true;
                cout << "Trong so: " << wt << endl;
                cout << "Cay khung: " << endl;
                for(int j=1; j<=k; j++) {
                    cout << d[t[j]] << " " << c[t[j]] << endl;
                }
                return;
            }
        }
        int u=d[i], v=c[i];
        if(vs[u]==0 && vs[v]==0) {
            vs[u]=k;
            vs[v]=k;
        }
        else if(vs[u]==0 && vs[v]!=0) vs[u]=vs[v]; 
        else if(vs[u]!=0 && vs[v]==0) vs[v]=vs[u];
        else if(vs[u]<vs[v]) {
            int temp=vs[v];
            for(int j=1; j<=n; j++) {
                if(vs[j]==temp) vs[j]==vs[u];
            }
        }
        else if(vs[v]<vs[u]) {
            int temp=vs[u];
            for(int j=1; j<=n; j++) {
                if(vs[j]==temp) vs[j]==vs[v];
            }
        }
    }
    if(!cocaykhung) cout << "Khong co cay khung" << endl;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) cin >> a[i][j];
    
    KRUSKAL(a);
}