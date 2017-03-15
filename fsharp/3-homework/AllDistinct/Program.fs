// Дополнительные сведения о F# см. на http://fsharp.net

let rec allDistinct list =
    match list with
    | [] -> true
    | x :: xs -> if List.exists ((=) x) xs 
                 then false 
                 else allDistinct xs 