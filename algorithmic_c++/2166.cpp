#include <iostream>
#include <list>
#include <cmath>

using namespace std;

double get_tri_area(double x1,double x2, double x3, double y1, double y2, double y3) {//외적을 통한 넓이 구하기
	double first = x1 * y2 + x2 * y3 + x3 * y1;
	double second = x1 * y3 + x3 * y2 + x2 * y1;
	return (first - second) * 0.5;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<pair<double, double>> arr;

	int i;
	cin >> i;

	for (double n = 0; n < i; n++) {
		double x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	pair<double, double> core_podouble = arr.front();//모든 삼각형에 포함되는 꼭지점
	arr.pop_front();
	list<pair<double, double>> rest_podouble;//나머지 꼭지점 두개를 담는 리스트

	double x1, x2, x3, y1, y2, y3;
	x1 = core_podouble.first;
	y1 = core_podouble.second;

	//초기 세팅
	rest_podouble.push_back(arr.front());
	arr.pop_front();
	rest_podouble.push_back(arr.front());
	arr.pop_front();

	double answer = 0;
	
	do {
		x2 = rest_podouble.front().first;
		y2 = rest_podouble.front().second;
		x3 = rest_podouble.back().first;
		y3 = rest_podouble.back().second;

		answer += get_tri_area(x1, x2, x3, y1, y2, y3);

		if (arr.empty())//더 이상 남은 꼭지점이 없는 경우
			break;

		rest_podouble.push_back(arr.front());
		arr.pop_front();
		rest_podouble.pop_front();
	} while (1);
	
	printf("%.1f", fabs(answer));
	return 0;
}