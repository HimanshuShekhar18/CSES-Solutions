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

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,maxi;
bool flag;
string str;

// <---------------------------------------------------------------APPROACH 1: Re-Rooting Technique-------------------------------------------------------------------------------------->


ll dp[MAX_N]; // sum of distances from node i to all the nodes in the subtree of node i  
ll ans[MAX_N]; // ans[i]= sum of distances of all nodes from node i when i is a root


// dp[i] = maximum no. of treats i can get, from the subtree of node i, if I start from node i

// I Calculated my ans for a single one root

void dfs(int source, int parent){
  
  dp[source]=0;

  for(auto it: graph[source]){
    if(it!=parent){
      dfs(it,source);

      // will select maximum among all children niche se upar Or wapas aate waqat; here contribution of MAX
      dp[source]=max(dp[source],dp[it]+1);
    }
  }
}

// Now Re-rooting is needed to calculate ans for each node
void dfs2(int source, int parent){

  ans[source]=dp[source];
  ll t1 = dp[source];
  vector<ll> pre,suff;
 
  for(auto it: graph[source]){
    if(it!=parent){

      pre.push_back(dp[it]);
      suff.push_back(dp[it]);
    }
  }

  int sz = pre.size();

  // Prefix Maximum and Suffix Maximum array
  for(int i = 1; i<sz; i++){
    pre[i]=max(pre[i],pre[i-1]);  
  }

  for(int i =sz-2; i>=0; i--){
    suff[i]=max(suff[i],suff[i+1]);  
  }

  //evaluate ans for every child i
  int cnt = 0;

  for(auto it: graph[source]){
    ll t2 = dp[it];
    if(it==parent) continue;



    // re-rooting from node to ch
    l = 0; r = 0;
    if(cnt-1>=0){
      l = pre[cnt-1];
    }
    if(cnt+1<sz){
      r = suff[cnt+1];
    }
 
    // rest children mein se sabse maximum wala pick karke aate hue
    dp[source]=max(l,r);

    // agar uska koi parent bhi hain wo bhi possibilites check karlo and ek increment karlo
    if(parent!=-1){
      dp[source]=max(dp[source],dp[parent])+1;
    }

    // ye condition jab uska parent nahi tha, ek increment kardo,
    // lekin tabhi change jab hamare pas child(other than jispe root shift ho raha hain) available ho
    /*
    2
    1 2

    2nd example
    10
    10 2
    3 4
    5 7
    6 1
    6 5
    10 7
    4 8
    3 1
    9 8
    */
    if(sz>1 && parent==-1) dp[source]+=1;

    dp[it]=max(dp[it],dp[source]+1);



    dfs2(it,source);

    // restoring dp values
    dp[source]=t1;
    dp[it]=t2;
    cnt++;
  }
}


void solve(){
    
    cin>> n;
    graph.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    memset(dp,-1,sizeof(dp));
    memset(ans,-1,sizeof(ans));

    dfs(0,-1); // assuming node 1 as root
    dfs2(0,-1); // re-root to all the nodes, one by one


    for(int i = 0; i<n; i++){
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




// <--------------------------------------------------------------APPROACH 2: IN-OUT DP----------------------------------------------------------------------------------------------->

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

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,maxi;
bool flag;
string str;


// APPROACH 2: IN-OUT DP


ll in[MAX_N]; // sum of distances from node i to all other nodes in the subtree of node i  
ll out[MAX_N]; // sum of distances from node i to all other nodes but outside the subtree of node i and through it's parent
void dfs(int source, int parent){
  
  in[source]=0;

  for(auto it: graph[source]){
    if(it!=parent){
      dfs(it,source);

      // will select maximum among all children niche se upar Or wapas aate waqat; here contribution of MAX
      in[source]=max(in[source],in[it]+1);
    }
  }
}


void dfs2(int source, int parent){

  ll maxi1 = -1, maxi2 = -1;

  for(auto it: graph[source]){
      if(it!=parent){
        // storing first maximum among its children
         if(in[it]>=maxi1){
            maxi2=maxi1;
            maxi1=in[it];  
         }
         // storing second maximum among its children
         else if(in[it]>maxi2){
            maxi2=in[it];
         }
      }
  }


  for(auto it: graph[source]){
    if(it!=parent){
      ll longest = maxi1;

      /*
      this check is done ensures longest distance is not passing through
      "it" or that child upon which we are doing calculation.
      Make sure child other then "it" are selected
      */
      // if maxi1 is along that "it" child only so reject maxi1 and select second maximum distacne maxi2
      if(maxi1==in[it]){
        longest=maxi2;
      }
      // out for that "it" child can be from outside of source or maybe from among it's child othen than that "it" child
      out[it]=1+max(out[source],1+longest);
      dfs2(it,source);
    }
  }
}


void solve(){
    
    cin>> n;
    graph.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    memset(in,-1,sizeof(in));
    memset(out,-1,sizeof(out));

    dfs(0,-1); // calculation in[i] for each node i
    
    dfs2(0,-1); // calculation out[i] for each node i


    for(int i = 0; i<n; i++){
      cout << max(in[i],out[i]) << " ";
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
