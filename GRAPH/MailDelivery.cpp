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
 
vector<pair<int,int>> graph[MAX_N];  // changes done here 
vector<int> seen;
vector<int> path;
 
 
void dfs(int node){
    while(!graph[node].empty()){  // changes done here
        int v = graph[node].back().first;
        int index = graph[node].back().second;
        graph[node].pop_back();  // changes done here 
        if(!seen[index]){
            seen[index]=1;
            dfs(v);
        }
    }
    path.push_back(node);
}
 
 
 
void solve(){
    ll n,m;
    in2(n,m);
 
    int indeg[n+1] = {0};
    
        for(int i = 1; i<=m; i++){
 
        int u , v;
 
        cin >> u >> v;
 
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
        indeg[u]++;
        indeg[v]++;        
    }
 
    // An important condition is that a graph can have an Eulerian cycle (not path) if and only if every node has an even degree.
    for(int i = 1; i<=n; i++){
        if(indeg[i]%2){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
 
 
    // check for edges visited
    seen.resize(m+1,0);
 
    dfs(1);
 
    
    if(path.size()!=m+1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    reverse(path.begin(),path.end());
 
    for(auto it: path){
        cout << it << " ";
    }
 
 
 
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
