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
 
vector<pair<int,int>> graph[MAX_N];  
vector<int> seen;
vector<int> path;
 
// time complexity: O(E)
void dfs(int node){
    while(!graph[node].empty()){  
        int v = graph[node].back().first;
        int index = graph[node].back().second;
        graph[node].pop_back(); 
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
    int outdeg[n+1] = {0};
    
        for(int i = 1; i<=m; i++){
 
        int u , v;
 
        cin >> u >> v;
 
        graph[u].push_back({v,i});
        outdeg[u]++;
        indeg[v]++;        
    }
 
 
    /* The condition of existance for an eulerian path in a directed graph is: At most one node has 
$out_i - in_i=1$
 and at most one node has 
$in_i - out_i=1$
.
This property is because an Eulerian path or cycle leaves a node the same number of times it enters the node. In a directed
geaph the exception are the start node and the end node.
   */
 
    for(int i = 2; i<n; i++){
        if(outdeg[i]!=indeg[i]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
 
    // exception are the start node and the end node.
    if(outdeg[1]-indeg[1]!=1 || indeg[n]-outdeg[n]!=1){
        cout << "IMPOSSIBLE" << endl;
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
