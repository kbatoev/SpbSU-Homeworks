// Дополнительные сведения о F# см. на http://fsharp.net
let reverseList ls = 
    let rec helper list acc =
        match list with
        | [] -> acc
        | (x :: xs) -> helper xs (x :: acc)
    helper ls []