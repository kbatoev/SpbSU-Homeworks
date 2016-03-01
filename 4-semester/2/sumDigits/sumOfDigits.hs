countSum :: Int -> Int
countSum number =  sum' number 0

sum' :: Int -> Int -> Int
sum' 0 x = x
sum' number x = sum' (number `div` 10) (x + number `mod` 10) 
