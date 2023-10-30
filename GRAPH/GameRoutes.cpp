// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

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

// <-----------------------------------------------------------------SIMPLE DFS AND DYNAMIC PROGRAMMING------------------------------------------------------------------------------------>


long long ways[MAX_N];

long long dfs(long long node){
    if(node==n) {
      return 1;  
    } 
    if (ways[node] != -1) {
        return ways[node];
    }
    int ans{};
    for(auto child: graph[node]){
        ans=(ans+dfs(child))%MOD;
    }

    return ways[node] = ans%MOD;
}


void solve(){

    in2(n,m);

for(long long i=0;i<m;i++){
    long long x,y;
    cin>>x>>y;
    graph[x].push_back(y);
}

     memset(ways,-1,sizeof(ways));
     
     long long ans = dfs(1);

     cout << ways[1]%MOD << endl;

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
