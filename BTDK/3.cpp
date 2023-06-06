//TPLT_DFS(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int k=0;
int a[100][100], lt[100];

void DFS(int u)
{
    lt[u]=k;
    for(int i=1; i<=n; i++) {
        if(lt[i]==0 && a[u][i]==1) {
            DFS(i);
        }
    }
}

int TPLT_DFS(int a[][100])
{
    k=0;
    for(int i=1; i<=n; i++) lt[i]=0;
    for(int i=1; i<=n; i++) {
        if(lt[i]==0) {
            k++;
            DFS(i);
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
    cout << TPLT_DFS(a) << endl;
    vector<int> tplt[k+1];
    for(int i=1; i<=n; i++) {
        int id=lt[i];
        tplt[id].push_back(i);
    }
    for(int i=1; i<=k; i++) {
        for(auto x:tplt[i]) cout << x << " ";
        cout << endl;
    }
}