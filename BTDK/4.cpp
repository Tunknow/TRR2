//TPLT_DFS(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int k;
int a[100][100], lt[100];

void BFS(int u)
{
    lt[u]=k;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(lt[i]==0 && a[cur][i]==1) {
                lt[i]=k;
                q.push(i);
            }
        }
    }
}

int TPLT_BFS(int a[][100])
{
    k=0;
    for(int i=1; i<=n; i++) lt[i]=0;
    for(int i=1; i<=n; i++) {
        if(lt[i]==0) {
            k++;
            BFS(i);
        }
    }
    return k;
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vs
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    cout << TPLT_BFS(a);
}