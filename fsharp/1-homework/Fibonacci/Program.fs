// Дополнительные сведения о F# см. на http://fsharp.net

let fibonacci n = 
    let rec helper x y z = if z = n then x else helper y (x + y) (z + 1)
    helper 0 1 0
