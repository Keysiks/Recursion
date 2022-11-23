#include <iostream>
using namespace std;

void elevator(int floor);
void factorial(int number, long long x);
double power(double a, int n, double res);
long long fib_num(int n);

//#define LESSON
//#define FACT
//#define POWER
#define FIB_PREDEL
//#define FIB_NUM
void main() {
#ifdef LESSON
	setlocale(LC_ALL, "");
	int floor;
	cout << "Enter floor: "; cin >> floor;
	elevator(floor);
#endif //LESSON

#ifdef FACT
	int num;
	cout << "Enter number: "; cin >> num;
	factorial(num, 1);
	
#endif //FACT

#ifdef POWER
	int n; double a;
	cout << "Enter number: "; cin >> a;
	cout << "Enter power: "; cin >> n;
	if (n == 0)
		cout << "Result = " << 1;
	else cout << "Result = " << power(a, n, 1);
#endif //POWER

#ifdef FIB_PREDEL
	int predel;
	cout << "Enter predel: "; cin >> predel;
	int result;
	for (int i = 1; i >= 0; i++) {
		result = fib_num(i);
		if (result > predel)
			break;
		cout << result << "\t";
	}
#endif //FIB_PREDEL

#ifdef FIB_NUM
	int n;
	cout << "Enter number: "; cin >> n;
	for (int i = 1; i < n + 1; i++)
		cout << fib_num(i) << "\t";
#endif //FIB_NUM
}

void elevator(int floor) {
	if (floor == 0) {
		cout << "Вы в подвале";
		return;
	}
	cout << "Вы на этаже: " << floor << endl;
	elevator(floor - 1);
	cout << "Вы на этаже: " << floor << endl;
}


void factorial(int number, long long x) {
	if (number > 45) {
		cout << "Error";
		return;
	}
	else if (number < 2) {
		cout << "result: " << x;
		return;
	}
	x *= number;
	cout << x << endl;
	factorial(number - 1, x);
}

double power(double a, int n, double res) {
	if (n == 0)
		return res;
	else if (n > 0) {
		res *= a; 
		return power(a, n - 1, res);
	}
	else {
		res/=a;
		return power(a, n + 1, res);
	}
}

long long fib_num(int n) {
	if (n == 1 or n == 2)
		return 1;
	return fib_num(n - 1) + fib_num(n - 2);
}