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




ll n,m;
string ans = "";
unordered_set<string> st;

// TIME COMPLEXITY: O(2^n + n - 1)

// dfs traversal
void dfs(string node){
    
for(int i = 0; i<2; i++){
    string u = node+to_string(i);
    if(st.find(u)==st.end()){
            st.insert(u);
            dfs(u.substr(1));
            ans+=to_string(i);
    }
}


}



void solve(){
    
    in(n);


    string start(n-1,'0');
    dfs(start);
    ans = ans+start;

    reverse(ans.begin(),ans.end());

    cout << ans << endl;

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
