// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

vector<vector<int>> graph;

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,maxi;
bool flag;
string str;


ll dp[MAX_N]; // sum of distances from node i to all the nodes in the subtree of node i  
vector<int> subtreenodes; // no. of nodes in subtree of node i 
ll ans[MAX_N]; // ans[i]= sum of distances of all nodes from node i when i is a root
void dfs(int source, int parent){
  
  subtreenodes[source]=1;
  dp[source]=0;

  for(auto it: graph[source]){
    if(it!=parent){
      dfs(it,source);
      subtreenodes[source]+=subtreenodes[it];
      dp[source]+=(dp[it]+subtreenodes[it]);
    }
  }
}

void dfs2(int source, int parent){
  ll dis1 = dp[source];
  ll cnt1 = subtreenodes[source];
  for(auto it: graph[source]){
    if(it!=parent){
      ll dis2 = dp[it];
      ll cnt2 = subtreenodes[it];

      // Transfering root from node to it
      subtreenodes[source]-=subtreenodes[it];
      dp[source]-=(dp[it]+subtreenodes[it]);
      subtreenodes[it]+=subtreenodes[source];
      dp[it]+=dp[source]+subtreenodes[source];

      ans[it]=dp[it];

      dfs2(it,source);

      // rollback the root to node
      dp[source]=dis1;
      subtreenodes[source]=cnt1;
      dp[it]=dis2;
      subtreenodes[it]=cnt2;
    }
  }
}


void solve(){
    
    cin>> n;
    graph.resize(n+1);
    subtreenodes.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    memset(dp,-1,sizeof(dp));
    memset(ans,-1,sizeof(ans));

    dfs(1,-1);
    ans[1]=dp[1];
    dfs2(1,-1);


    for(int i = 1; i<=n; i++){
      cout << ans[i] << " ";
    }

    cout << endl;   

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

