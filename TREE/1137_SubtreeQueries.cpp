// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

// <---------------------------------------------EULER TOUR TREE and SEGMENT TREE-------------------------------------------------->

vector<long long> graph[MAX_N];


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi,val;
bool flag;
string str;

/*

        Actual Graph

            1(1)
           / \
          /   \
         /     \
        /       \
       2(2)      3(3)
                / \
               /   \
              /     \
             /       \
            4(4)      5 (5)


    LET DESIGN THE SEGMENT TREE FOR ABOVE THE GRAPH


                         1(15)
                        /  \
                       /    \
                      /      \
                     /        \
                    2(6)       3(9)
                   / \        / \
                  /   \      /   \
                 /     \    /     \
                /       \  6(4)    7(5)
               /         \                
              4(3)        5
             / \         (3)
            /   \
           /     \
          8       9
         (1)     {2)

    ALL THE LEAF NODE WILL CONTAIN THE VALUE OF EACH NODE IN ORDER OF EULER TOUR TREE.

*/


ll in[MAX_N];   // for EULER TOUR TREE
ll subtree[MAX_N];   // for subtree size
ll value[MAX_N];     // for storing value of each node
vector<ll> eulertourarray;  // euler tour traversal path
vector<ll> seg;

ll timer;


// EULER TOUR TREE
void dfs(ll source, ll parent){

    subtree[source]=1;
    in[source]=timer;   // entry time or yahi use karunga segment tree mein 
    // range decide karenga mera ye

    timer++;
    eulertourarray.push_back(source);
    for(auto it: graph[source]){
        if(it!=parent){
            dfs(it,source);
            subtree[source]+=subtree[it];
        }
    }
}

void build(ll l = 0, ll r = n, ll id = 1){
    if(r-l==1){
        seg[id]=value[eulertourarray[l]];   // Value Stored in Order of EULER TOUR TREE
        return;
    }

    ll mid = l+(r-l)/2;

    build(l,mid,2*id);
    build(mid,r,2*id+1);

    seg[id]=seg[2*id]+seg[2*id+1];
}

// time complexity: O(log(n))
void modify(ll pos, ll value, ll l = 0, ll r = n, ll id = 1){

    if(r-l==1){
        seg[id]=value;
        return;
    }

    ll mid = l+(r-l)/2;

    if(pos<mid){
        modify(pos,value,l,mid,2*id);
    }
    else {
        modify(pos,value,mid,r,2*id+1);
    }

    seg[id]=seg[2*id]+seg[2*id+1];
}

// Querying Operation 
// Time complexity: O(log n)
ll query(ll x, ll y, ll id = 1, ll l = 0, ll r = n){
    if(l>=x && r<=y) return seg[id]; // When [L,R) is entirely inside [x,y)
    if(r<=x || l>=y) return 0;   // When [L,R) is entirely outside [x,y)
 
    ll mid = l+(r-l)/2;
    return query(x,y,2*id,l,mid)+query(x,y,2*id+1,mid,r);
}


void solve(){
    
    cin>> n >> q;

    seg.resize(4*n+1);

    
    for(ll i=1;i<=n;i++){
        cin>> value[i];    
    }

    for(ll i = 1; i<n; i++){
        cin >> u>> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    timer = 1;

    dfs(1,-1);
    build();

    while(q--){
        ll type;
        cin >> type;
        if(type==1){
            cin >> u >> val;
            modify(in[u]-1,val);
        }
        else {
            cin >> u;
            cout << query(in[u]-1,in[u]-1+subtree[u]) << endl;   // simple change done here "-1" added
            // starting point: in[u]-1
            // ending point: in[u]-1+subtree[u]
        }
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
