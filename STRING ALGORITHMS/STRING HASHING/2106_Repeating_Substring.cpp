// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e15;
int P = 173;
#define ll long long 

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


/*-----------------------------------------------------------------functions--------------------------------------------------------------*/


string duplicateStringOfLengthMid(string& S, int mid) {
       
        int sp = 0;
        int ep = mid - 1;
        
        unordered_set<long long> set;
        long long curr_hash = 0;
        long long p_pow = 1;

        // ROLLING HASH or REVERSE HASHING
        for (int i = mid - 1; i >= 0; i--) {
            curr_hash = (curr_hash + ((S[i] - 'a' + 1) * p_pow)) % MOD;
            if (i == 0) break;
            p_pow = (p_pow * P) % MOD;
        }

        set.insert(curr_hash);
        sp++;
        ep++;

        // sliding window
        while (ep < n) {
            curr_hash = (curr_hash - ((S[sp - 1] - 'a' + 1) * p_pow) % MOD + MOD) % MOD;
            curr_hash = (curr_hash * P) % MOD;
            curr_hash = (curr_hash + (S[ep] - 'a' + 1));

            if (set.find(curr_hash) != set.end())
                return S.substr(sp, mid);
            set.insert(curr_hash);
            sp++;
            ep++;
        }
        return "";
}

void solve(){
 
        string S;
        cin >> S; 

        string result = "";
        int left = 0;
        int right = S.length();
        n = S.length();

        // Binary Search
        while (left <= right) {
            int mid = right - (right - left) / 2;
            string ans = duplicateStringOfLengthMid(S, mid);
            if (ans.length() > 0) {
                result = ans;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        

        if(result.length()==0){

            cout << -1 << endl;

        }
        else{
            cout << result << endl;
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
