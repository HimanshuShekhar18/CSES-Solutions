// हर हर महादेव
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
bool flag;
string str;
 
 
/*------------------------------functions----------------------------------*/
 
//Finding Nearest Power Of 2 Of Any Number--->O(log(n))
int near_pow(int q){
    int ans = (int)log2(q);
    return pow(2,ans);
}
 
ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}
 
ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
 
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}
 
 
// MEX of an ARRAY in O(N)
ll findmex(vector<ll> v, ll n){
    unordered_set<ll> s;
    for(int i=0;i<n+2; i++){
        s.insert(i);
    }
    for(auto val:v) if (s.find(val)!=s.end()) s.erase(val);
    return *min_element(s.begin(),s.end());
}
 
// next greater element
vector <int> ngt(vector <int> &v){
    int n=v.size();
    stack<int> s;
    vector <int> res(n,n);
    for(int i=0;i<n;i++){
        while (!s.empty() && v[s.top()]<v[i])
        {
            res[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}
 
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
 
 
 
// memset(array, 0, n * sizeof(array[0]));
 
 
/*/-----------------------------Code begins----------------------------------/*/
 
// GOOGLE
// void testcase(ll T) {cout << "Case #" << T << ": ";}
 
 
int vis[MAX_N];
int parent[MAX_N];
int dis[MAX_N];
 
void bfs(int node){
    vis[node] = 1;
    dis[node] = 1;
    parent[node]  = -1;
 
    queue<int> q;
 
    q.push(node);
 
    while(!q.empty()){
 
        int t = q.front();
        q.pop();
 
    for(auto child: graph[t]){
        if(!vis[child]){
            vis[child] = 1;
            dis[child] = dis[t]+1;
            parent[child] = t;  
            q.push(child);          
        }
    }
 
  }
 
  
}
 
 
void solve(){
 
 
        in2(n,m);
 
        f(0,m,i){
            in2(a,b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
 
        bfs(1);      
 
        if(dis[n]==0){
            cout << "IMPOSSIBLE" << endl;
            return;
        } 
 
        cout << dis[n] << endl; 
 
        vector<int> vect;
 
        vect.push_back(n);
 
        int node = parent[n];
 
        f(0,dis[n],i){
            
            if(parent[node]==-1) {
                vect.push_back(node);
                break;
            }
 
            vect.push_back(node);
            node = parent[node];
        }
 
        reverse(vect.begin(),vect.end());
 
 
        f(0,vect.size(),i){
            cout << vect[i] << " ";
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

