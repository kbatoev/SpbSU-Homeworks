// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Figures

module Square =

  let printSquare n =
    match n with
    | 1 -> printfn "*\n"
    | x when x <= 0 -> printfn "side must be more than 0\n"
    | _ ->
        let side = String.replicate n "*"
        printfn "%s" side
        let edgeSide = "*" + String.replicate (n - 2) " " + "*"
        let rec printEdgeSides i =
          if i = n - 2
          then ()
          else printfn "%s" edgeSide
               printEdgeSides (i + 1)
        printEdgeSides 0
        printfn "%s\n" side

  [<EntryPoint>]
  let main argv =
    printfn "Square with side -8:"
    printSquare (-8)
    printfn "Square with side 1:"
    printSquare 1
    printfn "Square with side 2:"
    printSquare 2
    printfn "Square with side 4:"
    printSquare 4
    printfn "Square with side 10:"
    printSquare 10
    0 // возвращение целочисленного кода выхода
