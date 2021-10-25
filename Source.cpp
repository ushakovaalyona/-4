#include "iostream"

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	const int a = 100;
	int N;
	cout << "Введите количество сотрудников компании (целое число 1<= N <=1000): ";
	cin >> N;
	int distanse[a];
	int taxi[a];
	int distanse_index[a];
	int taxi_index[a];

	cout << "\nВведите расстояния в километрах от работы до домов всех сотрудников компании по порядку (N положительных целых чисел, не превышающих 1000): ";
	for (int i = 0; i < N; i++) {
		cin >> distanse[i];
		distanse_index[i] = i;
	}
	cout << "\nВведите тарифы за проезд одного километра в каждом такси по порядку (N положительных целых чисел, не превышающих 1000): ";
	for (int i = 0; i < N; i++) {
		cin >> taxi[i];
		taxi_index[i] = i;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (distanse[i] < distanse[j]) {
				int t = distanse[i];
				distanse[i] = distanse[j];
				distanse[j] = t;
				t = distanse_index[i];
				distanse_index[i] = distanse_index[j];
				distanse_index[j] = t;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (taxi[i] > taxi[j]) {
				int t = taxi[i];
				taxi[i] = taxi[j];
				taxi[j] = t;
				t = taxi_index[i];
				taxi_index[i] = taxi_index[j];
				taxi_index[j] = t;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (distanse_index[i] > distanse_index[j]) {
				int t = distanse_index[i];
				distanse_index[i] = distanse_index[j];
				distanse_index[j] = t;
				t = taxi_index[i];
				taxi_index[i] = taxi_index[j];
				taxi_index[j] = t;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << "\nДля минимальных затрат фирмы сотруднику №" << i + 1 << " следует уехать на такси №" << taxi_index[i] + 1 << ";";
	}

	cout << "\n\n";
	return 0;
}

