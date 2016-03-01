overturn :: [Int] -> [Int]
overturn list = overturn' list []

overturn' :: [Int] -> [Int] -> [Int]
overturn' [] newList = newList
overturn' (x:xs) newList = overturn' xs (x : newList)
