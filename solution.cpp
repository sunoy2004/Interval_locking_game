#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N+2);
    for(int i=1;i<=N;i++) cin >> A[i];

    vector<vector<int>> start(N+2);
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        start[l].push_back(r);
    }

    multiset<int> active;
    long long locked = 0;
    long long current_gain = 0;

    for(int i=1;i<=N;i++){
        for(int r : start[i]) active.insert(r);

        while(!active.empty() && *active.begin() < i)
            active.erase(active.begin());

        if(!active.empty()){
            current_gain += A[i];
            if(current_gain >= 0){
                locked += A[i];
            } else {
                // rollback: do not lock this point
                current_gain -= A[i];
            }
        }
    }

    long long total = 0;
    for(int i=1;i<=N;i++) total += A[i];

    cout << total - locked << "\n";
}