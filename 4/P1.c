#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция разделения массива (Хоара)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // опорный элемент - первый
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        // Двигаем i вправо, пока элемент меньше опорного
        do {
            i++;
        } while (arr[i] < pivot);
        
        // Двигаем j влево, пока элемент больше опорного
        do {
            j--;
        } while (arr[j] > pivot);
        
        // Если индексы встретились, возвращаем j
        if (i >= j) return j;
        
        // Меняем местами элементы
        swap(arr[i], arr[j]);
    }
}

// Рекурсивная функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Функция для проверки, отсортирован ли массив
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {
    srand(time(nullptr));
    
    // Тестирование на разных размерах массивов
    vector<int> testSizes = {5, 10, 20, 50};
    
    for (int size : testSizes) {
        cout << "\n=== Тестирование на массиве размером " << size << " ===" << endl;
        
        // Создаем случайный массив
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        
        cout << "Исходный массив: ";
        printArray(arr);
        
        // Сортируем
        quickSort(arr, 0, size - 1);
        
        cout << "Отсортированный массив: ";
        printArray(arr);
        
        // Проверяем результат
        if (isSorted(arr)) {
            cout << "✓ Массив правильно отсортирован!" << endl;
        } else {
            cout << "✗ Ошибка сортировки!" << endl;
        }
    }
    
    return 0;
}
