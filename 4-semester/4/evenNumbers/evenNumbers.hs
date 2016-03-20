countWithFilter :: [Int] -> Int  
countWithFilter = length . filter even

countWithMap :: [Int] -> Int
countWithMap = sum . map ((`mod` 2) . (+1))

countWithFoldr :: [Int] -> Int
countWithFoldr = foldr (\x acc -> if even x then acc + 1 else acc) 0 


