// Дополнительные сведения о F# см. на http://fsharp.net

let listOfDegrees n m =
    let degreeNM =
        let rec n2 i acc = if i = n + m then acc else n2 (i + 1) (acc * 2)
        n2 0 1
    let rec helper list i degree = if i < n then list else helper (degree :: list) (i - 1) (degree / 2)
    helper [] (n + m) degreeNM
