#include<bits/stdc++.h>

using namespace std;

int n, st;
int a[100][100], vs[100], e[100];

void BFS(int u)
{
    vs[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        cout << cur << " ";
        for(int i=1; i<=n; i++) {
            if(vs[i]==0 && a[cur][i]==1) {
                vs[i]=1;
                e[i]=cur;
                q.push(i);
            }
        }
    }
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vs
    cin >> n;
    for(int i=1; i<=n; i++) {
        vs[i]=0;
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> st; //Dinh bat dau duyet
    BFS(st);
}