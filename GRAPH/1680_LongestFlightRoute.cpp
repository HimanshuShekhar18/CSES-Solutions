
// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

// <---------------------------------------------------------------------TIME LIMIT EXCEEDED------------------------------------------------------------------------->
// All Test Cases Passed Only 2 got TLE

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

vector<int> graph[MAX_N];

long long dp[MAX_N];
long long dp2[MAX_N][5];

# define f(a,n,i) for(int i = a; i<n; i++)

# define in(a) cin>>a
# define in2(a,b) cin>>a>>b

# define ll long long


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


int dis[MAX_N];
int parent[MAX_N], sz[MAX_N];


vector<int> path;
void trace(int node) {
 if( parent[node] == -1)
     return;
 path.push_back(parent[node]);
 trace(parent[node]);
}


void solve(){

        path.clear();
        in2(n,m);


        f(0,m,i){
            in2(u,v);
            graph[u].push_back(v);
        }

        memset(dis,0,sizeof(dis));
        memset(parent,-1,sizeof(parent));

    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();
        for (auto child: graph[cur_vertex])
        {
           if(dis[cur_vertex]+1>dis[child]){
            q.push(child);
            dis[child]=dis[cur_vertex]+1;
            parent[child]=cur_vertex;            
           }
        }
    }

    if(dis[n]==0) cout << "IMPOSSIBLE" << endl;
path.push_back(n);

trace(n);
reverse(path.begin(), path.end());

cout << path.size() << endl;

f(0,path.size(),i){
    cout << path[i] << " ";
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

       solve();

       return 0;
}


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
// <------------------------------------------------------------------------------TOPOLOGICAL SORTING--------------------------------------------------------------------------------->
 
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<int> graph[MAX_N];
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;
 
 
int parent[MAX_N], sz[MAX_N];
 
vector<int> path;
void trace(int node) {
 if( parent[node] == -1)
     return;
 path.push_back(parent[node]);
 trace(parent[node]);
}
 
 
void solve(){
 
    in2(n,m);
    int in_deg[n]={0};
 
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    in_deg[y]++;
}
 
 
/* EXPLANATION
 
 
            1-->2-->10(target)
            |       ↑
            ↓       |
  12-->11-->3-->4-->5
 
Longest Route = 1-->3-->4-->5-->10
 
*/
 
queue<int> q;
 
for(int i=2;i<n;i++){
    if(in_deg[i]==0){
        q.push(i);
    }
}
 
 
// TOPOLOGICAL SORTING EXCLUDING 1
while(!q.empty()){
    int x  = q.front();
    q.pop();
    for(int i=0;i<graph[x].size();i++){
        int y = graph[x][i];
        in_deg[y]--;
        if(in_deg[y]==0){
            if(y!=1) q.push(y);
        }
    }
}
        
memset(parent,-1,sizeof(parent));
 
q.push(1);
 
 
// TOPOLOGICAL SORTING INCLUDING 1
while(!q.empty()){
    int x  = q.front();
    q.pop();
    for(int i=0;i<graph[x].size();i++){
        int y = graph[x][i];
        in_deg[y]--;
         parent[y]=x;
        if(in_deg[y]==0){
            q.push(y);
        }
    }
}
 
if(parent[n]==-1) {
    cout << "IMPOSSIBLE" << endl;
    return;
}
 
path.push_back(n);
 
trace(n);
reverse(path.begin(), path.end());
 
cout << path.size() << endl;
 
f(0,path.size(),i){
    cout << path[i] << " ";
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
 
       solve();
 
       return 0;
}



// <-----------------------------------------------------------------------DYNAMIC PROGRAMMING+DFS-------------------------------------------------------------------------------------->


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

vector<vector<ll>> graph(MAX_N); // adjacency list of tree


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


int dp[MAX_N];  // par[i][j] = 2^(j)th parent of ith node
vector<int> next_element;
int vis[MAX_N];

// preprocessing part  Dynamic Part TC: O(n*log(n))
void dfs(int source, int parent){

    vis[source]=1;

    // agar "n" ke aage koi vertex to usse explore karne ki jarorat nahi hain
    if(source==n) return;
    
    for(auto it: graph[source]){

            // if already explored 
            if(!vis[it]) dfs(it,source);

            // sirf wahi path dekhna jo "n" ko jaye
            if(dp[it]!=-1 && dp[source]<dp[it]+1)
            {
                dp[source]=dp[it]+1;
                next_element[source]=it;
            }
    }
}


void solve(){
    
    cin>> n >> m;

    // constructing the tree
    for(ll i=1;i<=m;i++){
    cin >> u >> v;
    graph[u].push_back(v); 
    }

    next_element.resize(n+1,-1);

    memset(dp,-1,sizeof(dp));

    dp[n]=1;    // sirf "n" wala path hi explore karna hain or koi nahi 

    dfs(1,-1);

    vector<int> path;

    path.push_back(1);

    int element = 1;

    for(int i = 0; i<dp[1]-1; i++){
        element=next_element[element];
        path.push_back(element);
    }

    if(find(path.begin(),path.end(),n)==path.end()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << dp[1] << endl;

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

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}

// <--------------------------------------SSLP TO SSSP NEGATIVE MONOTONIC DIJKSTRA'S------------------------------------------------------------>
// <------------------------------------------------TIME LIMIT EXCEEDED-------------------------------------------------------------------------------->
// <-----------------------------------------------USING PRIORITY QUEUE--------------------------------------------------------------------------------->


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
# define ll long long
 
// <----------------------------------------------SSLP TO SSSP NEGATIVE MONOTONIC DIJKSTRA'S------------------------------------------------------------------>
 
 
vector<pair<int,int>> graph[MAX_N];
 
 
ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;
 
 
int dp[MAX_N];  
int parent[MAX_N];
 
 
void solve(){
    
    cin>> n >> m;
 
    // constructing the tree
    for(ll i=1;i<=m;i++){
    cin >> u >> v;
    graph[u].push_back({v,-1});      // replacing each edge weight with "-1" thus converting problem from SSLP to SSSP
    }
 
   
 
    memset(dp,0,sizeof(dp));
    memset(parent,-1,sizeof(parent));
 
    
 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 
    pq.push({0,1});
    while(!pq.empty()){
        int vertex = (pq.top()).second;
        int dist = (pq.top()).first;
 
        pq.pop();
 
        if(dp[vertex]<dist) continue;   // check for repetitive checking avoids TLE
 
        for(auto it: graph[vertex]){
            int node = it.first;
            int weight = it.second;
            if(dp[node]>dp[vertex]+weight){
                dp[node]=dp[vertex]+weight;
                parent[node]=vertex;
                pq.push({dp[node],node});
            }
        }
    }
 
 
    // if "n" not get visited
    if(dp[n]==0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
 
    cout << -dp[n]+1 << endl;
 
    vector<int> next_element;
 
    next_element.push_back(n);
 
    int element = n;
 
    while(parent[element]!=-1){
        element=parent[element];
        next_element.push_back(element);
    }
 
    reverse(next_element.begin(),next_element.end());
 
 
    for(auto it: next_element){
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
 
ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
 
     solve();
       return 0;
}

// <----------------------------------------------SSLP TO SSSP NEGATIVE MONOTONIC DIJKSTRA'S------------------------------------------------------------------>
// <----------------------------------------------------------------------- USING SET ------------------------------------------------------------------------------>
// <---------------------------------------------------------------TIME LIMIT EXCEEDED-------------------------------------------------------------------------------------------->

// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

// <----------------------------------------------SSLP TO SSSP NEGATIVE MONOTONIC DIJKSTRA'S------------------------------------------------------------------>


vector<pair<int,int>> graph[MAX_N];


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


int dp[MAX_N];  
int parent[MAX_N];


void solve(){
    
    cin>> n >> m;

    // constructing the tree
    for(ll i=1;i<=m;i++){
    cin >> u >> v;
    graph[u].push_back({v,-1});      // replacing each edge weight with "-1" thus converting problem from SSLP to SSSP
    }

   

    memset(dp,0,sizeof(dp));
    memset(parent,-1,sizeof(parent));

    long long vis[MAX_N] = {0};

    set<pair<int,int>> st;

    st.insert({0,1});
    while(!st.empty()){
        int vertex = (*st.begin()).second;
        int dist = (*st.begin()).first;

        st.erase(st.begin());

        if(dp[vertex]<dist) continue;

        for(auto it: graph[vertex]){
            int node = it.first;
            int weight = it.second;
            if(dp[node]>dp[vertex]+weight){
                if(st.find({dp[node],node})!=st.end()) st.erase({dp[node],node});
                dp[node]=dp[vertex]+weight;
                parent[node]=vertex;
                st.insert({dp[node],node});
            }
        }
    }


    // if "n" not get visited
    if(dp[n]==0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }


    cout << -dp[n]+1 << endl;

    vector<int> next_element;

    next_element.push_back(n);

    int element = n;

    while(parent[element]!=-1){
        element=parent[element];
        next_element.push_back(element);
    }

    reverse(next_element.begin(),next_element.end());


    for(auto it: next_element){
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

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}









