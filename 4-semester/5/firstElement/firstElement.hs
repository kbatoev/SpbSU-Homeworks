import Control.Monad

main = getLine >>= \x -> findElement (makeMaybe (read x)) >>= print 

makeMaybe :: [Int] -> [Maybe Int]
makeMaybe [] = []
makeMaybe (x:xs) = (Just x) : makeMaybe xs 

findElement :: [Maybe Int] -> IO (Maybe Int)
findElement list = zipWithM isMore list (nextElem list) >>= \y -> zipWithM isMore y (prevElem list) >>= \x -> return (foldl1 (mplus) x)


isMore :: Maybe Int -> Maybe Int -> IO (Maybe Int)
isMore Nothing _ = return (Nothing)
isMore (Just value1) (Just value2) 
									| value1 > value2 = return (Just value1)
									| otherwise 	  = return (Nothing)

nextElem :: [Maybe Int] -> [Maybe Int]
nextElem [] = []
nextElem (x:xs) = xs ++ [last xs]

prevElem :: [Maybe Int] -> [Maybe Int]
prevElem [] = []
prevElem list@(x:xs) = [x] ++ take (length list - 1) list 


