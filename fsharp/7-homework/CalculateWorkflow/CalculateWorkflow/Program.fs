// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Workflows

open Microsoft.FSharp.Core

module Calculator =
  let compareDoubles n1 n2 =
    match (n1, n2) with
    | (None, _) -> false
    | (_, None) -> false
    | (Some x1, Some x2) -> abs(x1 - x2) <= 0.000001

  type NumberBuilder() =
    member this.Bind(x, f) =
      let rec convertListOfCharsToDouble list acc degree = 
        match list with
        | [] when degree <> 0.1 -> Some acc
        | (x :: xs) when (int x) >= 48 && (int x) <= 57 ->
          let digit = double <| int x - 48
          if degree = 1.0
          then convertListOfCharsToDouble xs (acc * 10.0 + digit) 1.0
          else convertListOfCharsToDouble xs (acc + digit * degree) (degree / 10.0)
        | x :: xs when (x = '.' || x = ',') && degree = 1.0 -> convertListOfCharsToDouble xs acc 0.1
        | _ -> None


      match (box x) with
      | :? int as n -> let number = double <| n
                       f number
      | :? double as n -> f n
      | :? string as str -> let number = convertListOfCharsToDouble (Seq.toList str) 0.0 1.0
                            match number with
                            | None -> None
                            | Some n -> f n
      | _ -> None

    member this.Return(x) =
      Some x


  [<EntryPoint>]
  let main argv = 
      let calculate = new NumberBuilder()

      let res = calculate {
          let! x = 123
          let! y = "901"
          let z = x + y
          return z
      }

      let res2 = calculate {
          let! a = "90.Hello, world!"
          let! b = "38"
          return a + b
          }

      let res3 = calculate {
          let! a = "12.0"
          let! b = "555,9"
          return a + b
          }

      printfn "res = %A" <| res
      printfn "res2 = %A" <| res2
      printfn "res3 = %A" <| res3

      0 // возвращение целочисленного кода выхода
