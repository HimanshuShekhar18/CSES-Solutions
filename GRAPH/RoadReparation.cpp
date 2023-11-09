// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 100000+15;
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
int parent[MAX_N];
int sz[MAX_N];
 
void make(int val){
    parent[val]=val;
    sz[val]=1;
}
 
int find(int val){
    if(val==parent[val]) return val;
    else return find(parent[val]);
}
 
void Union(int a, int b){
    int u = find(a);
    int v = find(b);
    if(u!=v){
 
        if(sz[u]<sz[v]) swap(u,v);
        parent[v]=u;
        sz[u]+=sz[v];
 
    }
}
 
 
void solve(){
    ll n,m;
    in2(n,m);
 
   
    // create graph
    vector<pair<int,pair<int,int>>> graph;
    
        for(int i{}; i<m; i++){
 
        int a{},b{},c{};
 
        cin >> a >> b >> c;
 
        graph.push_back({c,{a,b}});
 
    }
 
    ll total_cost = 0;
 
    for(int i = 1; i<=n; i++){
        make(i);
    }
 
 
    sort(graph.begin(),graph.end());
 
 
 
    for(auto g: graph){
        int wt = g.first;
        int u = g.second.first;
        int v = g.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
    }
 
    int vertex;
 
    for(int i = 1; i<= n; i++){
        if(parent[i]==i) {
            vertex=i;
            break;
        }
    }
 
    int save = 0;
 
    // size check karle why?
    // to check whether routes exist between any two vertex i.e. all vertices are connected by any means.
    for(int i = 1; i<= n; i++){
        if(sz[i]==n) {
            save = sz[i];
            break;
        }
    }
 
    if(save!=n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    cout << total_cost << endl;
 
 
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
