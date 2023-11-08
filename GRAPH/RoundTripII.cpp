/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<int> graph[MAX_N];
long long array[MAX_N];
long long dp[MAX_N];
long long dp2[MAX_N][5];
 
 
 
/* using mint = modular_int<mod>;
template<const int MOD>
vector<int> modular_int<MOD>::inverse_list ;
template<const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template<const int MOD>
const bool modular_int<MOD>::is_prime = true; */
// template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
// const int modular_int<mod>::inverse_limit = 100000;
 
 
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
 
#define inp(arr) for(auto& x:arr) cin >> x
#define inpvp(arr) for(auto& x:arr) cin >> x.first >> x.second;
#define out(arr) for(auto x: arr) cout << x << ' '; cout << endl 
#define outvp(vp) for(auto x: vp) cout << '(' << x.first << "," << x.second << "), "; cout << endl;
# define f(a,n,i) for(int i = a; i<n; i++)
# define fe(a,n,i) for(int i = a; i<=n; i++)
# define fje(a,n,i,j) for(int i = a; i<=n; i+=j)
# define fn(n,a,i) for(int i = n; i>=a; i--)
# define fme(s,n,i,a) for(int i = s; i<=n; i*=a)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define in3(a,b,c) cin>>a>>b>>c
# define in4(a,b,c,d) cin>>a>>b>>c>>d
# define ll long long
# define all(x) x.begin(), x.end()
# define sortall(x) sort(all(x))
# define pii pair<int, int>
# define pll pair<ll,ll>
typedef pair<int,pair<int,int>> pipii;
typedef pair<int,string> pis;
typedef pair<string,string> pss;
# define vl vector<ll> 
# define vi vector<int>  
# define vpii vector<pii>
# define vpll vector<pll>
# define array_size(arr) (sizeof(arr) / sizeof(*(arr)))
# define mpq priority_queue<ll,vector<ll>,greater<ll>>
typedef set<int> si;
typedef set<pll> spll;
# define mul multiset<ll>
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<string,int> msi;
typedef map<char,int> mci;
 
 
ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
 
string str;
 
 
  // detect a cycle in a directed graph using DFS
 
vector<int> vect;
int vis[MAX_N];
int pathvis[MAX_N];
 
int children;
bool flag = true;
 
bool dfs(int node){
   
vis[node] = 1;
pathvis[node] = 1;
    for(auto child: graph[node]){
        if(vis[child]==1 && pathvis[child]==1){
            vect.push_back(child);
            children=child;
            return true;
        } 
        else if(!vis[child]){
            
           if(dfs(child)) {
            if(child==children) flag = 0;
            if(flag) vect.push_back(child);
            
            return true;
        } 
    }
 }
 
 pathvis[node] = 0;
 
     return false;
 
}
 
 
void solve(){
 
 
 
    in2(n,m);
    f(0,m,i){
        in2(a,b);
        graph[a].push_back(b);
        
    }
 
  // detect a cycle in a directed graph using DFS
 
 
    f(1,n+1,i){
 
        if(!vis[i]){
 
 
    if(dfs(i)){
 
        
        vect.push_back(vect[0]);
        reverse(vect.begin(),vect.end());
        cout << vect.size() << endl;
 
        for(int j = 0; j<vect.size(); j++){
            cout << vect[j] << " ";
 
        }
 
        cout << endl;
        return;
    }
 
}
 
}
 
cout << "IMPOSSIBLE" << endl;
return;
 
 
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
 
// time_t timetoday;
//    time (&timetoday);
//    cout << asctime(localtime(&timetoday)) << endl;
//    // return 0;
 
ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    // cf();
      
 
       return 0;
}
