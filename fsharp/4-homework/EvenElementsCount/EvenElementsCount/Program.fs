// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".


open NUnit.Framework
open FsUnit

let list1 = [1; 3; 5; 7]
let list2 = [2; 4; 6; 8]
let list3 = []
let list4 = [2]
let list5 = [3]



let countEvenElementsFilter = List.filter (fun x -> x % 2 = 0) >> List.length

let countEvenElementsFold = List.fold (fun acc x -> if x % 2 = 0 then acc + 1 else acc) 0

let countEvenElementsMap = List.map (fun x -> (x  + 1 ) % 2) >> List.sum


countEvenElementsFilter list1 |> should equal 0
countEvenElementsFilter list2 |> should equal 4
countEvenElementsFilter list3 |> should equal 0
countEvenElementsFilter list4 |> should equal 1
countEvenElementsFilter list5 |> should equal 0

countEvenElementsFold list1 |> should equal 0
countEvenElementsFold list2 |> should equal 4
countEvenElementsFold list3 |> should equal 0
countEvenElementsFold list4 |> should equal 1
countEvenElementsFold list5 |> should equal 0

countEvenElementsMap list1 |> should equal 0
countEvenElementsMap list2 |> should equal 4
countEvenElementsMap list3 |> should equal 0
countEvenElementsMap list4 |> should equal 1
countEvenElementsMap list5 |> should equal 0