sumTwoNeighbours :: [Int] -> [Int]
sumTwoNeighbours list = [leftNeighbour x + rightNeighbour x | x <- [0 .. length list - 1]]
			where
				leftNeighbour x = if x == 0
				      		  then 0
				      		  else list !! (x - 1) 

				rightNeighbour x = if x == length list - 1
				      		   then 0
				      		   else list !! (x + 1)

findMax :: [Int] -> Int
findMax [] = -1
findMax (x:xs) = findMax' xs 1 x 0 

findMax' :: [Int] -> Int -> Int -> Int -> Int
findMax' [] _ _ position = position + 1
findMax' (x:xs) currentPos maxValue maxPosition = if x > maxValue
						  then findMax' xs (currentPos + 1) x currentPos
						  else findMax' xs (currentPos + 1) maxValue maxPosition

findPositionOfMaxSum :: [Int] -> Int
findPositionOfMaxSum list = findMax $ sumTwoNeighbours $ list
