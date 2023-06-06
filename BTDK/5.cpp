// T_DFS(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100], vs[100], e[100], lt[100];

void DFS(int u)
{
    vs[u]=1;
    for(int i=1; i<=n; i++) {
        if(vs[i]==0 && a[u][i]==1) {
            e[i]=u;
            DFS(i);
        }
    }
}

void T_DFS(int a[][100]) 
{
    for(int i=1; i<=n; i++) vs[i]=0;
    DFS(1);
    int cnt=0;
    for(int i=1; i<=n; i++) if(vs[i]==1) cnt++;
    if(cnt==n) {
        for(int i=1; i<=n; i++) {
            if(e[i]!=0) cout << i << " " << e[i] << endl;
        }
    }
    else cout << "Khong co cay khung";
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vs
    cin >> n;
    for(int i=1; i<=n; i++) {
        vs[i]=0;
        lt[i]=0;
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    T_DFS(a);
}