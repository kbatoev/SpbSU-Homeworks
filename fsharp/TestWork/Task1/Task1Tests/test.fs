namespace Task1Tests

open InfiniteSequences
open NUnit.Framework
open FsUnit

module Tests = 

  [<Test>]
  let checkHeadOfSequence () =
    Seq.head NaturalNumbers.infSeq |> should equal 1

  [<Test>]
  let checkAmountOf7 () =
    Seq.length <| Seq.filter (fun x -> x = 7) NaturalNumbers.infSeq100 |> should equal 7
  
  [<Test>]
  let checkExistenceOfBigNumber () =
    Seq.exists (fun x -> x = 1000) NaturalNumbers.infSeq |> should equal true

  [<Test>]
  let checkAscending () =
    Seq.toList NaturalNumbers.infSeq100 |> should be ascending

