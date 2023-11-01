// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
 
// <-------------------------------------------------BELLMANN FORD ALGORITHM--------------------------------------------->
// LONGEST PATH Finding THIS TIME
// But We will store with negation of each weights and 
// convert this problem to shortest path finding
// SSLP TO SSSP
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const long long NINF = -1e15;
const int MAX_N = 200 * 1000 + 13;
 
 
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
void solve(){
    ll n,m;
    in2(n,m);
 
vector<pair<long long,pair<long long,long long>>> edges;
 
for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
    edges.push_back({x,{y,-w}});
}
 
long long dist[3000];
fill(dist, dist + 3000, INF);
dist[1] = 0;
 
 
for(int i=1; i<=n-1; i++)
{
     for(auto e: edges)
     {
       int u=e.first;
       int v=e.second.first;
       int w=e.second.second;
       if(dist[u]==INF) continue;
       if(dist[u]+w<dist[v])
        {    // relaxation
             dist[v]=dist[u]+w;
        }
 
        // reset karna hain agar dist[v] NINF se kam hogaya ho
 
        dist[v]=max(dist[v],NINF);
     }
}
 
// Check for negative weight cycle including every nodes
// checking whether source and destination are part of that -ve cycle or not.
 
for(int i=1; i<=n; i++)    // changes done here
{
     for(auto e: edges)
     {
       int u=e.first;
       int v=e.second.first;
       int w=e.second.second;
       if(dist[u]==INF) continue;
       if(dist[u]+w<dist[v])
        {    // relaxation
             dist[v]=NINF;
        }
     }
}
 
if(dist[n]==NINF) {
    cout << -1 << endl;
    return;
}
 
cout << -dist[n] << endl;
 
 
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



// <-----------------------------------------------------------------------------------2nd Approach------------------------------------------------------------------------------------>



// 2) APPROACH --> Basically checking whether 1 and n both are the part of negative weight cycles

// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
 
// <-------------------------------------------------BELLMANN FORD ALGORITHM--------------------------------------------->
// LONGEST PATH Finding THIS TIME
// But We will store with negation of each weights and 
// convert this problem to shortest path finding
// SSLP TO SSSP

 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
 
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long

int vis1[MAX_N];
int visn[MAX_N];
vector<int> a[MAX_N];
vector<int> b[MAX_N];

 
// visited mark karne ke liye for both from 1 and from n
void dfs(vector<int> arr[], int node, int vis[]){
    vis[node]=1;
    for(auto it: arr[node]){
        if(vis[it]) continue;
        dfs(arr,it,vis);
    }
} 



void solve(){
    ll n,m;
    in2(n,m);
 
vector<pair<long long,pair<long long,long long>>> edges;

 
for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
    a[x].push_back(y);   // from 1 ke liye
    b[y].push_back(x);   // from n ke liye
    edges.push_back({x,{y,-w}});
}


/*


4 4
1 2 1
2 3 1
3 2 1
1 4 1
4 2 1

// original graph         
and "a" vector                "b" vector
1----->4                     1<------4                               
↓    ↙                       🠁     ↗                          
↓  ↙                         🠁   ↗                     
↓↙                           🠁 ↗                      
2----->3                     2<-------3                           
↑      🠃                     🠃        ↑
⤌⤌⤌⤌⤌                     ⤍⤍⤍⤍⤍⤍


hence ans is 1;



With the same example Let just invert the edge b/w 2 and 4
4 4
1 2 1
2 3 1
3 2 1
1 4 1
2 4 1

// original graph         
and "a" vector                "b" vector
1----->4                     1<------4                               
↓    ↗                       🠁     ↙                          
↓  ↗                         🠁   ↙                     
↓↗                           🠁 ↙                      
2----->3                     2<-------3                           
↑      🠃                     🠃        ↑
⤌⤌⤌⤌⤌                     ⤍⤍⤍⤍⤍⤍


hence ans is -1;


        

*/


memset(vis1,0,sizeof(vis1));
memset(visn,0,sizeof(visn));

dfs(a,1,vis1);  // from 1 se traverse karke visit marna 
dfs(b,n,visn);  // from n se traverse karke visit marna
  
long long dist[3000];
fill(dist, dist + 3000, INF);
dist[1] = 0;
 
 
for(int i=1; i<n; i++)
{
     for(auto e: edges)
     {
       int u=e.first;
       int v=e.second.first;
       int w=e.second.second;
       if(dist[u]+w<dist[v])
        {    // relaxation
             dist[v]=dist[u]+w;
        }
     }
}
 
for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second.first;
        int weight = edges[i].second.second;
        if(dist[u]==INF) continue;
        if (vis1[u] && visn[v] && dist[u]+weight < dist[v]) {
            cout << -1 << endl;
        return;
        }
}
 
cout << -dist[n] << endl;
 
 
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





