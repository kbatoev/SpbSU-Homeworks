infix 6 :+:
infix 7 :*:
infixr 6 :-:
infixr 7 :/:
data Expr = Const Int |
	    X Int |
	    Expr :+: Expr |
	    Expr :*: Expr |
	    Expr :/: Expr |
	    Expr :-: Expr
		deriving (Read, Eq)

instance Show Expr where
	show expr = showExpr $ simplify expr
			where
				showExpr (Const c) 
						| c >= 0 = show c
						| otherwise = "(" ++ show c ++ ")"
				showExpr (X degree) = if degree == 1
						  then "x"
						  else "x^" ++ show degree
				showExpr (expr1 :+: expr2) = "(" ++ showExpr expr1 ++ " + " ++ showExpr expr2 ++ ")"
				showExpr (expr1 :-: expr2) = "(" ++ showExpr expr1 ++ " - " ++ showExpr expr2 ++ ")"
				showExpr (expr1 :*: expr2) = "(" ++ showExpr expr1 ++ " * " ++ showExpr expr2 ++ ")"
				showExpr (expr1 :/: expr2) = "(" ++ showExpr expr1 ++ " / " ++ showExpr expr2 ++ ")"

dx :: Expr -> Expr
dx (Const _) = Const 0
dx (X degree) = if degree == 1 
		then Const 1
		else (Const degree) :*: (X (degree - 1))

dx (expr1 :+: expr2) = simplify $ (dx expr1) :+: (dx expr2)
dx (expr1 :*: expr2) = simplify $ ((dx expr1) :*: expr2) :+: (expr1 :*: (dx expr2))
dx (expr1 :-: expr2) = dx (expr1 :+: (Const (-1)) :*: expr2)
dx (expr1 :/: expr2) = simplify $ ((dx expr1) :*: expr2 :-: expr1 :*: (dx expr2)) :/: (expr2 :*: expr2)


first :: (Int, Int) -> Int
first (a, b) = a

simplify :: Expr -> Expr
simplify ((Const 0) :+: expr2) = simplify expr2
simplify ((Const 0) :-: expr2) = (Const (-1)) :*: simplify expr2
simplify ((Const 0) :*: expr2) = Const 0
simplify ((Const 0) :/: expr2) = Const 0
simplify (expr1 :+: (Const 0)) = simplify expr1
simplify (expr1 :-: (Const 0)) = simplify expr1
simplify (expr1 :*: (Const 0)) = Const 0
simplify expr@(expr1 :*: expr2) 
			 	| hasDivision expr == False = makeExpr $ simplify' expr
				| otherwise                 = (simplify expr1) :*: (simplify expr2)
simplify expr@(expr1 :+: expr2) 
			 	| hasDivision expr == False = makeExpr $ simplify' expr
				| otherwise                 = (simplify expr1) :+: (simplify expr2)
simplify expr@(expr1 :-: expr2) 
			 	| hasDivision expr == False = makeExpr $ simplify' expr
				| otherwise                 = (simplify expr1) :-: (simplify expr2)
simplify (expr1 :/: expr2) = (simplify expr1) :/: (simplify expr2)
simplify expr = makeExpr $ simplify' expr

hasDivision :: Expr -> Bool
hasDivision (expr1 :/: expr2) = True
hasDivision (Const _)         = False
hasDivision (X _)             = False
hasDivision (expr1 :+: expr2) = hasDivision expr1 || hasDivision expr2
hasDivision (expr1 :-: expr2) = hasDivision expr1 || hasDivision expr2
hasDivision (expr1 :*: expr2) = hasDivision expr1 || hasDivision expr2

simplify' :: Expr -> [(Int, Int)]
simplify' (Const c) = [(0, c)]
simplify' (X d)     = [(d, 1)]
simplify' (expr1 :+: expr2) = add (simplify' expr1) (simplify' expr2)
simplify' (expr1 :*: expr2) = multiply (simplify' expr1) (simplify' expr2)
simplify' (expr1 :-: expr2) = simplify' (expr1 :+: (Const (-1) :*: expr2))

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
multiply [] _ 	     = []
multiply _ []        = []
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
