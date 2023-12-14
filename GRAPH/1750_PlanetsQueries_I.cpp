// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

vector<int> graph[MAX_N];

# define ll long long

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


// DP ON GRAPHS
// <-------------------------------------------------BINARY LIFTING OR BINARY JUMPING----------------------------------------------------->

/*
Why so many TLE and WA
Ans:
Firstly Bcoz, this time jump depends on value of "k" not "n"
so jump = log(n)+1 --> WA


Second TLE, if I declare jump = 30 and pre-processing the parent, loop is running form 1 to jump(i.e. 30)
But, point is 2^31-1 = 30 bits ans 10^9(range of "k") = 29 bits
So our requirements is upto 29 bits so why are we pre-processing to 30th bit.

*/

int jump = 30;
vector<int> par;
int dp[MAX_N][30];


// preprocessing part  Dynamic Part TC: O(n*log(n))
void build(){

    for(int i = 1; i<=n; i++) dp[i][0] = par[i];
    for(int j = 1; j<jump; j++){   // loop runs upto 29 bits
        for(int i = 1; i<=n; i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];      
    }
  }
}


// TC: O(log(k))
int binarylifting(int node, int k ){
    // higher jumps pehle then lower jumps
    for(int j = jump-1; j>=0; j--){    // loop starts running from 29th bit
        if((1<<j)&k){ //jth bit set or not in k..
            node = dp[node][j]; //jump of 2^j
            k-=(1<<j);
        }
    }
    return node;
}


void solve(){

  cin >> n >> q;

  par.resize(n+1);

  memset(dp,0,sizeof(dp));

  

  for(int i = 1; i<=n; i++){
  
    cin >> par[i];
    
  }

  build();

  while(q--){
    cin >> u >> k;

    cout << binarylifting(u,k) << endl;
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

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}

