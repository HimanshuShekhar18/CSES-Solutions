#include <bits/stdc++.h>
using namespace std;

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


void solve(){


        int n;
        cin >> n;

        int x;
        cin >> x;


        vector<int> arr(n);

        for(int i = 0; i<n/2; i++){
            cin >> arr[i];
        }

        for(int i = n/2; i<n; i++){
            cin >> arr[i];
        }

        int len1 = n/2;
        int len2 = n-n/2;

        //Custom hash is used to increase the efficiency of hashing containers and avoid Hash Collisions
        unordered_map<long long, long long, custom_hash> mp;

        for (int i = 0; i < (1<<len1); ++i)
        {
            long long sum = 0;
            for(int j = 0; j<len1; j++){
                if(i & (1<<j)){
                    sum+=arr[j];
                }
            }
            mp[sum]++;
        }

        long long ans = 0;


        for (int i = 0; i < (1<<len2); ++i)
        {
            long long sum = 0;
            for(int j = 0; j<len2; j++){
                if(i & (1<<j)){
                    sum+=arr[len1+j];
                }
            }
            if(mp.count(x-sum)) ans+=mp[x-sum];
        }

        cout << ans << endl;

    }


int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

       solve();

       return 0;
}


