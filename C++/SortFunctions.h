#pragma once
#include <functional>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <chrono>

class SortFunctions
{
public:
	void executeAllSorts();
	void printVector(std::vector<int> printVector, std::string text);

	void swapNumbers(std::vector<int> &array, int swap_idxr, int swap_idxrl);
	std::vector<int> sliceVector(std::vector<int> toSlice, int start, int end);
	
	std::vector<int> insertionSort(std::vector<int> toSort, int n);
	std::vector<int> selectionSort(std::vector<int> toSort, int n);

	void mergeSort(std::vector<int> &toSort, int begin, int end);
	void merge(std::vector<int> &toMerge, int left_idx, int mid_idx, int right_idx);
	std::vector<int> runMergeSort(std::vector<int> toSort, int n);

	std::vector<int> quickSort(std::vector<int> &toSort, int low_idx, int high_idx);
	int partition(std::vector<int> &toSort, int low_idx, int high_idx);
	std::vector<int> runQuickSort(std::vector<int> toSort, int n);
};

