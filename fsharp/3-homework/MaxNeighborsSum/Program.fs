// Дополнительные сведения о F# см. на http://fsharp.net

let maxNeighborsSum list =
    let rec helper currentList maxSum currentPosition maxPosition =
        match currentList with
        | [x] -> maxPosition
        | x :: y :: xs -> if x + y > maxSum
                          then helper (y :: xs) (x + y) (currentPosition + 1) currentPosition
                          else helper (y :: xs) maxSum (currentPosition + 1) maxPosition
    match list with
    | x :: y :: xs -> Some (helper (y :: xs) (x + y) 2 1)
    | _ -> None 