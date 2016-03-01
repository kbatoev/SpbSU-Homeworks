checkString :: [Char] -> Bool
checkString str = checkString' str 0 (length str - 1)


checkString' :: [Char] -> Int -> Int -> Bool
checkString' str leftIndex rightIndex = if leftIndex > rightIndex
					then True
					else if (str !! leftIndex) /= (str !! rightIndex)
					     then False
					     else checkString' str (leftIndex + 1) (rightIndex - 1)  
