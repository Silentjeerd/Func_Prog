from time import time
import copy

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
    print(toSort)
    start = time()
    function(toSort,arrayLength)
    elapsedTime = time() - start
    print(toSort)
    print(str(function) + " finished in " + str(elapsedTime) + " seconds")

def main():
    arrayToSort = [18, 12, 23, 21, 17, 48, 2, 48, 38, 35, 35, 13, 40, 49, 29, 35, 4, 45, 12, 48]

    print("Starting")
    timeSortFunction(insertionSort, copy.copy(arrayToSort), len(arrayToSort))
    timeSortFunction(selectionSort, copy.copy(arrayToSort), len(arrayToSort))
    timeSortFunction(mergeSort, copy.copy(arrayToSort), len(arrayToSort))
    timeSortFunction(callQuickSort, copy.copy(arrayToSort), len(arrayToSort))
    print("Finished")

main()