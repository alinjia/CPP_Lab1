#include <iostream>

/*QuickSort*/
template <typename T>
void QuickSort(T *arr, int size) { //С помощью шаблона делаем функцию для любого типа массива, размер всегда целочисленный
    
    int begin = 0; //Номер начального элемента - начало массива
    int end = size - 1; //Номер конечного элемента - конец массива
    
    int indexPivot = rand() % (end - begin + 1) + begin; //Рандомно генерируем номер опорного элемента с помощью функции rand
    T pivot = arr[indexPivot]; //Обозначаем опорный элемент как элемент массива под номером, который определили рандомно

    do { //через цикл (do while), делим изначальный масси на две части, отделяя элементы меньшие опорного в лево, больше опорного в право

        while (arr[begin] < pivot) { //От начала проверяем элементы, если элемент меньше опорного пропускаем его и переходим к следующему
            begin++;
        }
        while (arr[end] > pivot) { //От конца проверяем элементы, если элемент больше опорного пропускаем его и переходим к следующему
            end--;
        }
        if (begin <= end) { //Если не пропустили элемент, то через if меняем местами элементы
            std::swap(arr[begin], arr[end]); 
            begin++;
            end--;
        }

    } while (begin <= end); //Функция происходит пока не пройдет все элементы, т е начало и конец встретяться


    //QuickSort - рекурсивная сортировка, т е после разделения на две части (меньшей и большей опорного), с этими частями нужно проделать тоже самое
    if (end > 0) { //Левая часть
        QuickSort(arr, end + 1);
    }
    if (begin < size) { //Правая часть
        QuickSort(&arr[begin], size - begin);
    }
}

/*BubbleSort*/

template <typename T>
void BubbleSort(T *arr, int size) { //С помощью шаблона делаем функцию для любого типа массива, размер всегда целочисленный
    for (int i = 0; i < size; i++) { //Циклами перебираем и сравниваем по два элемента
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { //если левыцй элемент массива больше правого - меняем их местами
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


/*InsertionSort*/
template <typename T>
void InsertionSort(T *arr, int size) { //С помощью шаблона делаем функцию для любого типа массива, размер всегда целочисленный
    for (int i = 1; i < size; i++) { //Начинаем перебирать элементы со второго
        T key = arr[i]; //Сохраняем значение выбранного элемента
        int j = i - 1; //Индекс предыдущего элемента от выбранного
        while (j >= 0 && arr[j] > key) { //Если предыдущий больше выбранного
            arr[j + 1] = arr[j]; // Перемещаем больший элемент на одно место вправо
            j = j - 1; 
        }
        arr[j + 1] = key; //Возвращаем выбранный элемент на место большего элемента, который мы передвинули
    }
}

int main() 
{
    /*QuickSort*/
    int IntArray[] = {52, 93, 9, 48, 5, 78, 43, 8};
    int SizeOfIntArray = sizeof(IntArray) / sizeof(IntArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfIntArray; i++) {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl;
    QuickSort(IntArray, SizeOfIntArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfIntArray; i++) {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl;

    /*InsertionSort*/
    double DoubleArray[] = { 52.3, 93.7, 9.3, 48.3, 523.4, 78.3, 43.0, 8.4 };
    int SizeOfDoubleArray = sizeof(DoubleArray) / sizeof(DoubleArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfDoubleArray; i++) {
        std::cout << DoubleArray[i] << " ";
    }
    std::cout << std::endl;
    InsertionSort(DoubleArray, SizeOfDoubleArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfDoubleArray; i++) {
        std::cout << DoubleArray[i] << " ";
    }
    std::cout << std::endl;

    /*BubbleSort*/
    char CharArray[] = { 'C', 'a', 'A', 'c', 'b', 'f', 'F', 'a' };
    int SizeOfCharArray = sizeof(CharArray) / sizeof(CharArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfCharArray; i++) {
        std::cout << CharArray[i] << " ";
    }
    std::cout << std::endl;
    BubbleSort(CharArray, SizeOfCharArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfCharArray; i++) {
        std::cout << CharArray[i] << " ";
    }

    return 0;
}
