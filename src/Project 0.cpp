#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void swap(int &a, int &b);
void bubbleSort(int arr[], int n);
bool binarySearch(int arr[], int n, int size);
int distanceToClosest(const int solutions[], int SIZE, int guess);

int main() {
	srand(time(NULL));
	const int ARR_SIZE = 5;
	int solutions[ARR_SIZE];

	for (int i = 0; i <= ARR_SIZE-1; i++) {		//setting random elements for solutions array (1-1000)
		solutions[i] = rand()%1000 + 1;
	}

	bubbleSort(solutions, ARR_SIZE);

	cout << "Hello, please try and guess one of my numbers between 1 and 1000.\n";
	while (true) {
		int guess;
		cout << "Please Make a guess: ";
		cin >> guess;

		if ((guess > 1000 || guess < 0) || cin.fail()) {		//input error checking
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nPlease enter an integer between 1 and 1000.\n";
			continue;
		}

		if (binarySearch(solutions, guess, ARR_SIZE)) {
				cout << "Success!";
				break;
		} else {
			cout << "I am sorry, that is incorrect!\n";
			static int previousDifference = -1;
			if ((previousDifference > distanceToClosest(solutions, ARR_SIZE, guess)) && previousDifference != -1) {
				cout << "Getting warmer!\n\n";
			} else if ((previousDifference < distanceToClosest(solutions, ARR_SIZE, guess)) && previousDifference != -1) {
				cout << "Getting colder!\n\n";
			} else if ((previousDifference == distanceToClosest(solutions, ARR_SIZE, guess)) && previousDifference != -1) {
				cout << "No change!\n\n";
			}
			previousDifference = distanceToClosest(solutions, ARR_SIZE, guess);
		}
	}
	return 0;
}

void swap(int &a, int &b) {		// swaps two ints a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int n) {		//sorts arr[] with n elements using bubble sort
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

bool binarySearch(int arr[], int n, int size) {		//binary search for n in arr[]
	int high = size-1, low = 0;
	cout << n << endl;
	while (low <= high) {
		int mid = (high + low)/2;
		if (n > arr[mid]) {
			low = mid + 1;
		} else if (n < arr[mid]) {
			high = mid - 1;
		} else if (n == arr[mid]){
			return true;
		}
	}
	return false;
}

int distanceToClosest(const int solutions[], int SIZE, int guess) {		//finds distance from guess to the closest element in the solutions array
	int difference = 1000;
	for (int i = 0; i <= SIZE-1; i++) {
		if (difference > abs(guess - solutions[i])){
			difference = abs(guess - solutions[i]);
		}
	}
	return difference;
}
