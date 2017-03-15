// Дополнительные сведения о F# см. на http://fsharp.net

let factorial n = 
    let rec helper n acc = if n = 0 then acc else helper (n - 1) (n * acc)
    helper n 1