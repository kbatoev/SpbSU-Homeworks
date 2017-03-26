// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace EvenElements

module Functions = 

  let countEvenElementsFilter xs = (List.filter (fun x -> x % 2 = 0) xs) |> List.length

  let countEvenElementsFold xs = List.fold (fun acc x -> if x % 2 = 0 then acc + 1 else acc) 0 xs

  let countEvenElementsMap xs = List.map (fun x -> (x + 1) % 2) xs |> List.sum
