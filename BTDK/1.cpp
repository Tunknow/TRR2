#include<bits/stdc++.h>

using namespace std;

int n, st;
int a[100][100], vis[100], e[100];

void DFS(int u)
{
    cout << u << " ";
    vis[u]=1;
    for(int i=1; i<=n; i++) {
        if(vis[i]==0 && a[u][i]==1) {
            e[i]=u;
            DFS(i)
        }
    }
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vis
    cin >> n;
    for(int i=1; i<=n; i++) {
        vis[i]=0;
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> st; //Dinh bat dau duyet
    DFS(st);
}