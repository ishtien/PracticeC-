#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countIntersections(vector<int> startsAt, vector<int> endsAt) {
    int sz = startsAt.size();
    vector<int> res(sz, 0);
    vector<int> startCopy(startsAt.begin(), startsAt.end());
    vector<int> endCopy(endsAt.begin(), endsAt.end());
    sort(startCopy.begin(), startCopy.end());
    sort(endCopy.begin(), endCopy.end());

    for(int i = 0; i < sz; i++) {
        // end before i starts
        auto it1 = lower_bound(endCopy.begin(), endCopy.end(), startsAt[i]);
        int idx1 = distance(endCopy.begin(), it1);

        // start after i ends
        auto it2 = upper_bound(startCopy.begin(), startCopy.end(), endsAt[i]);
        int idx2 = distance(it2, startCopy.end());
        cout << idx1 << " " << idx2 << endl;
        res[i] = sz-1 - idx1 -idx2;
    }

    return res;
}

int main(){
    vector<int> startsAt = {3,1,5}; // 1, 3, 5
    vector<int> endsAt = {3, 5, 6}; // 3, 5, 6
    vector<int> output = countIntersections(startsAt, endsAt);
    for(auto & o : output) {
        cout << o << endl;
    }
}