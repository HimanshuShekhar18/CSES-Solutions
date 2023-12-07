#include <iostream>
#include <vector>
using namespace std;


//<---------------------------------------------------------------SINGLE DFS OR DYNAMIC PROGAMMING------------------------------------------------------------------------------>

const int MAX_N = 200 * 1000 + 13;

vector<int> adj[MAX_N]; // Adjacency list representation
int depth[MAX_N], ans[MAX_N];

// Time Complexity: O(n)

void dfs(int s, int par) {
    int m1 = -1, m2 = -1;

    // Iterate through the children of s
    for (int i = 0; i < adj[s].size(); i++) {
        int ch = adj[s][i];
        if (ch != par) {
            dfs(ch, s);
            // Update m1 and m2
            if (depth[ch] >= m1) {
                m2 = m1;
                m1 = depth[ch];
            } else if (depth[ch] > m2) {
                m2 = depth[ch];
            }
        }
    }

    // Update depth and ans for the current node
    depth[s] = m1 + 1;
    ans[s] = m1 + m2 + 2;
}

int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

    
    int n;
    cin >> n;


    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1); // Assuming the root of the tree is at node 0

    // Find the maximum diameter in ans array
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, ans[i]);
    }
    // Output the result (diameter of the tree)
    cout << res << endl;
    return 0;
}




// <------------------------------------------------------------------------TWO DFS APPROACH---------------------------------------------------------------------------------------------->



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200 * 1000 + 13;

vector<vector<int>> v(MAX_N);
vector<bool> visited(MAX_N);
vector<int> depth(MAX_N);
int farthestNode, maxDepth;


// TWO DFS APPROACH: TC: O(n)
void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;

    if (d > maxDepth) {
        maxDepth = d;
        farthestNode = node;
    }

    for (int child : v[node]) {
        if (!visited[child]) {
            dfs(child, d + 1);
        }
    }
}

int findDiameter(int startNode) {
    fill(visited.begin(), visited.end(), false);
    fill(depth.begin(), depth.end(), 0);

    maxDepth = -1;
    dfs(startNode, 0);

    int nodeA = farthestNode;

    fill(visited.begin(), visited.end(), false);
    fill(depth.begin(), depth.end(), 0);

    maxDepth = -1;
    dfs(nodeA, 0);

    return maxDepth;
}

int main() {


    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // Step 1: Assume any node 'a' as the root
    int rootNode = 1;

    int diameter = findDiameter(rootNode);

    cout << diameter << endl;

    return 0;
}
