data Tree a = Nil | Node (Tree a) a (Tree a) deriving (Show)

lookupTree :: (Eq a) => Tree a -> (a -> Bool) -> Maybe a
lookupTree Nil condition = Nothing
lookupTree (Node leftTree value rightTree) condition
							| condition value = Just value
							| lookupTree leftTree condition /= Nothing = lookupTree leftTree condition
							| otherwise = lookupTree rightTree condition



foldTree :: (a -> b -> a) -> a -> Tree b -> a
foldTree func acc Nil = acc
foldTree func acc (Node leftTree value rightTree) = func (foldTree func (foldTree func acc leftTree) rightTree) value 
