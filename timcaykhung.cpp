#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100];
int e[100];
bool vis[100];

void dfs(int u)
{
    vis[u]=true;
    e[u]=0;
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int cur=st.top();       
        int ok=false;
        for(int i=1; i<=n; i++) {
            if(!vis[i] && a[cur][i]==1) {
                vis[i]=true;
                e[i]=cur;
                st.push(i);
                ok=true;
                break;
            }
        }
        if(!ok) st.pop();
    }
}
void bfs(int u)
{
    vis[u]=true;
    e[u]=0;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(!vis[i] && a[cur][i]==1) {
                vis[i]=true;
                e[i]=cur;
                q.push(i);
            }
        }
    }
}

void DFStree(int s)
{
    for(int i=1; i<=n; i++) {
        vis[i]=false;
    }
    dfs(s);
    bool ok=true;
    for(int i=1; i<=n; i++) if(!vis[i]) ok=false;
    if(!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "Stack DFS tree: ";
    for(int i=1; i<=n; i++) {
        if(e[i]!=0) cout << "(" << i << ", " << e[i] << ")" << " ";
    }
    cout << endl;
}

void BFStree(int s)
{
    for(int i=1; i<=n; i++) {
        vis[i]=false;
    }
    bfs(s);
    bool ok=true;
    for(int i=1; i<=n; i++) if(!vis[i]) ok=false;
    if(!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "Queue BFS tree: ";
    for(int i=1; i<=n; i++) {
        if(e[i]!=0) cout <<"(" << i << ", " << e[i] << ")" << " ";
    }
    cout << endl;
}

void solve(int s)
{
    DFStree(s);
    BFStree(s);
}

int main()
{
    cin >> n;
    int s;
    cin >> s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> a[i][j];
    solve(s);

    return 0;
}