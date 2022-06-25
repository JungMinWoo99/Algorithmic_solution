#include <iostream>
#include <vector>

using namespace std;

/*
* 사용 알고리즘
*/

int arr[9][9];

vector<pair<int, int>> track;//변경한 배열위치를 순서대로 저장하는 리스트(값을 추가할 수 없는 경우 역순으로 올라가며 다시 값을 바꿈)

bool col_check(int col) {
	bool table[10] = {false};//한번 확인된 값은 참으로 저장
	for (int i = 0; i < 9; i++) {
		if (table[arr[col][i]])//이미 확인된 값이 또 확인된경우
			return false;
		else//처음 확인된 값인 경우
			table[arr[col][i]] = true;
		table[0] = false;//0은 아직 정해진 값이 아니라는 뜻이기 때문에 중복으로 확인되도 됨
	}
	return true;//중복된 값이 하나도 없는 경우
}

bool row_check(int row) {
	bool table[10] = { false };//한번 확인된 값은 참으로 저장
	for (int i = 0; i < 9; i++) {
		if (table[arr[i][row]])//이미 확인된 값이 또 확인된경우
			return false;
		else//처음 확인된 값인 경우
			table[arr[i][row]] = true;
		table[0] = false;//0은 아직 정해진 값이 아니라는 뜻이기 때문에 중복으로 확인되도 됨
	}
	return true;//중복된 값이 하나도 없는 경우
}

bool cell_check(int col, int row) {//col행 row열의 셀에 대해 중복값 검사
	bool table[10] = { false };//한번 확인된 값은 참으로 저장
	for (int n = col*3; n < (col+1)*3; n++) {
		for (int m = row*3; m < (row + 1) * 3; m++) {
			if (table[arr[n][m]])//이미 확인된 값이 또 확인된경우
				return false;
			else//처음 확인된 값인 경우
				table[arr[n][m]] = true;
			table[0] = false;//0은 아직 정해진 값이 아니라는 뜻이기 때문에 중복으로 확인되도 됨
		}
	}
	return true;//중복된 값이 하나도 없는 경우
}

bool all_check(int col, int row) {
	if (!col_check(col))
		return false;
	if (!row_check(row))
		return false;
	if (!cell_check(col / 3, row / 3))
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int n = 0; n < 9; n++) {
		for (int m = 0; m < 9; m++) {
			int input;
			scanf_s("%1d", &input);
			arr[n][m] = input;
			if (input == 0)
				track.push_back(make_pair(n, m));//값을 채워야할 칸의 위치를 저장
		}
	}

	int iter = 0;//track의 양방향 반복자처럼 쓸 변수
	while (iter!=track.size()) {//빈칸을 모두 채우면 끝
		++arr[track[iter].first][track[iter].second]%=10;
		if (!(arr[track[iter].first][track[iter].second] == 0)) {//0이 대입되지 않은 경우
			if (all_check(track[iter].first, track[iter].second))//대입된 값이 중복이 아닐경우
				iter++;
			else
				continue;//중복인 경우 다음값 대입
		}
		else //0이 대입된 경우(1~9까지 현재 가능한 값이 없다는 뜻)
			iter--;
	}

	cout << endl;
	for (int n = 0; n < 9; n++) {
		for (int m = 0; m < 9; m++) {
			cout<<arr[n][m];
		}
		cout << endl;
	}
	
	return 0;
}