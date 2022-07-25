#include <iostream>

using namespace std;

bool compare_point(int x1, int y1, int x2, int y2) {
	return x1 == x2 && y1 == y2;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool op = false;//�� ������ ������ �� �ִ°��
	long long x1, x2, x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	if (compare_point(x1, y1, x3, y3)) {
		cout << "1" << '\n' << x1 << '\n' << y1 << '\n';
		return 0;
	}
	else if (compare_point(x1, y1, x4, y4)) {
		cout << "1" << '\n' << x1 << '\n' << y1 << '\n';
		return 0;
	}
	else if (compare_point(x2, y2, x3, y3)) {
		cout << "1" << '\n' << x2 << '\n' << y2 << '\n';
		return 0;
	}
	else if (compare_point(x2, y2, x4, y4)) {
		cout << "1" << '\n' << x2 << '\n' << y2 << '\n';
		return 0;
	}

	//��� ����� ���� �� ������ ���� ���ϱ�
	long long a = y2 - y1;
	long long b = x1 - x2;
	long long c = y4 - y3;
	long long d = x3 - x4;
	long long e = b * y2 + a * x2;
	long long f = d * y4 + c * x4;
	long long det = a * d - c * b;

	long long meet_x;
	long long meet_y;
	if (det == 0) {//�� ������ ������ ���
		det = 1;
		long long g = x1 - x3;
		long long h = y1 - y3;
		if (-c * g != h * d) {//������ ������ �ƴ� ���
			cout << "0" << '\n';
			return 0;
		}
		else {//���� ������ ��� 
			//�ϳ��� ���� �ۿ� �ִ� ���� �ݴ��� ���� ������ �� ���ɼ��� ����
			if (x1 == x3 && x2 == x4) {
				if (((y3 > y1 && y3 > y2) || (y3 < y1 && y3 < y2)) && ((y4 > y1 && y4 > y2) || (y4 < y1 && y4 < y2))) {
					meet_x = x1 * det;
					meet_y = y1 * det;
				}
				else if (((y1 > y3 && y1 > y4) || (y1 < y3 && y1 < y4)) && ((y2 > y3 && y2 > y4) || (y2 < y3 && y2 < y4))) {
					meet_x = x3 * det;
					meet_y = y3 * det;
				}
				else {
					if (y1 < y2) {
						if (y1 <= y3 && y3 <= y2) {
							meet_x = x3 * det;
							meet_y = y3 * det;
						}
						else {
							meet_x = x4 * det;
							meet_y = y4 * det;
						}
					}
					else {
						if (y2 <= y3 && y3 <= y1) {
							meet_x = x3 * det;
							meet_y = y3 * det;
						}
						else {
							meet_x = x4 * det;
							meet_y = y4 * det;
						}
					}
				}
			}
			else {
				if (((x3 > x1 && x3 > x2) || (x3 < x1 && x3 < x2)) && ((x4 > x1 && x4 > x2) || (x4 < x1 && x4 < x2))) {
					meet_x = x1 * det;
					meet_y = y1 * det;
				}
				else if (((x1 > x3 && x1 > x4) || (x1 < x3 && x1 < x4)) && ((x2 > x3 && x2 > x4) || (x2 < x3 && x2 < x4))) {
					meet_x = x3 * det;
					meet_y = y3 * det;
				}
				else {
					if (x1 < x2) {
						if (x1 <= x3 && x3 <= x2) {
							meet_x = x3 * det;
							meet_y = y3 * det;
						}
						else {
							meet_x = x4 * det;
							meet_y = y4 * det;
						}
					}
					else {
						if (x2 <= x3 && x3 <= x1) {
							meet_x = x3 * det;
							meet_y = y3 * det;
						}
						else {
							meet_x = x4 * det;
							meet_y = y4 * det;
						}
					}
				}
			}
		}
	}
	else {//�������� �ʴ� ���
		op = true;
		meet_x = (e * d - f * b);
		meet_y = (-e * c + a * f);
	}

	//������ �� ���� ���� �ִ��� Ȯ��
	bool answer = true;

	if ((meet_x > x1 * det && meet_x > x2 * det) || (meet_x < x1 * det && meet_x < x2 * det))
		answer = false;

	if ((meet_x > x3 * det && meet_x > x4 * det) || (meet_x < x3 * det && meet_x < x4 * det))
		answer = false;

	if ((meet_y > y1 * det && meet_y > y2 * det) || (meet_y < y1 * det && meet_y < y2 * det))
		answer = false;

	if ((meet_y > y3 * det && meet_y > y4 * det) || (meet_y < y3 * det && meet_y < y4 * det))
		answer = false;

	cout << answer << '\n';
	if (answer == true && op == true) {
		double x = (double)meet_x / (double)det;
		double y = (double)meet_y / (double)det;
		cout << x << '\n';
		cout << y << '\n';
	}
	return 0;
}