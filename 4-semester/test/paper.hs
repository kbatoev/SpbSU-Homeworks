data Paper = Book {name :: String, author :: String, price :: Int} | Magazine {name :: String, year :: Int, number :: Int, price :: Int}

countPrice :: [Paper] -> Int
countPrice []     = 0
countPrice (x:xs) = price x + countPrice xs
