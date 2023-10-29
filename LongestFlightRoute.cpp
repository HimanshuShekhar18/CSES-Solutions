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
