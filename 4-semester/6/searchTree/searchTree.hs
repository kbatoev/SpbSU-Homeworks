data BinaryTree a = Nil | Node a (BinaryTree a) (BinaryTree a) deriving (Show, Read)


add :: (Ord a) => a -> BinaryTree a -> BinaryTree a
add x Nil = Node x Nil Nil
add x bt@(Node y l r) 
		  | x == y = bt
		  | x < y  = Node y (x `add` l) r
		  | otherwise = Node y l (x `add` r)  

remove :: (Ord a) => a -> BinaryTree a -> BinaryTree a
remove _ Nil = Nil
remove x (Node y l r) 
			| x == y && (size l == 0) = r
			| x == y && (size r == 0) = l
			| x == y                  = Node (biggestElem l) (remove (biggestElem l) l) r
			| x > y                   = Node y l (remove x r)
			| otherwise               = Node y (remove x l) r 


biggestElem :: (Ord a) => BinaryTree a -> a
biggestElem (Node x _ Nil) = x
biggestElem (Node x _ r)   = biggestElem r


lookupElem :: (Ord a) => a -> BinaryTree a -> String
lookupElem _ Nil = "No"
lookupElem x (Node y l r) 
			| x == y                  = "Yes"
			| lookupElem x l == "Yes" = "Yes"
			| otherwise               = lookupElem x r  

countHeight :: (Ord a) => BinaryTree a -> Int
countHeight Nil = 0
countHeight (Node x l r) = 1 + max (countHeight l) (countHeight r)

size :: (Ord a) => BinaryTree a -> Int
size Nil = 0
size (Node a l r) = 1 + size l + size r 


a = Node 4 Nil Nil
b = 3 `add` a
c = 5 `add` b	

