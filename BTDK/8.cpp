// DIJKSTRA(int u)

#include<bits/stdc++.h>

using namespace std;

int n, u;
int a[100][100], vs[100], d[100], e[100];

void DIJKSTRA(int u)
{
    for(int v=1; v<=n; v++) {
        d[v]=a[u][v];
        e[v]=u;
    }
    vs[u]=1; d[u]=0;e[u]=0;
    while(1) {
        int s=0, mn=99999;
        for(int v=1; v<=n; v++) {
            if(vs[v]==0 && d[v]<mn) {
                s=v;
                mn=d[v];
            }
        }
        if(s==0) {
            for(int v=1; v<=n; v++) {
                if(v!=u) {
                    cout << "Duong di ngan nhat tu " << u << " den " << v << " la: ";
                    for(int i=v; i!=u; i=e[i]) cout << i << "<-";
                    cout << u << " ";
                    cout << "Do lon: " << d[v] << endl;
                }
            }
            return;
        }
        vs[s]=1;
        for(int v=1; v<=n; v++) {
            if(vs[v]==0 && d[v]>d[s]+a[s][v]) {
                d[v]=d[s]+a[s][v];
                e[v]=s;
            }
        }
    }
}

int main()
{
    memset(vs, 0, sizeof(vs));
    cin >> n >> u;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    DIJKSTRA(u);
}