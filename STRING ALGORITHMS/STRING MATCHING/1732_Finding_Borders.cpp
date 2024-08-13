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




void solve(){
 
        string S;
        cin >> S; 

        l = 0, r = 0;

        i = 1;

        n = S.length();

        vector<long long> Z(n+1,0);

        while(i<n){

            if(i<=r){
                Z[i] = min(r-i+1,Z[i-l]);
            }

            while(S[Z[i]]==S[i+Z[i]]){
                Z[i]++;
            }

            if(r-i+1<Z[i]){
                l=i;
                r=i+Z[i]-1;
            }
            i++;
        }

        for(int i = n-1; i>0; i--){
            if(n-i==Z[i]) {
                cout << Z[i] << " ";
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



ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     
       solve();


       return 0;
}
