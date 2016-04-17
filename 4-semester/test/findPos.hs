findPosition :: (Eq a) => a -> [a] -> Int
findPosition x list = parse $ findPosition' x (0, False) list

parse :: (Int, Bool) -> Int
parse (_, False) = -1
parse (x, _)     = x

findPosition' :: (Eq a) => a -> (Int, Bool) -> [a] -> (Int, Bool)
findPosition' element (pos, status) list = foldl (\(p, s) x -> if s == True
							       then (p, s)
							       else if s == False && x == element
							            then (p, True)
							            else (p + 1, False)
						 ) (pos, status) list 
