#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

bool canMakeRact(ll N, ll K) {
    return 1LL * K * (K + 1) / 2 <= N;  // 오버플로 방지
}

bool canMakeRactWithNoRest(ll N, ll K) {
    return 1LL * K * (K + 1) / 2 == N;  // 오버플로 방지
}

ll paramSearch(ll N) {
    ll lo = 1, hi = 2 * pow(10, 10);  // N+1은 불가능한 upper bound

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (canMakeRact(N, mid)) {
            lo = mid + 1;  // mid는 가능: 더 오른쪽 탐색
        } else {
            hi = mid;      // mid는 불가능: 왼쪽 탐색
        }
    }

    if(canMakeRactWithNoRest(N, lo - 1))// 마지막으로 가능한 K는 lo - 1
        return lo - 1;
    else
        return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        ll N;
        cin >> N;

        ll answer = paramSearch(N);
        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}
