#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> accum(0);

void square(int x) {
	accum += x * x;
}

int main() {
	thread th(&square, 100);
	th.join();
	cout << "Outside thread" << endl;
	return 0;
}
