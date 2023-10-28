// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
 
vector<int> graph[MAX_N];
 
long long dp[MAX_N];
long long dp2[MAX_N][5];
 
 
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
 
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
# define npos string::npos
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
# define memseti(array) memset(array, -1, sizeof(array));
 
 
ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;
 
/*/-----------------------------Code begins----------------------------------/*/
 
// GOOGLE
// void testcase(ll T) {cout << "Case #" << T << ": ";}
 
const int MAXK = 25;
 
vector<ll> bit(MAX_N+1,0);
 
void update(ll k, ll val){
    while(k<=n){
        bit[k]+=val;
        k+=(k&(~k+1));
    }
}
 
ll sumquery(ll k){
    ll res = 0;
    while(k>0){
        res+=bit[k];
        k-=(k&(~k+1));
    }
    return res;
}
 
 
 
 
void solve(){
 
      in(n);
 
              ll arr[n+1];
              for (ll i = 1; i <= n; ++i)
              {
                  cin >> arr[i];
                  update(i,1);
              }
 
              ll position[n];
              for (ll i = 0; i < n; ++i)
              {
                  cin >> position[i];
              }
 
f(0,n,i){
            ll lo=1, hi=n, mid;
while(lo<hi)
{
  mid=lo+(hi-lo)/2;
  ll tmp=sumquery(mid);
  // tmp is prefix sum till mid
  // tmp==x for first time
  if(tmp<position[i])
   lo=mid+1;
 else//tmp>=x
  hi=mid;
}
 
// lo-->pref(lo)==x for the first time..
cout<<arr[lo] << " ";
update(lo,-1);
 
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
 
    
       solve();
       return 0;
}
