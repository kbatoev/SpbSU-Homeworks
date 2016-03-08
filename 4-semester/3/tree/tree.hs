data Tree a = Nil | Leaf a | Branch (Tree a) a (Tree a)
			deriving (Show)

countHeight :: Tree a -> Int
countHeight Nil = 0
countHeight (Leaf a) = 1
countHeight (Branch leftTree a rightTree) = 1 + max (countHeight leftTree) (countHeight rightTree)

countMinDistance :: Tree a -> Int
countMinDistance Nil = 0
countMinDistance (Leaf a) = 1
countMinDistance (Branch leftTree a rightTree) 
												| countMinDistance leftTree == 0  = 1 + countMinDistance rightTree
												| countMinDistance rightTree == 0 = 1 + countMinDistance leftTree
												| otherwise                       = 1 + min (countMinDistance leftTree) (countMinDistance rightTree)

--myTree :: Tree Int
--myTree = Branch (Branch (Leaf 12) 15 Nil) 20 (Branch Nil 21 (Branch Nil 22 (Branch Nil 23 (Leaf 24))))