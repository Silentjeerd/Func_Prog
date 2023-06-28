{-# LANGUAGE MonoLocalBinds #-}
module Lib
    ( swapNumbers,
      insertNumber,
      insertionSort,
      findLowestNumber,
      indexOfLowest,
      indexOfNumber,
      splitList,
      merge,
      mergeSort,
      selectionSort,
      selectionSort2,
      quickSort
    ) where

import Data.List ( elemIndex )
import Data.Maybe ( fromJust )

findLowestNumber :: [Int] -> Int
findLowestNumber [] = 0
findLowestNumber [x] = x
findLowestNumber (x:y:xs) = if x <= y
                            then findLowestNumber (x:xs)
                            else findLowestNumber (y:xs)

indexOfLowest :: [Int] -> Int
indexOfLowest list = indexOfNumber (findLowestNumber list) list

indexOfNumber :: Int -> [Int] -> Int
indexOfNumber number list = fromJust (elemIndex number list)

swapNumbers :: Int -> Int -> [Int] -> [Int]
swapNumbers i j ls = [get k x | (k,x) <- zip [0..length ls - 1] ls]
    where get k x | k == i = ls !! j
                  | k == j = ls !! i
                  | otherwise = x

insertNumber :: Int -> [Int] -> [Int]
insertNumber number [] = [number]
insertNumber number (x:xs) = if number < x
                       then number:x:xs
                       else x : insertNumber number xs

insertionSort :: [Int] -> [Int]
insertionSort [] = []
insertionSort [x] = [x]
insertionSort (x:xs) = insertNumber x (insertionSort xs)

selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort [x] = [x]
selectionSort (x:xs) = if indexOfNumber x (x:xs) == indexOfLowest (x:xs)
                             then x : selectionSort xs
                             else y : selectionSort ys where 
                                y:ys = swapNumbers (indexOfNumber x (x:xs)) (indexOfLowest (x:xs)) (x:xs)

selectionSort2 :: [Int] -> [Int]
selectionSort2 [] = []
selectionSort2 [x] = [x]
selectionSort2 list = lowestNumList ++ selectionSort2 listMinusLowest
                        where lowestNumList = [y | y<-list, y == findLowestNumber list]
                              listMinusLowest = [y |y<-list, y /= findLowestNumber list]

splitList :: [Int] -> ([Int],[Int])
splitList list
  = case list of
      [] -> ([], [])
      x : xs -> let (odds, evens) = splitList xs in (x : evens, odds)

merge :: [Int] -> [Int] -> [Int]
merge [] [] = []
merge [x] [] = [x]
merge [] (x:xs) = merge [x] xs
merge (x:xs) [] = merge [x] xs
merge [x] (y:ys) = if x <= y 
                       then x : merge [y] ys 
                       else y : merge [x] ys
merge (x:xs) (y:ys) = if x <= y
                         then x : merge xs (y:ys)
                         else y : merge ys (x:xs) 

mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort (x:xs) = merge (mergeSort split1) (mergeSort split2)
               where (split1, split2) = splitList (x:xs)

quickSort :: [Int] -> [Int]
quickSort [] = []
quickSort [x] = [x]
quickSort (x:xs) = quickSort left ++ partitions ++ quickSort right
        where left = [y | y<-xs , y < x]
              partitions = x : [y | y<-xs , y == x] 
              right = [y | y<-xs , y > x]

