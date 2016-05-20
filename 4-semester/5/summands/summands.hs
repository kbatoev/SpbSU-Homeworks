import Control.Monad

main = do 
		str <- getLine
		let number = read str :: Int
		makeSums 1 number []


makeSums :: Int -> Int -> [Int] -> IO ()
makeSums start number list = do
								if number == 0
						 		then print list 
								else 
									if start > number
								 	then return ()
								 	else
								 		do
								 		forM_ [start .. number] $ \x -> do
								 											let newStart = x
								 											let newNumber = number - x
								 											let newList = x : list
								 											makeSums newStart newNumber newList 

