cntDigits :: Int -> Int
cntDigits x
	  | x < 10 = 1
	  | otherwise = 1 + cntDigits (div x 10)  

list179 :: [Int]
list179 = list179
		where
	     	 list1 = [10 ^ (cntDigits x) + x | x <- list179]
	     	 list7 = [7 * 10 ^ (cntDigits x) + x| x <- list179]
	     	 list9 = [9 * 10 ^ (cntDigits x) + x| x <- list179]
	     	 list179 = [1, 7, 9] ++ concatBySorting list1 list7 list9

	     	 concatBySorting (x:xs) (y:ys) (z:zs)
				| x < y && x < z = [x] ++ concatBySorting xs (y:ys) (z:zs)
				| y < x && y < z = [y] ++ concatBySorting (x:xs) ys (z:zs)
				| otherwise = [z] ++ concatBySorting (x:xs) (y:ys) zs

