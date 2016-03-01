findFirst :: [Int] -> Int -> Int
findFirst list number = findFirst' list number 0

findFirst' :: [Int] -> Int -> Int -> Int
findFirst' [] _ _ = -1
findFirst' (x:xs) number pos = if x == number
			       then pos
			       else findFirst' xs number (pos + 1) 
