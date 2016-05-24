data Monomial = X Int Int -- first value is degree, second - factor

degree :: Monomial -> Int
degree (X d _) = d

factor :: Monomial -> Int
factor (X _ f) = f

instance Show Monomial where 
	show (X degree factor)
				| factor == 0 = "0"
				| degree == 0 = show factor
				| otherwise   = showFactor factor ++ "x" ++ showDegree degree
					where
						showFactor :: Int -> String
						showFactor f
							     | f == 1 	  = ""
							     | f > 0  	  = show f ++ "*"
							     | otherwise  = "(" ++ show f ++ ")*"
						showDegree :: Int -> String
						showDegree d 
							     | d == 1 	 = ""
							     | otherwise = "^" ++ show d


data Polynomial = Polynomial [Monomial] 

instance Show Polynomial where
	show (Polynomial list) = showP $ (filter isNotZero list)
		where 
			showP :: [Monomial] -> String
			showP []     = "0"
			showP [x]    = show x
			showP (x:xs) = show x ++ " + " ++ showP xs


simplify :: Polynomial -> Polynomial
simplify (Polynomial list) = Polynomial (filter isNotZero (simplifyInside list)) 
		
isNotZero :: Monomial -> Bool
isNotZero (X d f) = f /= 0


simplifyInside :: [Monomial] -> [Monomial]
simplifyInside [] = []
simplifyInside list@(x:xs) = (foldl1 addEqualDegreeMonomials list) : simplifyInside (filter (isDifferentDegree $ degree x) xs)
	where
		addEqualDegreeMonomials :: Monomial -> Monomial -> Monomial
		addEqualDegreeMonomials x y = if degree x == degree y
			      		      then X (degree x) (factor x + factor y)
					      else x

		isDifferentDegree :: Int -> Monomial -> Bool
		isDifferentDegree d m = degree m /= d


(<+>) :: Polynomial -> Polynomial -> Polynomial
(Polynomial a) <+> (Polynomial b) = simplify (Polynomial (a ++ b))
		

(<*>) :: Polynomial -> Polynomial -> Polynomial
(Polynomial []) <*> y                       = Polynomial []
(Polynomial a@(x:xs)) <*> bb@(Polynomial b) = simplify (Polynomial (map (multiplyMonomials x) b)) <+> ((Polynomial xs) <*> bb)
	where
		multiplyMonomials :: Monomial -> Monomial -> Monomial
		multiplyMonomials (X d1 f1) (X d2 f2) = X (d1 + d2) (f1 * f2)




a = Polynomial [X 1 1]
b = Polynomial [X 1 2]
c = Polynomial [(X 1 1), (X 2 1), (X 3 1)]
d = Polynomial [(X 1 2), (X 5 1)]
e = Polynomial [(X 1 2), (X 5 0)]








