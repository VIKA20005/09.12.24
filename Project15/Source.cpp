//Задания на массивы
//1. Сумма цифр массива
//Найти сумму всех цифр целочисленного массива.Например, если дан
//массив[12, 104, 81], то сумма всех его цифр будет равна 1 + 2 + 1 + 0 +
//4 + 8 + 1 = 17.#include <iostream>
#include <vector>

int sumOfDigits(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

int main() {
    std::vector<int> arr = { 12, 104, 81 };
    std::cout << "Sum of digits: " << sumOfDigits(arr) << std::endl;
    return 0;
}
//2. Среднее арифметическое положительных элементов массива
//Найти среднее арифметическое положительных элементов линейного
//массива.#include <iostream>
#include <vector>

double averagePositive(const std::vector<int>& arr) {
    double sum = 0;
    int count = 0;
    for (int num : arr) {
        if (num > 0) {
            sum += num;
            count++;
        }
    }
    return count > 0 ? sum / count : 0; // Якщо немає позитивних елементів, повертаємо 0
}

int main() {
    std::vector<int> arr = { 12, -5, 104, 0, 81, -10 };
    std::cout << "Average of positive elements: " << averagePositive(arr) << std::endl;
    return 0;
}//3. Максимальный отрицательный элемент массива
//В массиве найти максимальный отрицательный элемент.Вывести на
//экран его значение и позицию в массиве.#include <iostream>
#include <vector>
#include <limits>

void maxNegativeElement(const std::vector<int>& arr) {
    int maxNegative = std::numeric_limits<int>::min();
    int position = -1;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] < 0 && arr[i] > maxNegative) {
            maxNegative = arr[i];
            position = i;
        }
    }
    if (position != -1) {
        std::cout << "Max negative element: " << maxNegative << " at position " << position << std::endl;
    }
    else {
        std::cout << "No negative elements in the array." << std::endl;
    }
}

int main() {
    std::vector<int> arr = { 12, -5, 104, -10, 81 };
    maxNegativeElement(arr);
    return 0;
}//4. Число, чаще всего встречающееся в массиве
//Определить, какое число в массиве встречается чаще всего.//#include <iostream>
#include <vector>
#include <unordered_map>

int mostFrequent(const std::vector<int>& arr) {
    std::unordered_map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }

    int maxFreq = 0;
    int mostFreqNum = arr[0];
    for (const auto& pair : frequency) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqNum = pair.first;
        }
    }
    return mostFreqNum;
}

int main() {
    std::vector<int> arr = { 12, 104, 12, 81, 12, 104 };
    std::cout << "Most frequent number: " << mostFrequent(arr) << std::endl;
    return 0;
}//5. Среди элементов с нечетными номерами найдите наибольший элемент
//массива, который делится на 3

#include <iostream>
#include <vector>
#include <limits>

int maxOddIndexDivisibleBy3(const std::vector<int>& arr) {
    int maxElem = std::numeric_limits<int>::min();
    for (size_t i = 1; i < arr.size(); i += 2) { // Ідемо тільки по непарних індексах
        if (arr[i] % 3 == 0 && arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem == std::numeric_limits<int>::min() ? -1 : maxElem; // Повертаємо -1, якщо елементи відсутні
}

int main() {
    std::vector<int> arr = { 12, 9, 104, 15, 81, 21 };
    int result = maxOddIndexDivisibleBy3(arr);
    if (result != -1) {
        std::cout << "Max element with odd index divisible by 3: " << result << std::endl;
    }
    else {
        std::cout << "No elements with odd index divisible by 3." << std::endl;
    }
    return 0;
}



//6. Найти наибольший четный элемент массива и поменять его
//местами с наименьшим нечетным элементом.Если одного из таких
//элементов нет, то всем элементам массива присвоить значение,
//равное нулю.
#include <iostream>
#include <vector>
#include <limits>

void replaceMaxEvenMinOdd(std::vector<int>& arr) {
    int maxEven = std::numeric_limits<int>::min();
    int minOdd = std::numeric_limits<int>::max();
    int maxEvenIndex = -1, minOddIndex = -1;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0 && arr[i] > maxEven) {
            maxEven = arr[i];
            maxEvenIndex = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            minOddIndex = i;
        }
    }

    if (maxEvenIndex != -1 && minOddIndex != -1) {
        std::swap(arr[maxEvenIndex], arr[minOddIndex]);
    }
    else {
        for (int& num : arr) {
            num = 0;
        }
    }
}

int main() {
    std::vector<int> arr = { 12, 15, 104, 81, 8, 3 };
    replaceMaxEvenMinOdd(arr);

    std::cout << "Modified array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}



//7. Даны два массива.Сформировать третий массив, состоящий из тех
//элементов, которые: а) присутствуют в обоих массивах;
//б) присутствуют только в одном из массивов.#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> intersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    for (int num : arr1) {
        if (std::find(arr2.begin(), arr2.end(), num) != arr2.end()) {
            result.push_back(num);
        }
    }
    return result;
}

std::vector<int> difference(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    for (int num : arr1) {
        if (std::find(arr2.begin(), arr2.end(), num) == arr2.end()) {
            result.push_back(num);
        }
    }
    for (int num : arr2) {
        if (std::find(arr1.begin(), arr1.end(), num) == arr1.end()) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    std::vector<int> arr1 = { 12, 104, 81, 15 };
    std::vector<int> arr2 = { 81, 15, 7, 104 };

    std::vector<int> common = intersection(arr1, arr2);
    std::vector<int> unique = difference(arr1, arr2);

    std::cout << "Common elements: ";
    for (int num : common) {
        std::cout << num << " ";
    }
    std::cout << "\nUnique elements: ";
    for (int num : unique) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}