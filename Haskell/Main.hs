module Main (main) where
import Lib (insertionSort,selectionSort,selectionSort2,mergeSort,quickSort)

main :: IO ()
main = do
    let toSort = [18, 12, 23, 21, 17, 48, 2, 48, 38, 35, 35, 13, 40, 49, 29, 35, 4, 45, 12, 48,8]

    print "Start sorting."

    print "Selection sorting:"
    print toSort
    let selectionSorted = selectionSort toSort
    print selectionSorted

    print "Selection sorting2:"
    print toSort
    let selectionSorted2 = selectionSort2 toSort
    print selectionSorted2

    print "Insertion sorting:"
    print toSort
    let insertionSorted = insertionSort toSort
    print insertionSorted

    print "Quick sorting:"
    print toSort
    let quickSorted = quickSort toSort
    print quickSorted

    print "Merge sorting:"
    print toSort
    let mergeSorted = mergeSort toSort
    print mergeSorted

    print "Sorting done."


