import Control.Monad

main = getLine >>= (\x -> makePairs (read x) 1 1 [])


makePairs :: Int -> Int -> Int -> [String]-> IO ()
makePairs number left right list = makeElem left right >>= (\x -> if number >= left 
                                                                  then makePairs number (left + right `div` number) (right `mod` number + 1) (x:list)
                                                                  else print $ reverse list
                                                            )

makeElem :: Int -> Int -> IO String
makeElem left right = return ((show left) ++ "*" ++ (show right))
