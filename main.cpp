#include <iostream>

using namespace std;

void print_map(char zmap[80][80]) {
	for (unsigned i = 0; i < 80; ++i) {
		for (unsigned j = 0; j < 80; ++j) {
			cout << zmap[i][j];
		}
		cout << endl;
	}
}

int main()
{
	cout << "Welcome to glowing-nemesis." << endl;

	char map[80][80];
	for (unsigned i = 0; i < 80; ++i) {
		for (unsigned j = 0; j < 80; ++j) {
			map[i][j] = '.';
		}
	}

	print_map(map);

	return 0;
}