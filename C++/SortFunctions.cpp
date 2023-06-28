#include "SortFunctions.h"


void SortFunctions::swapNumbers(std::vector<int> &array, int swap_idxr, int swap_idxl) {
    int placeholder = array[swap_idxr];
    array[swap_idxr] = array[swap_idxl];
    array[swap_idxl] = placeholder;
}

std::vector<int> SortFunctions::sliceVector(std::vector<int> toSlice, int start, int size) {
    std::vector<int> vectorSlice(size);
    for (int i = 0; i < size; i++) {
        vectorSlice[i] = toSlice[start + i];
    }
    return vectorSlice;
}

std::vector<int> SortFunctions::insertionSort(std::vector<int> toSort, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = toSort[i];
        j = i - 1;

        while (j >= 0 && toSort[j] > key) {
            toSort[j + 1] = toSort[j];
            j = j - 1;
        }
        toSort[j + 1] = key;
    }
    return toSort;
}

std::vector<int> SortFunctions::selectionSort(std::vector<int> toSort, int n) {
    int i, min_idx, j;
    for (i = 0; i < n; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) if (toSort[j] < toSort[min_idx]) min_idx = j;
        if (min_idx != i) {
            swapNumbers(toSort, min_idx, i);
        }
    }
    return toSort;
}

void SortFunctions::merge(std::vector<int>& toMerge, int left_idx, int mid_idx, int right_idx) {
    int const leftSize = mid_idx - left_idx + 1;
    int const rightSize = right_idx - mid_idx;

    std::vector<int> leftSlice = sliceVector(toMerge, left_idx, leftSize);
    std::vector<int> rightSlice = sliceVector(toMerge, mid_idx + 1, rightSize);

    int x = 0;
    int y = 0;
    int indexX = left_idx;
    while (x < leftSlice.size() && y < rightSlice.size()) {
        if (leftSlice[x] <= rightSlice[y]) {
            toMerge[indexX] = leftSlice[x];
            x++;
        }
        else {
            toMerge[indexX] = rightSlice[y];
            y++;
        }
        indexX++;
    }

    while (x < leftSlice.size()) {
        toMerge[indexX] = leftSlice[x];
        x++;
        indexX++;
    }

    while (y < rightSlice.size()) {
        toMerge[indexX] = rightSlice[y];
        y++;
        indexX++;
    }
}

void SortFunctions::mergeSort(std::vector<int> &toSort, int begin, int end) {
    if (begin >= end) return;

    int mid = begin + (end - begin) / 2;
    mergeSort(toSort, begin, mid);
    mergeSort(toSort, mid + 1, end);
    merge(toSort, begin, mid, end);
}

std::vector<int> SortFunctions::runMergeSort(std::vector<int> toSort, int n) {
    mergeSort(toSort, 0, n-1);
    return toSort;
}

int SortFunctions::partition(std::vector<int> &toSort, int low_idx, int high_idx) {
    int pivot = toSort[high_idx];
    int i = low_idx - 1;
    for (int j = low_idx; j < high_idx; j++) {
        if (toSort[j] <= pivot) {
            i++;
            swapNumbers(toSort, i, j);
        }
    }
    swapNumbers(toSort, i + 1, high_idx);
    return i + 1;
}

std::vector<int> SortFunctions::quickSort(std::vector<int> &toSort, int low_idx, int high_idx) {
    if (low_idx < high_idx) {
        int part_idx = partition(toSort, low_idx, high_idx);
        quickSort(toSort, low_idx, part_idx - 1);
        quickSort(toSort, part_idx + 1, high_idx);
    }
    return toSort;
}

std::vector<int> SortFunctions::runQuickSort(std::vector<int> toSort, int n) {
    return quickSort(toSort, 0, n - 1);
}

void SortFunctions::executeAllSorts() {

    std::vector<int> toSort{ 35, 110, 48, 131, 152, 40, 112, 3, 100, 139
                            , 179, 27, 16, 10, 182, 24, 86, 54, 19, 156
                            , 101, 61, 56, 68, 155, 59, 121, 136, 145, 151
                            , 122, 47, 130, 39, 116, 146, 137, 78, 28, 192
                            , 25, 143, 9, 199, 45, 17, 63, 181, 89, 83 };

    auto start = std::chrono::steady_clock::now();
    std::vector<int> insertionSorted = insertionSort(toSort, toSort.size());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time insertion sort: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::steady_clock::now();
    std::vector<int> selectionSorted = selectionSort(toSort, toSort.size());
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time selection sort: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::steady_clock::now();
    std::vector<int> mergeSorted = runMergeSort(toSort, toSort.size());
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time merge sort: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::steady_clock::now();
    std::vector<int> quickSorted = runQuickSort(toSort, toSort.size());
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time quick sort: " << elapsed_seconds.count() << "s\n";
}

void SortFunctions::printVector(std::vector<int> printVector, std::string text) {
    std::cout << text << printVector.size() << " numbers: ";
    for (unsigned int i = 0; i < printVector.size(); i++) {
        std::cout << printVector[i] << ",";
    }
    std::cout << std::endl;
}

int main() {
    SortFunctions functions;
    functions.executeAllSorts();
}
