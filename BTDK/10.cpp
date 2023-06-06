//PRIM(int a[][], int u) 

#include<bits/stdc++.h>

using namespace std;

int n, u;
int a[100][100], d[100], e[100], vs[100];

void PRIM(int a[][100], int u) {
    for(int v=1; v<=n; v++) {
        d[v]=a[u][v];
        e[v]=u;
        vs[v]=0;
    }
    vs[u]=1; d[u]=0; e[u]=0;
    int cnt=1, wt=0;
    while(cnt<n) {
        int s=0;
        int mn=99999;
        for(int v=1; v<=n; v++) {
            if(vs[v]==0 && d[v]<mn) {
                s=v;
                mn=d[v];
            }
        }
        if(s==0) {
            cout << "Khong co cay khung" << endl;
            return;
        }

        cnt++;
        vs[s]=1;
        wt=wt+a[s][e[s]];
        for(int v=1; v<=n; v++) {
            if(vs[v]==0 && d[v]>a[s][v]) {
                d[v]=a[s][v];
                e[v]=s;
            }
        }
    }
    cout << "Trong so cay khung: " << wt << endl;
    for(int v=1; v<=n; v++) {
        if(e[v]!=0) {
            cout << v << " " << e[v] << endl;
        }
    }
    return;
}

int main()
{
    cin >> n >> u;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    PRIM(a,u);
}