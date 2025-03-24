/*
빙하왕국의 엘사와 안나가 빙하 평원에서 길을 잃었습니다.

리본 머리띠를 하고 있는 안나는 엘사를 찾기 위해,왕관 쓰고 있는 엘사는 안나를 찾기 위해,서로 1초 마다 한 칸씩동시에 이동하며서로를 찾습니다.
 

[안나의 움직임]

안나는 1 초에 한 칸씩 상, 하, 좌, 우로 움직일 수 있습니다.

그리고 제 자리에 멈추어 휴식을 취하는 것도 가능합니다.

 

[엘사의 움직임]

엘사는 1 초에 한 칸씩 상, 하, 좌, 우로 움직일 수 있습니다.

몸이 가벼운 엘사는, 제자리에 멈추지 않고 끊임없이 움직입니다.
 

엘사는마법을 사용하여,대각선으로도 움직일 수 있습니다. (총 8 방향 이동 가능)

하지만 안나가 두 칸거리 안에 가까이 존재한다면,마법으로 인해 안나가 다칠까봐, 대각선 이동을 하지 않습니다.
 

지도를 입력 받고, 빙하를 피해 엘사와 안나가 가장 빠르게 만날 수 있는 이동시간을 계산해 주세요.
 

 

[유의사항]
 

안나와 엘사가 동시에 움직여 엇갈릴 수도 있습니다.
반드시 만날 수 있는 길이 있는 입력 값이 주어집니다.
 
입력

첫 줄에 맵의 크기를 나타내는 수 N 을 입력 받아주세요. (1 <= N <= 5)

다음 줄부터 N x N 맵 정보를 입력 받습니다.

 

빈칸은 '_' (언더바) 이며, 빙하는 '#' 으로 표기됩니다.

그 다음줄에는엘사의 위치 (y, x) 와 안나의 위치 (y, x) 가 입력 됩니다.
 

출력

두 사람이 같은 좌표에서 만나게 되는, 최소 시간을 출력해 주세요.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

#define endl '\n'
using namespace std;

// 이동 방향 정의
vector<int> elsaMoveFarY = {1, 1, 0, -1, -1, -1, 0, 1};  // Elsa가 멀리 있을 때 8방향 이동
vector<int> elsaMoveFarX = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> elsaMoveNearY = {1, 0, -1, 0};  // Elsa가 가까울 때 4방향 이동
vector<int> elsaMoveNearX = {0, 1, 0, -1};

vector<int> annaMoveY = {1, 0, -1, 0, 0};  // Anna는 4방향과 제자리(0,0) 이동
vector<int> annaMoveX = {0, 1, 0, -1, 0};

// 노드 구조체 정의
struct Node {
    int elsaY, elsaX;  // Elsa의 좌표
    int annaY, annaX;  // Anna의 좌표
    int time;          // 경과 시간
};

// 범위 및 장애물 검사 함수
bool isValidMove(int y, int x, const vector<vector<char>>& map) {
    int n = map.size();
    return (y >= 0 && y < n && x >= 0 && x < n && map[y][x] != '#');
}

// Elsa와 Anna가 가까운지 확인 (반경 3 이내)
bool isAnnaClose(const Node& node) {
    return abs(node.annaX - node.elsaX) < 3 && abs(node.annaY - node.elsaY) < 3;
}

// Elsa가 Anna에게 도달하는 최소 시간을 찾는 Flood Fill 알고리즘
int findMinTimeToMeet(int elsaY, int elsaX, int annaY, int annaX, const vector<vector<char>>& map) {
    int n = map.size();
    int minTime = INT_MAX;  // 최소 시간 초기화

    // 방문 여부를 저장하는 2차원 배열 (Elsa 위치 * Anna 위치)
    vector<vector<int>> visited(n * n, vector<int>(n * n, 0));
    queue<Node> q;
    q.push({elsaY, elsaX, annaY, annaX, 1});  // 시작 상태

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        // 현재 위치를 인덱스로 변환 (방문 여부 확인을 위해)
        int elsaIdx = cur.elsaY * n + cur.elsaX;
        int annaIdx = cur.annaY * n + cur.annaX;

        // 이미 방문했거나 최소 시간을 초과하면 무시
        if (minTime <= cur.time || visited[elsaIdx][annaIdx]) continue;
        visited[elsaIdx][annaIdx] = 1;  // 방문 처리

        // Elsa와 Anna가 같은 위치에 도달한 경우
        if (cur.elsaY == cur.annaY && cur.elsaX == cur.annaX) {
            minTime = min(minTime, cur.time);
            continue;
        }

        // Elsa의 이동 방향 결정 (가까우면 4방향, 멀면 8방향)
        vector<int>* elsaMoveY = isAnnaClose(cur) ? &elsaMoveNearY : &elsaMoveFarY;
        vector<int>* elsaMoveX = isAnnaClose(cur) ? &elsaMoveNearX : &elsaMoveFarX;

        // 다음 위치 탐색
        if (cur.time + 1 < minTime) {
            for (int i = 0; i < elsaMoveY->size(); i++) {
                int nextElsaY = cur.elsaY + (*elsaMoveY)[i];
                int nextElsaX = cur.elsaX + (*elsaMoveX)[i];

                // Elsa의 이동이 유효하지 않으면 무시
                if (!isValidMove(nextElsaY, nextElsaX, map)) continue;

                // Anna의 이동 (4방향 + 제자리)
                for (int j = 0; j < annaMoveY.size(); j++) {
                    int nextAnnaY = cur.annaY + annaMoveY[j];
                    int nextAnnaX = cur.annaX + annaMoveX[j];

                    int nextElsaIdx = nextElsaY * n + nextElsaX;
                    int nextAnnaIdx = nextAnnaY * n + nextAnnaX;

                    // Anna의 이동이 유효하고, 방문하지 않은 상태라면 큐에 추가
                    if (isValidMove(nextAnnaY, nextAnnaX, map) && !visited[nextElsaIdx][nextAnnaIdx]) {
                        q.push({nextElsaY, nextElsaX, nextAnnaY, nextAnnaX, cur.time + 1});
                    }
                }
            }
        }
    }

    return minTime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;  // 지도 크기

    // 지도 입력
    vector<vector<char>> map(n, vector<char>(n));
    for (auto& row : map) {
        for (auto& cell : row) {
            cin >> cell;
        }
    }

    // Elsa와 Anna의 초기 위치 입력
    int elsaY, elsaX, annaY, annaX;
    cin >> elsaY >> elsaX >> annaY >> annaX;

    // 최소 시간 계산
    int result = findMinTimeToMeet(elsaY, elsaX, annaY, annaX, map);

    // 결과 출력
    cout << result - 1 << " sec" << endl;

    return 0;
}
