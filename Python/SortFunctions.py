import copy
from timeit import default_timer as timer

def insertionSort(toSort, n):
    for i in range(1, n):
        key = toSort[i]
        j = i - 1
        while j >= 0 and toSort[j] > key:
            toSort[j+1] = toSort[j]
            j -= 1
        toSort[j+1] = key

def selectionSort(toSort,n):
    for i in range(0,n):
        min_idx = i
        for j in range(i+1,n):
            if toSort[j] < toSort[min_idx]:
                min_idx = j
        if min_idx is not i:
            toSort[min_idx], toSort[i] = toSort[i], toSort[min_idx]

def mergeSort(toSort, n):
    if n > 1:
        middle = n//2

        sortLeft = toSort[:middle]
        sortRight = toSort[middle:]
        mergeSort(sortLeft,len(sortLeft))
        mergeSort(sortRight,len(sortRight))

        i = 0
        j = 0
        k = 0
        while i < len(sortLeft) and j < len(sortRight):
            if sortLeft[i] <= sortRight[j]:
                toSort[k] = sortLeft[i]
                i += 1
            else:
                toSort[k] = sortRight[j]
                j += 1
            k += 1

        while i < len(sortLeft):
            toSort[k] = sortLeft[i]
            i += 1
            k += 1

        while j < len(sortRight):
            toSort[k] = sortRight[j]
            j += 1
            k += 1

def partition(toSort,low, high):
    pivot = toSort[high]
    i = low - 1
    for j in range(low,high):
        if toSort[j] <= pivot:
            i += 1
            toSort[i], toSort[j] = toSort[j], toSort[i]
    toSort[i+1], toSort[high] = toSort[high], toSort[i+1]
    return i + 1

def quickSort(toSort, low, high):
    if low < high:
        pi = partition(toSort, low, high)
        quickSort(toSort, low, pi-1)
        quickSort(toSort, pi+1, high)

def callQuickSort(toSort,n):
    low = 0
    high = n-1
    quickSort(toSort, low, high)

def timeSortFunction(function,toSort,arrayLength):
    start = timer()
    function(toSort,arrayLength)
    elapsedTime = timer() - start
    print(str(function) + "Finished in " + str(elapsedTime) + " seconds")

def testSortFunction(function,toSort,arrayLength,expected):
    function(toSort,arrayLength)
    if expected == toSort:
        print(str(function) + " correctly sorted")
    else:
        print(str(function) + " sorting failed")

def testSorts():
    expected = [1,2,3,4,5,6,7,8,9,10]
    toSort = [6,4,2,10,1,9,3,8,5,7]
    testSortFunction(insertionSort, copy.copy(toSort), len(toSort),expected)
    testSortFunction(selectionSort, copy.copy(toSort), len(toSort),expected)
    testSortFunction(mergeSort, copy.copy(toSort), len(toSort),expected)
    testSortFunction(callQuickSort, copy.copy(toSort), len(toSort),expected)

def main():
    testSorts()

    arrayToSortLong = [35, 110, 48, 131, 152, 40, 112, 3, 100, 139
        , 179, 27, 16, 10, 182, 24, 86, 54, 19, 156
        , 101, 61, 56, 68, 155, 59, 121, 136, 145, 151
        , 122, 47, 130, 39, 116, 146, 137, 78, 28, 192
        , 25, 143, 9, 199, 45, 17, 63, 181, 89, 83 ]

    timeSortFunction(insertionSort, copy.copy(arrayToSortLong), len(arrayToSortLong))
    timeSortFunction(selectionSort, copy.copy(arrayToSortLong), len(arrayToSortLong))
    timeSortFunction(mergeSort, copy.copy(arrayToSortLong), len(arrayToSortLong))
    timeSortFunction(callQuickSort, copy.copy(arrayToSortLong), len(arrayToSortLong))


main()