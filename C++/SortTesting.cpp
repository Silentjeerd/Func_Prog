#include "pch.h"
#include "CppUnitTest.h"
#include "../C++_Func_Prog/SortFunctions.h"
#include "../C++_Func_Prog/SortFunctions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortTesting
{
	TEST_CLASS(SortTesting)
	{
	public:
		std::vector<int> toSort{ 10,12,1,4,20,6,8 };
		std::vector<int> expected{ 1,4,6,8,10,12,20 };
		SortFunctions sorting;

		TEST_METHOD(insertionSort)
		{
			std::vector<int> sorted = sorting.insertionSort(toSort, toSort.size());
			Assert::IsTrue(expected == sorted);
		}

		TEST_METHOD(selectionSort)
		{
			std::vector<int> sorted = sorting.selectionSort(toSort, toSort.size());
			Assert::IsFalse(toSort == expected);
			Assert::IsTrue(expected == sorted);
		}

		TEST_METHOD(mergeSort) 
		{
			std::vector<int> sorted = sorting.runMergeSort(toSort, toSort.size());
			Assert::IsFalse(toSort == expected);
			Assert::IsTrue(expected == sorted);
		}
		TEST_METHOD(quickSort) 
		{
			std::vector<int> sorted = sorting.runQuickSort(toSort, toSort.size());
			Assert::IsFalse(toSort == expected);
			Assert::IsTrue(expected == sorted);
		}

	};
}
