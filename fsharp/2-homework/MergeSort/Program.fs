// Дополнительные сведения о F# см. на http://fsharp.net

//module Microsoft.FSharp.Collections.List
//module System.IO.StreamWriter

let rec mergeSort list =    
    match list with
    | [x] -> [x]
    | _   -> let cnt = List.length list / 2

             let merge list1 list2 =
                let rec helper acc (l1, l2) =
                    match (l1, l2) with
                    | ([], []) -> List.rev acc
                    | ([], y :: ys) -> helper (y :: acc) ([], ys)
                    | (x :: xs, []) -> helper (x :: acc) (xs, [])
                    | (x :: xs, y :: ys) when x < y -> helper (x :: acc) (xs, l2)
                    | (x :: xs, y :: ys) -> helper (y :: acc) (l1, ys) 
                helper [] (list1, list2)
    
             let l1, l2 =
                let rec splitList currentList acc n = if n = cnt
                                                      then currentList, acc
                                                      else splitList (List.tail currentList) ((List.head currentList) :: acc) (n + 1)
                splitList list [] 0
             merge (mergeSort l1) (mergeSort l2)

// let list = [1; 6; 2; 0; -1; 4; 3]
let list = List.init 20000 id
mergeSort list |> printf "The sorted list is %A\n"