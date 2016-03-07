checkBracketSequence :: [Char] -> Bool
checkBracketSequence str = checkSequence str []

checkSequence :: [Char] -> [Char] -> Bool
checkSequence [] []     = True
checkSequence [] _      = False

checkSequence (s:rs) [] 
							| s == ')' || s == '}' || s == ']' = False
							| s == '(' || s == '{' || s == '[' = checkSequence rs [s]
							| otherwise                        = checkSequence rs []
			   
checkSequence (s:rs) bList@(b:rb)
							| s == ')' && b /= '('		       = False
							| s == '}' && b /= '{' 		       = False
							| s == ']' && b /= '['             = False
							| s == ')' || s == '}' || s == ']' = checkSequence rs rb
							| s == '(' || s == '{' || s == '[' = checkSequence rs (s:bList)
							| otherwise                        = checkSequence rs bList