getPrimeNumbers :: [Int]
getPrimeNumbers = filter (primeCondition 2) [2, 3..]

primeCondition :: Int -> Int -> Bool
primeCondition d x
		| x == d         = True
		| x `mod` d == 0 = False
		| otherwise      = primeCondition (d + 1) x		 
