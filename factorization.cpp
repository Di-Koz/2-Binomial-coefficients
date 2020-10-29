#include <iostream>
using namespace std;

//1
void printTr(int kolvoStrok);
//2
unsigned long long C(int N, int K);
void C2(int N);
//3
unsigned long long fact(int ch);
unsigned long long D(int N, int K);
void D2(int N);
//dop
unsigned long long calculateValue(int ch1, int ch2);
int backNOD(int ch1, int ch2);

int main() {
	//1
	/*int numStrok{0};
	cin >> numStrok;
	printTr(numStrok);*/
	//2 
	/*int n{ 0 };
	cin >> n;
	C2(n);*/
	//3
	/*int n{ 0 };
	cin >> n;
	D2(n);*/
	//dop
	int a{ 33 };
	printTr(a + 1);
	cout << endl;
	for (int i{ 0 }; i <= a; ++i) {
		cout << calculateValue(a, i) << " ";
	}
}

void printTr(int kolvoStrok) {
	unsigned long long *arr1 = new unsigned long long[1];
	unsigned long long *arr2 = new unsigned long long[0];
	arr1[0] = 1;
	//cout << arr1[0] << endl;

	for (int i{1}; i < kolvoStrok; ++i) {
		if (i % 2 == 1) {
			arr2 = new unsigned long long[i + 1];
			for (int j{ 0 }; j <= i; ++j) {
				arr2[j] = (j == 0) || (j == i) ? 1 : arr1[j - 1] + arr1[j];
				
				if (i == kolvoStrok - 1) {
					cout << arr2[j] << " ";
				}
				//cout << arr2[j] << " ";
			}
			delete[] arr1;
		}
		else {
			arr1 = new unsigned long long[i + 1];
			for (int j{ 0 }; j <= i; ++j) {
				arr1[j] = (j == 0) || (j == i) ?  1 : arr2[j - 1] + arr2[j];
				if (i == kolvoStrok - 1) {
					cout << arr1[j] << " ";
				}
				//cout << arr1[j] << " ";
			}
			delete[] arr2;
		}
		//cout << endl;
	}
}
//2
unsigned long long C(int N, int K) {
	return (K == 0) || (K == N) ? 1 : C(N - 1, K - 1) + C(N - 1, K);
}

void C2(int N) {
	for (int i{ 0 }; i <= N; ++i) {
		cout << C(N, i) << " ";
	}
}
//3
unsigned long long fact(int ch) {
	if (ch == 1 || ch == 0) {
		return 1;
	}
	else {
		return ch * fact(ch - 1);
	}
}

unsigned long long D(int N, int K) {
	return fact(N) / (fact(K) * fact(N - K));
}

void D2(int N) {
	for (int i{0}; i <= N; ++i) {
		cout << D(N, i) << " ";
	}
}

unsigned long long calculateValue(int ch1, int ch2) {
	int *arr3 = new int[ch1 - ch2];
	int* arr4 = new int[ch1 - ch2];

	for (int i{ 1 }; i <= ch1 - ch2; ++i) {
		arr3[i - 1] = i;
	}
	for (int i{ ch1 }; i > ch2; --i) {
		arr4[i - ch2 - 1] = i;
	}
	
	for (int i{0}; i < ch1 - ch2; ++i) {
		for (int j{0}; j < ch1 - ch2; ++j) {
			if (backNOD(arr4[i], arr3[j])) {
				int NOD = backNOD(arr4[i], arr3[j]);
				arr4[i] /= NOD;
				arr3[j] /= NOD;
			}
		}
	}

	/*for (int i{ 0 }; i < ch1 - ch2; ++i) {
		cout << arr4[i] << " ";
	}
	cout << endl;
	for (int i{ 0 }; i < ch1 - ch2; ++i) {
		cout << arr3[i] << " ";
	}*/

	//unsigned long long result1{ 1 };
	//unsigned long long result1{ 1 };
	int result1{ 1 };
	int result2{ 1 };
	for (int i{0}; i < ch1 - ch2; ++i) {
		result1 *= arr3[i];
		result2 *= arr4[i];
	}

	return result2 / result1;
}

int backNOD(int ch1, int ch2) {
	while (ch1 != ch2) {
		if (ch1 > ch2) {
			ch1 = ch1 - ch2;
		}
		else {
			ch2 = ch2 - ch1;
		}
	}
	if (ch1 == 1) {
		return 0;
	}
	return ch1;
}