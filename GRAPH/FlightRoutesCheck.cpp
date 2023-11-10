// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200000+15;
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long

vector<int> graph[MAX_N];
vector<int> graph2[MAX_N];

void dfs(int node, vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it: graph[node]){
        if(!vis[it]) dfs(it,vis,st);
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis){
        vis[node] = 1;
        for(auto it: graph2[node]){
            if(!vis[it]){
                dfs2(it,vis);
            }
        }
}

void solve(){
    ll n,m;
    in2(n,m);


    
        for(int i{}; i<m; i++){

        int u , v;

        cin >> u >> v;

        graph[u].push_back(v);

        
    }

    vector<int> vis(n+1,0);

    stack<int> st;


    for(int i = 1; i<=n; i++){
        if(!vis[i]) dfs(i,vis,st);
    }


    // reverse the edges
    for(int i = 1; i<=n; i++){
            vis[i]=0;
    for(auto it: graph[i]){

        graph2[it].push_back(i);
    }
}

int scc = 0;
vector<int> store;
while(!st.empty()){

    int vertex = st.top();
    st.pop();

    
        if(!vis[vertex]){
            scc++;
            store.push_back(vertex);
            dfs2(vertex,vis);
        }
}

if(scc!=1){
    cout << "NO" << endl;
    cout << store[1] << " " << store[0] << endl;  // changes done here
    return;
}

cout << "YES" << endl;

 fflush(stdout);
       cout << flush;

 }
 
int main() {
 
    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif
 
 
// cout<<1<<endl;
ios_base::sync_with_stdio(0);
    cin.tie(0);
 
       solve();
 
       return 0;
}
