// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace NumbersCalculus

module NumbersRounding =

  type RoundingNumbersBuilder(precision :int) = 
    member this.Bind(x :double, f : double -> double) =
      let xWithPrecision = System.Math.Round(x, precision) 
      System.Math.Round (f xWithPrecision, precision)

    member this.Return (x :double) = System.Math.Round (x, precision)

  [<EntryPoint>]
  let main argv =
    let rounding = new RoundingNumbersBuilder(3)
    let res = rounding {
      let! a = 2.0 / 12.0
      let! b = 3.5
      return a / b
      }

    printfn "(2.0 / 12.0) / 3.5 = %A with precision 3" <| res
    0 // возвращение целочисленного кода выхода
