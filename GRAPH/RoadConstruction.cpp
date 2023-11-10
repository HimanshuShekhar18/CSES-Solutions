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

ll parent[MAX_N];
ll sz[MAX_N];

void make(int val){
    parent[val]=val;
    sz[val]=1;
}

int find(int val){
    if(val==parent[val]) return val;
    return parent[val] = find(parent[val]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by size
        if(sz[a]<sz[b]) swap(a,b);
        parent[b] = a;
        sz[a]+=sz[b];
    }
}

void solve(){
    ll n,m;
    in2(n,m);


       for(int i = 1; i<=n; i++){
        make(i);
    }

    ll maxi = 1;
    ll number = n;

    
        for(int i{}; i<m; i++){

        int u , v;

        cin >> u >> v;

        if(find(u)==find(v)){
            cout << number << " " << maxi << endl;
            continue;
        }
        Union(u,v);
        maxi = max({maxi,sz[parent[u]],sz[parent[v]]});  // changes done here keep noted
        number--;
        cout << number << " " << maxi << endl;
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





// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


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

ll parent[MAX_N];
ll sz[MAX_N];

void make(int val){
    parent[val]=val;
    sz[val]=1;
}

int find(int val){
    if(val==parent[val]) return val;
    return parent[val] = find(parent[val]);
}

ll Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by size
        if(sz[a]<sz[b]) swap(a,b);
        parent[b] = a;
        sz[a]+=sz[b];
    }
    return sz[a];
}

void solve(){
    ll n,m;
    in2(n,m);


       for(int i = 1; i<=n; i++){
        make(i);
    }

    ll maxi = 1;
    ll number = n;

    
        for(int i{}; i<m; i++){

        int u , v;

        cin >> u >> v;

        if(find(u)==find(v)){
            cout << number << " " << maxi << endl;
            continue;
        }
        ;
        maxi = max(maxi,Union(u,v));  // changes done here keep noted
        number--;
        cout << number << " " << maxi << endl;
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
