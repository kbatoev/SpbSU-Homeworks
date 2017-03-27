namespace PrimeNumbersTest

open PrimeNumbers.Sequence
open NUnit.Framework
open FsUnit

module Tests = 

  [<Test>]
  let check35ToNotBePrime () =
    isPrime 35 |> should equal false

  [<Test>]
  let check101ToBePrime () =
    isPrime 101 |> should equal true

  let list = Seq.toList (Seq.take 100 (primeNumbersSeq ()))
  [<Test>]
  let check101ToBeInList () =
    list |> should contain 101

  [<Test>]
  let check102ToNotBeInList () =
    list |> should not' (contain 102)

  [<Test>]
  let checkAscendingOrder () =
    list |> should be ascending

  [<Test>]
  let checkExistenceOf9239 () =
    Seq.exists (fun x -> if x = 9239 then true else false) (primeNumbersSeq ()) |> should equal true
