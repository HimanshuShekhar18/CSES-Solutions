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

vector<pair<long long,pair<long long,long long>>> graph;

# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define in3(a,b,c) cin>>a>>b>>c
# define in4(a,b,c,d) cin>>a>>b>>c>>d
# define ll long long

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;

/*
Not a Conventional SSSP Problem
*/


void solve(){

     in2(n,m);

    for(int i=0;i<m;i++){
    long long x,y,w;
    cin>>x>>y>>w;
    graph.push_back({x,{y,w}});
}

  long long dist[n+1];
  fill(dist,dist+(n+1),INF);
  vector<long long> parent(n+1,0);
  dist[1]=0;
  for(int i = 0; i<n; i++){
    x = -1;

    for(auto it: graph){
      int first = it.first;
      int second = it.second.first;
      int weight = it.second.second;
      
      // changes done here
      /*
      "if(dist[u] >= infinity) continue"
      the above line is not needed in this question because graph can be disconnected and in 
      the disconnected part may contain a graph and cycle so we have to take all the vertex into account ,
      with this check we will not consider those vertex which are not reachable form the starting vertex so we omit this check.
      
      eg: 
      4 5
      1 1 0
      2 1 3
      2 2 -1
      3 4 3
      4 2 6
      */
      if(dist[second]>dist[first]+weight){
        dist[second]=dist[first]+weight;
        parent[second]=first;
        x = second;
      }
      // dist INF se jyada nahi hona chahiye
      dist[second]=min(dist[second],INF);
    }
  }

   
  if(x==-1) {
    cout << "NO" << endl;
    return;
  }
  else 
  {
      vector<int> cycle;
      cout << "YES" << endl;

      // changes done here
      /* IMPORTANT:
      moving the variable x to a specific position in the graph before starting the cycle detection. 
      The idea is to find a vertex that is part of the cycle.
      After the loop, x will be pointing to a vertex that is n steps away from the starting vertex of the cycle.
      This step is important to ensure that the subsequent traversal of the cycle captures the entire cycle and doesn't miss any vertices.
      */
      // Capture a Vertex that is part of -ve cycle and  not that vertex coming out of -ve cycle
      for(int i = 1; i <= n; ++i)
        {
            x = parent[x];
        }

    for(int v = x; ; v = parent[v])
        {
            cycle.push_back(v);
            if(v==x && cycle.size()>1) break;
        }

      // changes done here
      reverse(cycle.begin(),cycle.end());

    for(auto it: cycle){
    cout << it << " ";
    }
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

// time_t timetoday
//    time (&timetoday);
//    cout << asctime(localtime(&timetoday)) << endl;
//    // return 0;

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}
