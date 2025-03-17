#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    vector<int> container = {0};

   public:
    // heap이 비어있는지 확인
    bool isEmpty() {
        return container.size() == 1;
    }

    // heap에 x 삽입
    void push(int x) {
        // 현재 힙의 크기 = 새로 push할 데이터의 초기 인덱스
        int idx = container.size();

        // 힙의 마지막 자리에 x 삽입
        container.push_back(x);

        // 부모 노드와 비교하면서 부모 노드보다 큰 경우 swap
        while (idx > 1 && container[idx] > container[idx / 2]) {
            swap(container[idx], container[idx / 2]);  // 부모 노드와 swap
            idx /= 2;                                  // 현재 x의 인덱스도 변경
        }
    }

    // heap에서 가장 큰 값을 제거하고 그 값 반환
    int pop() {
        int item = container[1];  // 반환할 가장 큰 값 (루트 노드)

        // 가장 마지막에 있던 노드를 루트 노드로 옮겨줌
        container[1] = container[container.size() - 1];
        container.pop_back();  // 가장 마지막 노드 제거

        int size = container.size();
        int parent = 1, child = 2;

        // 자식 노드와 비교하면서 자식 노드보다 작은 경우 swap
        while (child < size) {
            // 오른쪽 자식 노드가 존재하는 경우, 두 개의 자식 노드 중 큰 값 선택
            if (child + 1 < size && container[child + 1] > container[child]) {
                child += 1;
            }

            // 부모 노드가 자식 노드보다 작은 경우 swqp
            if (container[parent] < container[child]) {
                swap(container[parent], container[child]);

                // 부모 노드와 자식 노드의 인덱스 업데이트
                parent = child;
                child = parent * 2;
            }
            // 부모 노드가 자식 노드보다 작지 않은 경우 더 이상 swap할 필요가 없음
            else {
                break;
            }
        }
        return item;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    MaxHeap max_heap;

    // 입력
    cin >> n;

    // 연산 & 출력
    while (n--) {
        cin >> x;

        // x가 0인 경우 heap에서 가장 큰 값 출력
        if (x == 0) {
            // heap이 비어있는 경우 0 출력
            if (max_heap.isEmpty()) {
                cout << "0\n";
            } else {
                cout << max_heap.pop() << "\n";
            }
        }
        // x가 자연수인 경우 max_heap에 x 추가
        else {
            max_heap.push(x);
        }
    }

    return 0;
}