fibonacci :: Int -> Int
fibonacci i = if i < 2 
	      then 1
	      else fibonacci (i - 1) + fibonacci (i - 2)
	      
