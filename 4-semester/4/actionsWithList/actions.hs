main = doActions []

doActions :: [Int] -> IO ()
doActions list = do
		showActions
		choice <- getLine 
		case read (choice) :: Int of
			0 -> return ()
			1 -> addNumber list
			2 -> removeNumber list
			3 -> printList list list

showActions :: IO ()
showActions = do
		putStrLn "Enter value: "
		putStrLn "0 - exit"
		putStrLn "1 - add number"
		putStrLn "2 - remove number"
		putStrLn "3 - print List"
	
addNumber :: [Int] -> IO ()
addNumber [] = do
		str <- getLine
		doActions [read str :: Int]
addNumber list = do
		str <- getLine
		let number = read str :: Int		
		let list' = sortList (number:list)
		doActions list'


removeNumber :: [Int] -> IO ()
removeNumber list = do
			str <- getLine
			let number = read str :: Int
			doActions $ filter (/=number) list


sortList :: [Int] -> [Int]
sortList [] = []
sortList [x] = [x]
sortList (a:b:c)
		| a < b = (a:b:c)
		| otherwise = (b:(sortList(a:c))) 

printList :: [Int] -> [Int] -> IO ()
printList list [] = (putStrLn "") >> doActions list
printList list (x:xs) = do
		   	putStr ((show x) ++ " ")
		   	printList list xs 

