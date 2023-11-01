// 1) WITH VISITED ARRAY - AC

// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
// <---------------------------------------------------------------------Priority Queue (DIJKSTRA'S ALGORITHM)------------------------------------------------------------------------->
 
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<pair<long long,long long>> graph[MAX_N];
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
void solve(){
 
    ll n,m;
    in2(n,m);
 
 
 
for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
 
    graph[x].push_back({y,w});
}
 
 
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
long long dist[MAX_N];
fill(dist, dist + MAX_N, INF);
dist[1] = 0;
pq.push({0,1});
 
long long vis[MAX_N] = {0};
 
 
 
while(!pq.empty()){
 
 
 
    long long vertex = pq.top().second;
 
    pq.pop();
 
    if(vis[vertex]) continue;
    vis[vertex]  = 1;
 
    for(auto it: graph[vertex]){
        long long child = it.first;
        long long weight = it.second;
    if(dist[child]>dist[vertex]+weight){
        dist[child]=dist[vertex]+weight;
        pq.push({dist[child],child});
    }
}
}
 
 
 
for (int i = 1; i <= n; ++i)
{
    cout << dist[i] << " ";
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


// 2) WITH VISITED ARRAY - AC

// <---------------------------------------------------------------------SET(DIJKSTRA'S ALGORITHM)------------------------------------------------------------------------->
 
 
 
 
 
// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
 
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<pair<long long,long long>> graph[MAX_N];
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
void solve(){
    ll n,m;
    in2(n,m);
 
 
 
for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
 
    graph[x].push_back({y,w});
}
 
 
set<pair<long,long>> pq;
long long dist[MAX_N];
fill(dist, dist + MAX_N, INF);  // changes done here INFINITY karo
dist[1] = 0;
pq.insert({0,1});
 
long long vis[MAX_N] = {0};
 
while(!pq.empty()){
 
 
 
    long  vertex = (*pq.begin()).second;
 
    pq.erase(pq.begin());
 
    if(vis[vertex]) continue;
    vis[vertex]  = 1;
 
 
    for(auto it: graph[vertex]){
        long long child = it.first;
        long long weight = it.second;
    if(dist[child]>dist[vertex]+weight){
        dist[child]=dist[vertex]+weight;
        pq.insert({dist[child],child});
    }
}
}
 
 
 
for (int i = 1; i <= n; ++i)
{
    cout << dist[i] << " ";
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



// 3) WITHOUT VISITED ARRAY


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
// <---------------------------------------------------------------------Priority Queue (DIJKSTRA'S ALGORITHM)------------------------------------------------------------------------->
// Time Limit Exceeded
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<pair<long long,long long>> graph[MAX_N];
 
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long
 
void solve(){
    ll n,m;
    in2(n,m);
 
 
 
for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
 
    graph[x].push_back({y,w});
}
 
 
 
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
long long dist[MAX_N];
fill(dist, dist + MAX_N, INF);
dist[1] = 0;
pq.push({0,1});
 
 
 
while(!pq.empty()){
 
 
 
    long long vertex = pq.top().second;
 
    pq.pop();
 
    for(auto it: graph[vertex]){
        long long child = it.first;
        long long weight = it.second;
    if(dist[child]>dist[vertex]+weight){
        dist[child]=dist[vertex]+weight;
        pq.push({dist[child],child});
    }
}
}
 
 
 
for (int i = 1; i <= n; ++i)
{
    cout << dist[i] << " ";
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


// 4) WITHOUT VISITED ARRAY - AC

// <---------------------------------------------------------------------SET(DIJKSTRA'S ALGORITHM)------------------------------------------------------------------------->


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */



#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

vector<pair<long long,long long>> graph[MAX_N];


# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long

void solve(){
    ll n,m;
    in2(n,m);



for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;

    graph[x].push_back({y,w});
}


set<pair<long,long>> pq;
long long dist[MAX_N];
fill(dist, dist + MAX_N, INF);  // changes done here INFINITY karo
dist[1] = 0;
pq.insert({0,1});



while(!pq.empty()){



    long  vertex = (*pq.begin()).second;

    pq.erase(pq.begin());

    for(auto it: graph[vertex]){
        long long child = it.first;
        long long weight = it.second;
    if(dist[child]>dist[vertex]+weight){
        if(pq.find({dist[child],child})!=pq.end()) pq.erase({dist[child],child});
        dist[child]=dist[vertex]+weight;
        pq.insert({dist[child],child});
    }
}
}



for (int i = 1; i <= n; ++i)
{
    cout << dist[i] << " ";
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


