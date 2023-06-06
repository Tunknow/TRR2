//TPLT_DFS(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100], vis[100], e[100], lt[100];

void DFS(int u)
{
    vis[u]=1;
    for(int i=1; i<=n; i++) {
        if(vis[i]==0 && a[u][i]==1) {
            e[i]=u;
            DFS(i);
        }
    }
}

int TPLT_DFS(int a[][100])
{
    int k=0;
    int u;
    while(1) {
        bool done=true;
        for(int i=1; i<=n; i++) {
            if(lt[i]==0) {
                done=false;
                u=i;
                break;
            }
        }
        if(done) return k;
        k++;
        DFS(u);
        for(int i=1; i<=n; i++) if(vis[i]==1) lt[i]=k;
    }
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vis
    cin >> n;
    for(int i=1; i<=n; i++) {
        vis[i]=0;
        lt[i]=0;
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    cout << TPLT_DFS(a);
}