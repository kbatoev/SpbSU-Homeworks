// Дополнительные сведения о F# см. на http://fsharp.net


module Microsoft.FSharp.Collections.List

let isPalindrome str =
    let listOfChars = 
        str |> Seq.toList
    let reverseList = 
        let rec reverse list acc = 
            match list with
            | [] -> acc
            | x :: xs -> reverse xs (x :: acc)
        reverse listOfChars []
    listOfChars |> List.zip reverseList |> List.fold (fun acc (x,y) -> (x = y) && acc) true
