#include <iostream>
#include <vector>
#include <clocale>

using namespace std;

int sumOfDigits(const vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        if (num < 0) num = -num; 
        if (num == 0) total_sum += 0;

        while (num > 0) {
            total_sum += num % 10;
            num /= 10;
        }
    }
    return total_sum;
}

double averageOfPositives(const vector<int>& arr) {
    double sum = 0;
    int count = 0;
    for (int num : arr) {
        if (num > 0) {
            sum += num;
            count++;
        }
    }
    return count > 0 ? sum / count : 0.0;
}

void findMaxNegative(const vector<int>& arr) {
    int max_neg = 0;
    int max_idx = -1;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            if (max_idx == -1 || arr[i] > max_neg) {
                max_neg = arr[i];
                max_idx = static_cast<int>(i);
            }
        }
    }

    if (max_idx != -1) {
        cout << "Максимальний від'ємний елемент: " << max_neg << " на індексі: " << max_idx << "\n";
    }
    else {
        cout << "Від'ємні елементи відсутні.\n";
    }
}

int mostFrequent(const vector<int>& arr) {
    if (arr.empty()) return 0;

    int most_frequent_num = arr[0];
    int max_count = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < arr.size(); ++j) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_frequent_num = arr[i];
        }
    }

    return most_frequent_num;
}

void maxOddIndexDivBy3(const vector<int>& arr) {
    int max_val = 0;
    bool found = false;

    for (size_t i = 1; i < arr.size(); i += 2) { 
        if (arr[i] % 3 == 0) {
            if (!found || arr[i] > max_val) {
                max_val = arr[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "Найбільший елемент на непарній позиції, що ділиться на 3: " << max_val << "\n";
    }
    else {
        cout << "Такий елемент не знайдено.\n";
    }
}

void swapMaxEvenAndMinOdd(vector<int>& arr) {
    int max_even_idx = -1;
    int min_odd_idx = -1;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            if (max_even_idx == -1 || arr[i] > arr[max_even_idx]) {
                max_even_idx = static_cast<int>(i);
            }
        }
        else { 
            if (min_odd_idx == -1 || arr[i] < arr[min_odd_idx]) {
                min_odd_idx = static_cast<int>(i);
            }
        }
    }

    if (max_even_idx != -1 && min_odd_idx != -1) {
        int temp = arr[max_even_idx];
        arr[max_even_idx] = arr[min_odd_idx];
        arr[min_odd_idx] = temp;
    }
    else {
        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = 0;
        }
    }
}

void combineArrays(const vector<int>& A, const vector<int>& B) {
    vector<int> common;
    vector<int> unique_only;

    for (int x : A) {
        bool in_B = false;
        for (int y : B) {
            if (x == y) {
                in_B = true;
                break;
            }
        }
        if (in_B) {
            bool already_added = false;
            for (int val : common) {
                if (val == x) {
                    already_added = true;
                    break;
                }
            }
            if (!already_added) {
                common.push_back(x);
            }
        }
    }

    for (int x : A) {
        bool in_B = false;
        for (int y : B) {
            if (x == y) {
                in_B = true;
                break;
            }
        }
        if (!in_B) {
            bool already_added = false;
            for (int val : unique_only) {
                if (val == x) {
                    already_added = true;
                    break;
                }
            }
            if (!already_added) {
                unique_only.push_back(x);
            }
        }
    }

    for (int y : B) {
        bool in_A = false;
        for (int x : A) {
            if (y == x) {
                in_A = true;
                break;
            }
        }
        if (!in_A) {
            bool already_added = false;
            for (int val : unique_only) {
                if (val == y) {
                    already_added = true;
                    break;
                }
            }
            if (!already_added) {
                unique_only.push_back(y);
            }
        }
    }

    cout << "а) Присутні в обох масивах: ";
    for (int x : common) cout << x << " ";
    cout << "\nб) Присутні тільки в одному: ";
    for (int x : unique_only) cout << x << " ";
    cout << "\n";
}

int main() {
	setlocale(LC_ALL, "Ukrainian");

    vector<int> arr1 = { 12, 104, 81 };
    cout << "1. Сума цифр: " << sumOfDigits(arr1) << "\n\n";

    vector<int> arr2 = { -5, 10, 20, -2, 30 };
    cout << "2. Середнє позитивних: " << averageOfPositives(arr2) << "\n\n";

    cout << "3. ";
    findMaxNegative(arr2);
    cout << "\n";

    vector<int> arr4 = { 1, 3, 2, 3, 4, 3, 2 };
    cout << "4. Число, що зустрічається найчастіше: " << mostFrequent(arr4) << "\n\n";

    vector<int> arr5 = { 10, 9, 4, 12, 5, 18, 7 };
    cout << "5. ";
    maxOddIndexDivBy3(arr5);
    cout << "\n";

    vector<int> arr6 = { 3, 8, 1, 4, 10, 7 };
    swapMaxEvenAndMinOdd(arr6);
    cout << "6. Масив після обміну max-парного та min-непарного: ";
    for (int x : arr6) cout << x << " ";
    cout << "\n\n";

    vector<int> A = { 1, 2, 3, 4, 5 };
    vector<int> B = { 3, 4, 5, 6, 7 };
    cout << "7. ";
    combineArrays(A, B);

    return 0;
}