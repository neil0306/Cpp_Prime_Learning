# include <iostream>

int main(void) {
	using std::cout;
	using std::endl;
	using std::cin;

	int min,max,sum=0;
	cout << "enter the min number:";
	cin >> min;
	cout << "enter the max number:";
	cin >> max;
	
	for (int i = min; i <= max; i++) {
		sum += i;
	}
	cout << "sum = " << sum << endl;

	return 0;
}