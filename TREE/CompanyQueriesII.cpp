// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

// <---------------------------------------------------------------LCA USING BINARY LIFTING--------------------------------------------------------------------------------------->


vector<vector<int>> graph;

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;

int jump;
vector<int> vis;
vector<int> depth;   // storing depth for each node
int dp[MAX_N][31];  // par[i][j] = 2^(j)th parent of ith node

// preprocessing part  Dynamic Part TC: O(n*log(n))
void build(int source, int parent){

    vis[source]=true;
    dp[source][0] = parent;
    for(int j = 1; j<=jump; j++){
        if(dp[source][j-1]==-1){
            dp[source][j]=-1;
        }
        else{
            dp[source][j]=dp[dp[source][j-1]][j-1];
        }    
    }

    for(auto it: graph[source]){
        if(!vis[it]){
        depth[it]=depth[source]+1;
        build(it,source);
        }
    }
}

// k-->jump-->binary representation

// TC: O(log(k))
int binarylifting(int node, int k ){
    // higher jumps pehle then lower jumps
    for(int j = jump; j>=0; j--){
        if((1<<j)&k){ //jth bit set or not in k..
            node = dp[node][j]; //jump of 2^j
            k-=(1<<j);
            if(node==-1) return -1; 
            // agar -1 agaya to or jump ki no requirement, wahi se return ho jao 
        }
    }
    return node;
}

void solve(){
    
    cin>> n >> q;

    depth.resize(n+1,0);

    graph.resize(n+1);

    // constructing the graph
    for(int i = 2; i<=n; i++){
            cin >> u;
            graph[u].push_back(i);
            graph[i].push_back(u);
    }

    vis.resize(n+1,false);

    depth[1]=0;

    // don't forget to take log to the base 2
    jump=log2(n)+1; //max possible jump req to reach a parent (You can also take x=30)

    fill_n(&dp[0][0], MAX_N*31, -1);

    build(1,-1);   

    // q*log(jump)
    while(q--){
        cin>>a>>b;
        if(depth[a]>depth[b]){
            swap(a,b);
        }

        d = depth[b]-depth[a];
        // equalizing the depth
        b = binarylifting(b,d);

        // now a and b are at the same level or depth
        // just check they are not on the same path
        if(a==b)
        {
            cout << a << endl;
            continue;
        }
        for(int j = jump; j>=0; j--){
            if(dp[a][j]!=dp[b][j]){
                a = dp[a][j];
                b = dp[b][j];
            }
        }

        cout << dp[a][0] << endl;
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

