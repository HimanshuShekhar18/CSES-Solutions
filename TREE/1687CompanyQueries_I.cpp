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

int jump;
int par[MAX_N][31];  // par[i][j] = 2^(j)th parent of ith node

// preprocessing part  Dynamic Part TC: O(n*log(n))
void dfs(int source, int parent){

    par[source][0]=parent;
    for(int j = 1; j<=jump; j++){
        if(par[source][j-1]==-1){
            par[source][j]=-1;
        }
        else{
            par[source][j]=par[par[source][j-1]][j-1];
        }        
    }

    for(auto it: graph[source]){
        if(it!=parent){
            dfs(it,source);
        }
    }
}

// k-->jump-->binary representation

// TC: O(log(k))
int binarylifting(int node, int k ){
    for(int j = jump; j>=0; j--){
        if((1<<j)&k){ //jth bit set or not in k..
            node = par[node][j]; //jump of 2^j
            k-=(1<<j);
            if(node==-1) return -1;
        }
    }
    return node;
}

void solve(){
    
    cin>> n >> q;

    // constructing the tree
    for(ll i=2;i<=n;i++){
    cin >> x;
    graph[x].push_back(i); 
    }

    // don't forget to take log to the base 2
    jump=log2(n)+1; //max possible jump req to reach a parent (You can also take x=30)

    fill_n(&par[0][0], MAX_N*31, -1);
    
    dfs(1,-1);

    // q*log(k)
    while(q--){
        cin>>x>>k;
        cout << binarylifting(x,k) << endl;
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

