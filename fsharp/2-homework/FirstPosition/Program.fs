// Дополнительные сведения о F# см. на http://fsharp.net

let findFirstPosition list number =
    let rec helper newList position =
        match newList with
        | [] -> -1
        | x :: xs -> if x = number then position else helper xs (position + 1)
    helper list 0
