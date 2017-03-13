// Дополнительные сведения о F# см. на http://fsharp.net

let maxNeighborsSum list =
    let rec helper a b c list maxSum currentPosition maxPosition =
        let currentSum = a + c
        match list with
        | [] -> if currentSum >= maxSum then currentPosition else maxPosition
        | x :: xs -> if currentSum >= maxSum
                     then helper b c x xs currentSum (currentPosition + 1) currentPosition
                     else helper b c x xs maxSum (currentPosition + 1) maxPosition
    match list with
    | x :: y :: z :: xs -> Some (helper x y z xs (x + z) 1 1)
    | _ -> None 
