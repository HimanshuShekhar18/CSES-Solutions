// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

// <--------------------------------------CONCEPT OF FUNCTIONAL GRAPH------------------------------------------------------->


ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;


int vis[MAX_N];
int next_element[MAX_N];
int steps;
int pathlength[MAX_N];
queue<int> path;

void dfs(int source){

    // add planet to path
    path.push(source);
    if(vis[source]){
        // add pathlength of the repeat planet to current step count
        steps+=pathlength[source];
        return;
    }
    steps++;
    vis[source]=1;

    dfs(next_element[source]);
}



void solve(){
    
    cin>> n;

    // constructing the tree
    for(int i=1;i<=n;i++){
       cin>>next_element[i];
    }

    memset(vis,0,sizeof(vis));
    
   
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            steps=0;
            dfs(i);

            int decrement = 1;
            // for each planet in current path, calculate pathlength
            while(!path.empty()){

                // we are in the cycle; all nodes have same pathlength
                if(path.front()==path.back()) decrement=0;

                pathlength[path.front()]=steps;
                steps-=decrement;
                path.pop();
            }
        }
    }

    for(int i = 1; i<=n; i++)
{
    cout << pathlength[i] << " ";
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
