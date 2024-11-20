#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Calculate the sum of the elements
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / n;

    std::cout << "The average value of the elements in the array is: " << average << std::endl;

    return 0;
}
