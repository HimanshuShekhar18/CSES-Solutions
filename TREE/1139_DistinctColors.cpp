// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

vector<int> graph[MAX_N];

#define ll long long

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,maxi;
bool flag;
string str;

// <---------------------------------------------------------------------------------------SMALL TO LARGE MERGING--------------------------------------------------------------------------------------------------->

set<int> colors[MAX_N];
int value[MAX_N];
int ans[MAX_N];
int vis[MAX_N];

/*
Every time we copy an element over, the set it is now in will be at least 2 times larger than the set it was previously in.
 Hence the time complexity is O(n(logn)^2)
 */
int merge(int a, int b){
   if(colors[a].size()<colors[b].size()) swap(a,b);
   for(auto it: colors[b]) colors[a].insert(it);
      colors[b].clear();
   return a;
}

int dfs(int source, int parent){
   vis[source]=1;
   int currset = value[source];
   for(auto it: graph[source]){
      if(it!=parent && !vis[it]) currset=merge(currset,dfs(it,source));
   }
   ans[source]=colors[currset].size();
   // cout << ans[source] << " " << source << endl;
   return currset;
}

void solve(){

   cin>> n;

   for(int i = 1; i<=n; i++){
      cin>>x;
      colors[i].insert(x);
      value[i]=i;
   }


   for(int i = 0; i<n; i++){
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   memset(vis,0,sizeof(vis));

   dfs(1,-1);

   for(int i = 1; i<=n; i++){
      cout << ans[i] << " ";
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

       solve();

       return 0;
}
