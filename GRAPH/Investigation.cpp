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

/*

MODIFIED DIJKSTRA's


*/


void solve(){
    ll n,m;
    in2(n,m);

   
    // create graph
    vector<pair<int,int>> graph[n+1];
    
        for(int i{}; i<m; i++){

        int a{},b{},c{};

        cin >> a >> b >> c;

        graph[a].push_back({b,c});

    }

    ll dist[n+1];
    fill(dist, dist + n+1, INF);


// priority queue {cost,vertex}
priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;


pq.push({0,1});


ll routes[n+1]; // to save how many shortest path
ll min_flight[n+1]; // to save min-flight in that shortest path
ll max_flight[n+1]; // to save max-flight in that shortest path


fill(routes, routes + n+1, 0);
fill(min_flight, min_flight + n+1, 0);
fill(max_flight, max_flight + n+1, 0);

routes[1] = 1;
dist[1] = 0;


while(!pq.empty()){
    ll d = pq.top().first;  // dist
    ll u = pq.top().second; // vertex

    pq.pop();

    for(auto e: graph[u]){
        int v = e.first;   // reach vertex
        int c = e.second;  // cost


        // case 1:
        // suboptimal do nothing
        if(c + d > dist[v]) continue;


        // case 2:
        // Same Optimal
        if(c + d == dist[v]){
            routes[v]+=routes[u];
            routes[v]%=MOD;
            min_flight[v] = min(min_flight[u]+1,min_flight[v]);
            max_flight[v] = max(max_flight[u]+1,max_flight[v]);
        }


        // case 3:
        // NEW OPTIMAL
        if(dist[v]>c+d){
            dist[v] = c + d;
            routes[v]=routes[u]; // the only optimal path to V is only via U.
            min_flight[v] = min_flight[u]+1;
            max_flight[v] = max_flight[u]+1;
            pq.push({dist[v],v});
        }
    }
}


cout << dist[n] << " " << routes[n] << " " << min_flight[n] << " " << max_flight[n] << endl;
 
 
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
