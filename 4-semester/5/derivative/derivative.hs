infix 6 :+:
infix 7 :*:
data Expr = Const Int |
	    X Int |
	    Expr :+: Expr |
	    Expr :*: Expr
		deriving (Read, Eq)


countHeight :: Expr -> Int
countHeight (Const _) = 1
countHeight (X _ ) = 1
countHeight (expr1 :+: expr2) = 1 + min (countHeight expr1) (countHeight expr2) 
countHeight (expr1 :*: expr2) = 1 + min (countHeight expr1) (countHeight expr2)

instance Show Expr where
	show (Const c) 
			| c >= 0 = show c
			| otherwise = "(" ++ show c ++ ")"
	show (X degree) = if degree == 1
			  then "x"
			  else "x^" ++ show degree
	show (expr1 :+: expr2) = show expr1 ++ " + " ++ show expr2
	show (expr1 :*: expr2) 
				| countHeight expr1 > 1 && countHeight expr2 > 1 = "(" ++ show expr1 ++ ")" ++ " * " ++ "(" ++ show expr2 ++ ")"
				| countHeight expr1 > 1                          = "(" ++ show expr1 ++ ")" ++ " * " ++ show expr2
				| countHeight expr2 > 1                          = show expr1 ++ " * " ++ "(" ++ show expr2 ++ ")"
				| otherwise                                      = show expr1 ++ " * " ++ show expr2

dx :: Expr -> Expr
dx (Const _) = Const 0
dx (X degree) = 
		| degree == 1 = Const 1
		| otherwise   = (Const degree) :*: (X (degree - 1))

dx (expr1 :+: expr2) = simplify $ (dx expr1) :+: (dx expr2)
dx (expr1 :*: expr2) = simplify $ ((dx expr1) :*: expr2) :+: (expr1 :*: (dx expr2))

first :: (Int, Int) -> Int
first (a, b) = a

simplify :: Expr -> Expr
simplify expr = makeExpr $ simplify' expr

simplify' :: Expr -> [(Int, Int)]
simplify' (Const c) = [(0, c)]
simplify' (X d)     = [(d, 1)]
simplify' (expr1 :+: expr2) = add (simplify' expr1) (simplify' expr2)
simplify' (expr1 :*: expr2) = multiply (simplify' expr1) (simplify' expr2)

add :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
add [] expr = expr
add expr [] = expr
add (x:xs) expr = (foldl summarize x expr) : (add xs (filter (isDifferentDegree $ first x) expr))
	where
		summarize :: (Int, Int) -> (Int, Int) -> (Int, Int)
		summarize (d1, f1) (d2, f2) 
			   		    | d1 == d2 = (d1, f1 + f2)
			   		    | otherwise = (d1, f1)

		isDifferentDegree :: Int -> (Int, Int) -> Bool
		isDifferentDegree d (a, b) = a /= d

multiply :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
multiply [] _ = []
multiply _ [] = []
multiply (x:xs) expr = map (func x) expr `add` multiply xs expr
	where 
		func :: (Int, Int) -> (Int, Int) -> (Int, Int)
		func (d1, f1) (d2, f2) 
					| f1 == 0 || f2 == 0 = (0, 0)
					| otherwise          = (d1 + d2, f1 * f2)

makeExpr :: [(Int, Int)] -> Expr
makeExpr [(d, f)]
		  | d == 0 = Const f
		  | f == 1 = X d
		  | otherwise = (Const f) :*: (X d)
makeExpr (x:xs) = makeExpr [x] :+: makeExpr xs 


a = Const 5
b = X 1
c = X 4
d = a :+: b
e = b :*: c
