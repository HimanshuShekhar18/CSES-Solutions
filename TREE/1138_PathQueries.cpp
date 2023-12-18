// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 600000;   // changes done here

# define ll long long

// <---------------------------------------------EULER TOUR TREE and SEGMENT TREE-------------------------------------------------->

vector<long long> graph[MAX_N];


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi,val;
bool flag;
string str;

/*

        Actual Graph

        let value = {1,2,3,4,5}

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
            4(4)      5(5)

    path = {1,2-2,3,4,-4,5,-5,-3,-1}


    LET DESIGN THE SEGMENT TREE FOR ABOVE THE GRAPH


                          1(0)
                        /     \
                       /       \
                      /         \
                     /           \
                    2(8)          3(-8)
                   / \              /  \
                  /   \            /    \
                 /     \          /      \
                /       \        6(-7)    7(-1)
               /         \         /  \        
              4(3)        5       /    \
             /   \        (4)    /      \
            /     \            12(1)    13(-8)
           /       \            / \       /  \
          8(3)      9(1)       /   \     /    \
         / \        / \       /     \ 26(-5)   \
        /   \      /   \   24(-4)    \          \
       /     \    /     \             \        27(-3)
      /       \  18(-2)  19(3)        25(5)
     16       17  
    (1)       (2)

    ALL THE LEAF NODE WILL CONTAIN THE VALUE OF NODES IN ORDER OF EULER TOUR TREE TRAVERSAL.

*/


ll in[MAX_N];   // for EULER TOUR TREE
ll out[MAX_N];

ll value[MAX_N];     // for storing value of each node

// changes done here
ll seg[800000];    // 800000 set karo iss baar size bara hain !!!!!!

vector<ll> path;

ll timer;


// EULER TOUR TREE
void dfs(ll source, ll parent){

    in[source]=timer;   // entry time or yahi use karunga segment tree mein 
    // range decide karenga mera ye

    timer++;

    path.push_back(value[source]);    // entry ke time

    for(auto it: graph[source]){
        if(it!=parent){
            dfs(it,source);
        }
    }

    path.push_back(-1*value[source]);   // exit ke time

    out[source]=timer;
    timer++;
}

void build(ll l = 0, ll r = path.size(), ll id = 1){
    if(r-l==1){
        seg[id]=path[l];   // Value Stored in Order of EULER TOUR TREE
        return;
    }

    ll mid = l+(r-l)/2;

    build(l,mid,2*id);
    build(mid,r,2*id+1);

    seg[id]=seg[2*id]+seg[2*id+1];

}

// time complexity: O(log(n))
void modify(ll pos, ll value, ll l = 0, ll r = path.size(), ll id = 1){

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
ll query(ll x, ll y, ll id = 1, ll l = 0, ll r = path.size()){
    if(l>=x && r<=y) return seg[id]; // When [L,R) is entirely inside [x,y)
    if(r<=x || l>=y) return 0;   // When [L,R) is entirely outside [x,y)
 
    ll mid = l+(r-l)/2;
    return query(x,y,2*id,l,mid)+query(x,y,2*id+1,mid,r);
}


void solve(){
    
    cin>> n >> q;
    
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
            modify(out[u]-1,-val);
        }
        else {
            cin >> u;
            cout << query(0,in[u]) << endl;  
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
