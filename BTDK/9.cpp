// FLOYD(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100], d[100][100], e[100][100];

void FLOYD(int a[][100])
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            d[i][j]=a[i][j];
            e[i][j]=i;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    e[i][j]=k;
                }
            }
        }
    }
    //xuat ket qua
    bool chuachutrinham=false;
    for(int u=1; u<=n; u++) if(d[u][u]<0) {
        chuachutrinham=true;
        break;
    }
    if(chuachutrinham) {
        cout << "G chua chu trinh am" << endl;
    }
    else {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << "d[" << i << "][" << j << "]=" << d[i][j] << " " << "e[" << i << "][" << j << "]=" << e[i][j] << endl;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    FLOYD(a);
}