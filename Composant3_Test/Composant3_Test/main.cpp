#include <iostream>
#include "Mineur.h"
#include "Bloc.h"
#include <string> 

using namespace std;

bool test_bloc() {
	bool testResult = true;
	Bloc bloc = Bloc();
	int nb_zeros = 2;
	Mineur mineur = Mineur(bloc, nb_zeros);
	mineur.transform();
	Bloc final_bloc = mineur.getM_bloc();
	string blocString = final_bloc.ToString();

	//Transform to Binary
	std::vector<int> bites(8 * blocString.length());
	for (int i = 0; i < blocString.length(); i++) {
		for (int j = 0; j < 8; j++) {
			bites[i * 8 + j] = ((1 << j) & blocString[i]) != 0 ? 1 : 0;
		}
	}

	// Tester les n premiers bites
	for (int i = 0; i < nb_zeros; i++) {
		if (bites[i] != 0) {
			testResult = false;
			break;
		}
	}
	
	return testResult;
}

int main(int argc, char *argv[])
{
	if(test_bloc())
		cout << "Test Mineur: SUCCESS" << endl;
	else
		cout << "Test Mineur: FAIL" << endl;

	return 0;
}