#include <iostream>
#include <vector>
using namespace std;

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
