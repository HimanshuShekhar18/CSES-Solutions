// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 100000;
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long

/*

DIJKSTRA's 
Single Source (Kth) Shortest Path Problem


*/


void solve(){
    ll n,m,k;
    in2(n,m);
    in(k);
    
    // create graph
    vector<pair<int,int>> graph[n+1];
    
        for(int i{}; i<m; i++){

        int a{},b{},c{};

        cin >> a >> b >> c;

        graph[a].push_back({b,c});

    }

    // dp[n][k-1]
    vector<vector<ll>> dp(n+1,vector<ll> (k,INF));

// priority queue {cost,vertex}
 priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

pq.push({0,1});

while(!pq.empty()){
    ll d = pq.top().first;  // dist
    ll u = pq.top().second; // vertex

    pq.pop();

    if(dp[u][k-1]<d) continue;

    for(auto e: graph[u]){
        int v = e.first;   // reach vertex
        int c = e.second;  // cost

        if(dp[v][k-1]>c+d){
            dp[v][k-1] = c+d;
            pq.push({dp[v][k-1],v});
            sort(dp[v].begin(),dp[v].end());
        }
    }
}



for(int i = 0; i < k; ++i)
    {
        cout << dp[n][i] << " ";
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
