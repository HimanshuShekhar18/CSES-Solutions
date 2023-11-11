// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200000+15;
 
# define f(a,n,i) for(int i = a; i<n; i++)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define ll long long


// HAMILOTIAN FLIGHTS: Visits Node only Once and find routes to n
// Basically the Question is to find No. of HAMILTONIAN PATHS EXIST 
// that's a DP Question but kaise lagega that's important

/*

eg: 

     1 ------->2↘ 
     |       ↗ ↓ ↘
     |     ↗   ↓   ↘
     |   ↗     ↓     ↘
     ↓ ↗       ↓       ↘
     3<---------         ↘
     ↓                     ↘
     ↓                       ↘
     ↓                         ↘
     --------------------------> 4

ans: 2
1-->2-->3-->4
1-->3-->2-->4

*/


/*

Using Visited Array and Recursion and Backtracking TC: O(n!) 
So iss Visited Array jo state hain usko Bitmask kardo 'n' bits ka mask bcoz 'n' Nodes hain 
1-->2-->3 and 1-->3-->2 so here mask is same 111 But Ending cities are different firstly 3 and latter 2,              
so we use dp[mask][ending city]

*/

ll n,m;

vector<int> graph[25];  
ll dp[1<<20][20];  // changes done here 

// time complexity: O(2^n*(n+m))
// for complexte graph m = n^2;
// time complexity: O(2^n*n^2)
ll dfs(int node, int mask){
    // reached at node n after visiting all nodes once
    if(__builtin_popcount(mask)==n) return 1;
    // reached at node n not visiting all nodes
    else if(node==n-1) return 0;
    if(dp[mask][node]!=-1) return dp[mask][node];
    ll ans = 0;
    for(auto it: graph[node]){
        if(mask&(1<<it)) continue;
        ans=(ans+dfs(it,mask|(1<<it)))%MOD;
    }

    return dp[mask][node]=ans%MOD;
}

// we have to do in 0-based indexing 

void solve(){
    
    in2(n,m);

    
        for(int i = 1; i<=m; i++){

        int u , v;

        cin >> u >> v;
        u--; // 0-based indexing 
        v--; // 0-based indexing 
        graph[u].push_back(v);
        
    }

    memset(dp,-1,sizeof(dp));

    ll res = dfs(0,1);
    cout << res << endl;

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
