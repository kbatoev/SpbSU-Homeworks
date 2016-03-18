data Tree a = Nil | Node (Tree a) a (Tree a) deriving (Show)

countHeight :: Tree a -> Int
countHeight Nil = 0
countHeight (Node leftTree a rightTree) = 1 + max (countHeight leftTree) (countHeight rightTree)

countMinDistance :: Tree a -> Int
countMinDistance Nil = 0
countMinDistance (Node leftTree a rightTree) 
					| countMinDistance leftTree == 0  = 1 + countMinDistance rightTree
					| countMinDistance rightTree == 0 = 1 + countMinDistance leftTree
					| otherwise                       = 1 + min (countMinDistance leftTree) (countMinDistance rightTree)

--myTree :: Tree Int
--myTree = Node (Node (Node Nil 12 Nil) 15 Nil) 20 (Node Nil 21 (Node Nil 22 (Node Nil 23 (Node Nil 24 Nil))))
