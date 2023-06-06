// T_BFS(int a[][])

// T_DFS(int a[][])

//TPLT_DFS(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100], vis[100], e[100], lt[100];

void BFS(int u)
{
    vis[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(vis[i]==0 && a[cur][i]==1) {
                vis[i]=1;
                e[i]=cur;
                q.push(i);
            }
        }
    }
}

void T_BFS(int a[][100]) 
{
    for(int i=1; i<=n; i++) vis[i]=0;
    BFS(1);
    int cnt=0;
    for(int i=1; i<=n; i++) if(vis[i]==1) cnt++;
    if(cnt==n) {
        for(int i=1; i<=n; i++) {
            if(e[i]!=0) cout << i << " " << e[i] << endl;
        }
    }
    else cout << "Khong co cay khung";
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
    T_BFS(a);
}