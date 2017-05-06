// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace InfiniteSequences

module NaturalNumbers =
 
  let infSeq = Seq.concat <| Seq.map (fun y -> Seq.init y (fun z -> y)) (Seq.initInfinite id)
  let infSeq100 = Seq.take 100 infSeq

  [<EntryPoint>]
  let main argv = 
    for i in infSeq100 do
      printf "%d " i
    0 // возвращение целочисленного кода выхода
