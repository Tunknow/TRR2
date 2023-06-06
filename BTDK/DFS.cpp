#include<bits/stdc++.h>

using namespace std;

int a[100][100], u, n, vs[100];

void DFS(int u) {
    vs[u]=1;
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int v=st.top();
        int ok=1;
        for(int i=1; i<=n; i++) {
            if(vs[i]==0 && a[v][i]==1) {
                vs[i]=1;
                ok=0;
                st.push(i);
                break;
            }
        }
        if(ok==1) {
            cout << st.top() << " ";
            st.pop();
        }
    }
}

int main()
{
    memset(vs, 0, sizeof(vs));
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    DFS(1);
}