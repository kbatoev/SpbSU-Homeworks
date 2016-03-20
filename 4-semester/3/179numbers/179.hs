list179 :: [Int]
list179 = [1, 7, 9] ++ [x * 10 + digit | x <- list179, digit <- [1, 7, 9]]
