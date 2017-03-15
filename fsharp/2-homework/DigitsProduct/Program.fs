// Дополнительные сведения о F# см. на http://fsharp.net

let digitsProduct n =
    let rec helper x acc = 
        if x < 10
        then x * acc
        else helper (x / 10) (x % 10 * acc)
    if n < 0
    then helper (-n) 1
    else helper n 1