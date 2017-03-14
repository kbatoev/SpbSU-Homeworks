// Дополнительные сведения о F# см. на http://fsharp.net

let findFirstPosition list number =
    let rec helper newList position =
        match newList with
        | [] -> None
        | x :: xs -> if x = number then Some position else helper xs (position + 1)
    helper list 0
