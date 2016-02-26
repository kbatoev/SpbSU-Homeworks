createListOfTwo :: Int -> [Int]
createListOfTwo n = [2 ^ x | x <- [0, 1 .. n]]
