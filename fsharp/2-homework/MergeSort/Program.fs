// Дополнительные сведения о F# см. на http://fsharp.net

module Microsoft.FSharp.Collections.List

let rec mergeSort list =
    let cnt = List.length list / 2

    let rec merge l1 l2 = 
        match l1 with
        | [] -> l2
        | (x :: xs) -> match l2 with
                        | [] -> l1
                        | (y :: ys) ->  if x < y 
                                        then x :: (merge xs l2) 
                                        else y :: (merge l1 ys)
    match list with
    | [x] -> [x]
    | _   -> merge (list |> Seq.take cnt |> Seq.toList |> mergeSort) (list |> Seq.skip cnt |> Seq.toList |> mergeSort)


let list = [1; 6; 2; 0; -1; 4; 3]
list |> mergeSort |> printf "The sorted list is %A\n"