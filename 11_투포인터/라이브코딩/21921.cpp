#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;


ci calcMaxVisitor(vector<int> &visitor, int n, int x) {
    
    int cnt_visitor = 0; 
    int cnt_period = 1;
    for  (int i = 0; i < x; i++) { 
        cnt_visitor += visitor[i];
    }
    int max_visitor = cnt_visitor; 

    for (int i = x; i < n; i++) { 
    
        cnt_visitor -= visitor[i - x]; 
        cnt_visitor += visitor[i]; 

        if (cnt_visitor > max_visitor) {
            max_visitor = cnt_visitor;
            cnt_period = 1;
        } else if (cnt_visitor == max_visitor) {
            cnt_period++;
        }
    }
    return {max_visitor, cnt_period};
}

int main() {
    int n, x;

    cin >> n >> x;
    vector<int> visitor(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> visitor[i];
    }

    ci answer = calcMaxVisitor(visitor, n, x);

    if (answer.first == 0) {
        cout << "SAD\n";
        return 0;
    }

    cout << answer.first << '\n' << answer.second;
    return 0;
}
