#include <iostream>
#include <ostream>
#include <vector>
#include <limits>
#include <cmath>

void task51() {
	std::cout << "Task: 51\n";
    const int N = 10; 
    int A[N]; 
    int A0; 

    std::cout << "Введите начальное значение A[0] (A[0] ≠ 0): ";
    std::cin >> A0;

    if (A0 == 0) {
        std::cerr << "Начальное значение A[0] не должно быть равно 0." << std::endl;
        return;
    }

    A[0] = A0; 
    for (int i = 1; i < N; ++i) {
        A[i] = A[i / 2] + A[i - 1];
    }
    std::cout << "Заполненный массив A:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "A[" << i << "] = " << A[i] << std::endl;
    }
}

void task58() {
    std::cout << "Task: 58\n";
    const int N = 10;
    std::vector<int> x(N);
    std::vector<int> y(N);
    std::vector<int> z(2 * N);

    std::cout << "Введите элементы первого вектора упорядоченные по возрастанию:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
        if (i > 0 && x[i] < x[i - 1]) {
            std::cerr << "Ошибка: элементы должны быть упорядочены по возрастанию." << std::endl;
            return;
        }
    }

    std::cout << "Введите элементы второго вектора упорядоченные по возрастанию:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> y[i];
        if (i > 0 && y[i] < y[i - 1]) {
            std::cerr << "Ошибка: элементы должны быть упорядочены по возрастанию." << std::endl;
            return;
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < N && j < N) {
        if (x[i] <= y[j]) {
            z[k++] = x[i++];
        }
        else {
            z[k++] = y[j++];
        }
    }
    while (i < N) {
        z[k++] = x[i++];
    }
    while (j < N) {
        z[k++] = y[j++];
    }

    std::cout << "Объединенный вектор (упорядоченный):" << std::endl;
    for (int i = 0; i < 2 * N; i++) {
        std::cout << z[i] << " ";
    }
    std::cout << std::endl;
}


void task77() {
	std::cout << "Task: 77\n";
    int number;
    int index = 0;
    int position = -1;

    std::cout << "Введите последовательность целых чисел (завершается числом -1):" << std::endl;

    while (true) {
        if (!(std::cin >> number)) {
	        std::cout << "Ошибка: введите корректное целое число." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (number == -1) {
            break;
        }

        index++;
        if (number % 7 == 0 && position == -1) {
            position = index; 
        }
    }

    if (position != -1) {
	    std::cout << "Первое число, кратное 7, имеет порядковый номер: " << position << std::endl;
    }
    else {
	    std::cout << "В последовательности нет чисел, кратных 7." << std::endl;
    }
}


void task114() {
	std::cout << "Task: 114\n";
    const int SIZE = 10;
    int arr[SIZE];

	std::cout << "Введите 10 элементов массива: ";
    for (int i = 0; i < SIZE; i++) {
	    std::cin >> arr[i];
    }

    int sum = arr[4] + arr[9];
    int element = sum * sum;

    int k;
	std::cout << "Введите позицию k: ";
	std::cin >> k;

    if (k < 0 || k > SIZE) {
	    std::cout << "Некорректное значение k." << std::endl;
        return;
    }

    int newArr[SIZE + 1];
    for (int i = 0, j = 0; i < SIZE + 1; i++) {
        if (i == k) {
            newArr[i] = element;
        }
        else {
            newArr[i] = arr[j++];
        }
    }
	std::cout << "Обновленный массив: ";
    for (int i = 0; i < SIZE + 1; i++) {
	    std::cout << newArr[i] << " ";
    }
	std::cout << std::endl;
}


void task175() {
	std::cout << "Task: 175\n";
    const int SIZE = 30;
    int arr[SIZE];
    srand(static_cast<unsigned int>(time(0)));

	std::cout << "Введите первое значение для массива: ";
    while (true) {
        if (!(std::cin >> arr[0])) {
	        std::cout << "Ошибка: введите корректное целое число." << std::endl;
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        else {
            break;
        }
    }
    for (int i = 1; i < SIZE; i++) {
        int change = rand() % 21 - 10; 
        int newValue = arr[i - 1] + change;
        if (newValue < 1) {
            newValue = 1; 
        }
        arr[i] = newValue;
    }

	std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < SIZE; i++) {
	    std::cout << arr[i] << " ";
    }
	std::cout << std::endl;
}


void task56() {
    std::cout << "Task: 56\n";
        const int N = 50;
        double z[N];
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < N; i++) {
            z[i] = rand() % 100 + 1; 
        }
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += z[i] * z[i];
        }
        double L = sqrt(sum);

    std::cout << "Сгенерированный вектор: ";
        for (int i = 0; i < N; i++) {
	        std::cout << z[i] << " ";
        }
    std::cout << std::endl;
    std::cout << "Длина вектора: " << L << std::endl;
    }

int main()
{
    //task51();
    //task58();
    //task77();
    //task114();
    //task175();
    //task56();
    return 0;
}





