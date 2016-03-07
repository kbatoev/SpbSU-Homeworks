list179 :: [Int]
list179 = list179
		where
	     	 list1 = [x * 10 + 1 | x <- list179]
	     	 list7 = [x * 10 + 7 | x <- list179]
	     	 list9 = [x * 10 + 9 | x <- list179]
	     	 list179 = [1, 7, 9] ++ concatBySorting list1 list7 list9
		
		 concatBySorting :: (Ord a) => [a] -> [a] -> [a] -> [a]
	     	 concatBySorting (x:xs) (y:ys) (z:zs)
				| x < y && x < z = [x] ++ concatBySorting xs (y:ys) (z:zs)
				| y < x && y < z = [y] ++ concatBySorting (x:xs) ys (z:zs)
				| otherwise = [z] ++ concatBySorting (x:xs) (y:ys) zs

