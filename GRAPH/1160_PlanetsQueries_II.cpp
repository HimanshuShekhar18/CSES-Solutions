// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */



#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
#define getcurrtime      ((double)clock()/CLOCKS_PER_SEC)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


# define ll long long

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


// <-----------------------------------------------------DP ON GRAPHS--------------------------------------------------->
// <-------------------------------------------------BINARY LIFTING OR BINARY JUMPING----------------------------------------------------->

/*

Problem Breaking

i) Seeing the constraint says it's BINARY LIFTING
ii) Just seems like kth children of a tree, but it's not a tree 
iii) Out-degree of each node = 1 (as given only one teleporter)
iv) Cycle is definitely present 
v) what's the problem with applying Binary Lifting?
ans: There are cycles and we didn't work with that. Let see how to deal with the cycles
vi) All the cycles are DISJOINT, due to out-degree = 1 constraint
vii) So there are just Disjoint Cycles that have "trees" attached to them.
viii) In a Single Component, Only 1 Cycle will be present;

*/


/*

Problem Breakdown 

i) Notice that there can't be a directed path form 1 vertex in one cycle to another vertex outside the cycle
(because out degree of each cycle is 1)
and then there can be "trees" entering these cycles through one vertex(i.e. a root for this "tree")

*/

vector<int> graph[MAX_N];
vector<int> rgraph[MAX_N];

int jump;
int par[MAX_N];
int dp[MAX_N][30];
int vis[MAX_N];
int comp[MAX_N];
int depth[MAX_N];
int LEN;
int cycle_length[MAX_N];
int in_cycle[MAX_N];

void markRoot(){
  function<void (int)> dfs = [&](int node){
        vis[node]=1;
        int u = par[node];
        if(vis[u]){
          if(vis[u]==1){
            in_cycle[u]=1;    // root marked done
          }
        }
        else {
          dfs(u);
        }
        
        vis[node]=2;
  };

  fill(vis,vis+MAX_N,0);

  for(int i = 0; i<n; i++){
    if(!vis[i]) dfs(i);
  }
}

// simple component marking 
void markComponent(){
  function<void (int)> dfs = [&](int node){
    comp[node]=j;
    vis[node]=1;
    for(auto it: graph[node]) {
      if(!vis[it]) dfs(it);
    }
  };

  fill(vis,vis+MAX_N,0);
  for(int i = 0; i<n; i++){
    if(!vis[i]) {
      dfs(i);
      j++;
    }
  }
}

void build_and_depth(){

  // NOTE: Depth is calculated taking usss component ka "root" as a base

  function<void (int,int)> dfs_depth = [&](int node, int parent){

    if(parent!=-1){   // changes done here "1" replaced with "-1"
      depth[node]+=depth[parent]+1;
    }

    for(auto it: rgraph[node]){
      dfs_depth(it,node);
    }

  };

  for(int i = 0; i<n; i++){

      if(in_cycle[i]) continue;    // root ko leave karte hue

      dp[i][0]=par[i];
      rgraph[par[i]].push_back(i);  
  }

  for(int i = 0; i<n; i++){
    if(in_cycle[i]) dfs_depth(i,-1);  // sirf root se start honga
  }


  // preprocessing part  Dynamic Part TC: O(n*log(n))
    for(int j = 1; j<=jump; j++){  
        for(int i = 0; i<n; i++){
            // root ko leave karte hue
            if(dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1];      
    }
  }
}


void mark_in_cycle(){
    set<int> st;
      for(int i = 0; i<n; i++){
        if(!in_cycle[i]) continue;

        // In a Single Component, Only 1 Cycle will be present;
        if(st.find(comp[i])!=st.end()) continue;   // if the cycle is already processed for a component nothing to do further;

        st.insert(comp[i]);

        int u = par[i];

        int length = 1;

        while(u!=i && in_cycle[u]==0){
          in_cycle[u]=1;
          length++;
          u = par[u];
        }

        cycle_length[comp[i]] = length; // storing cyclelength for each component

      }
}




int LCA(int u, int v){

  if(depth[u]>depth[v]) swap(u,v);

  int diff = depth[v]-depth[u];

  for(int i = jump; i>=0; i--){
      if(diff&(1<<i)){
        v=dp[v][i];
      }
  }

  if(v==u) return u;

  // agar u or v mein se koi bhi ek agar "root" node to wo upar hi lca ka part upar hi solve ho jata 
  // niche jane ki jaroort nahi 

  for(int i = jump; i<=0; i--){
    int upar = dp[u][i];
    int vpar = dp[v][i];

    if(upar==-1 || vpar==-1) continue;  // this special case only for root node;

    if(upar!=vpar){
      u=upar;
      v=vpar;
    }
  }

  return dp[v][0];

}


void solve(){

  cin >> n >> q;

  for(int i = 0; i<n; i++){
  
    cin >> par[i];
    par[i]--;
    graph[i].push_back(par[i]);
    graph[par[i]].push_back(i);    
  }

  jump = log2(n)+1;


  memset(in_cycle,0,sizeof(in_cycle));
  memset(depth,0,sizeof(depth));
  fill_n(&dp[0][0],MAX_N*30,-1);

  markRoot();
  j = 0;
  markComponent();
  build_and_depth();
  mark_in_cycle();

  while(q--){
    cin >> u >> v;

    u--,v--;
    if(comp[u]!=comp[v]){
      cout << -1 << endl;
      continue;
    }

    int lca = LCA(u,v);
    int diff = abs(depth[u]-depth[v]);
    int LEN = cycle_length[comp[u]];
 
    // case 1: when u is present in cycle
    if(in_cycle[u])
    {

      // sub-case if v is also prensent in cycle
      if(in_cycle[v])
      {
            // "u" root ke aage hain and "v" root ke piche; hence lca at "v"
            if(lca == v)
            {
                cout << diff << endl;
            }

            // "u" root ke piche hain and "v" root ke aage; hence lca at "u"
            else
            {
             // lca == u
              cout << LEN - diff << endl;
            }
      }

      // sub-case if v is not present in cycle
      else 
      {
        cout << -1 << endl;
        
      }
    }

    // case 2: when u is not present in cycle
    else 
    {

      // sub-case if v is present in cycle
      if(in_cycle[v])
      {
          // if u(part of tree) is directly pointing to v(part of cycle)
          if(lca==v)
          {
            cout << diff << endl;
            
          }

          // 
          else
          {
              cout << abs(depth[lca]-depth[u]) + LEN - abs(depth[lca]-depth[v]) << endl;
              
          }
      }

      // sub-case if v is not present in cycle
      else 
      {

          if(lca==v)
          {
            cout << diff << endl;
            
          }

          else 
          {
            cout << -1 << endl;
            
          }

      }
    }

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

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}
