#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9 + 1;

ci findLiquid(int left, int right, vector<int> &liquid) {
    
    ci ans = {0, 0}; 
    int value = INF;


    while (left < right) {
        
        int mix = liquid[left] + liquid[right];

        
        if (mix == 0) {
            return {liquid[left], liquid[right]};
        }

        if (abs(mix) < value) {
            value = abs(mix);
            ans = {liquid[left], liquid[right]};
        }

        if (mix > 0) {
            right--;
        } else {  
            left++;
        }
    }

    return ans;
}

int main() {
    int n;

 
    cin >> n;
    vector<int> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    ci answer = findLiquid(0, n - 1, liquid);

    cout << answer.first << " " << answer.second;
    return 0;
}
