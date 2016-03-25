sumAndDiv :: (Floating a) => [a] -> a
sumAndDiv list = foldl (\acc x -> acc / cos x) (sum list) list
