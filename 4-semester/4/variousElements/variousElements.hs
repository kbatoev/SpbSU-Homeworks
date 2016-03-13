import Data.List

checkUniqueness :: (Ord a) => [a] -> Bool
checkUniqueness list = checkUniqueness' (sort list) []
			where checkUniqueness' :: (Ord a) => [a] -> [a] -> Bool
			      checkUniqueness' [] _              = True
			      checkUniqueness' (x:xs) []         = checkUniqueness' xs [x]
			      checkUniqueness' (x:xs) acc@(y:yx) = if x == y
								    then False
								    else checkUniqueness' xs (x:acc) 
