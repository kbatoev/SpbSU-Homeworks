data Tree a = Nil | Node (Tree a) a (Tree a) deriving (Show)

makeListLessZero :: Tree Int -> [Int]
makeListLessZero tree = makeListLessZero' tree []
	where makeListLessZero' :: Tree Int -> [Int] -> [Int]
	      makeListLessZero' Nil acc = acc
	      makeListLessZero' (Node leftTree a rightTree) acc =  if a < 0
								   then (a : makeListLessZero' rightTree (makeListLessZero' leftTree acc))
								   else makeListLessZero' rightTree (makeListLessZero' leftTree acc)



myTree :: Tree Int
myTree = Node (Node (Node Nil (-109) Nil) (-45) Nil) (-5) (Node Nil (-4) (Node Nil 0 (Node Nil 23 (Node Nil 24 Nil))))
