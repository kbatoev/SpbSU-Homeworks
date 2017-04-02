namespace PointFreeTest

open Functions.PointFreeFunctions
open NUnit.Framework
open FsUnit


module Tests =

  [<Test>]
  let checkEmptyList () =
    func 3 [] |> should equal []

  [<Test>]
  let checkListWithOneElement () =
    func 5 [1] |> should equal [5]

  [<Test>]
  let checkBigList () =
    func 2 [11; 100; 34; 1; 77; 2000] |> should equal [22; 200; 68; 2; 154; 4000]


  [<Test>]
  let checkMultiplyingByZero () =
    func 0 [11; 100; 34; 1; 77; 2000] |> should equal [0; 0; 0; 0; 0; 0]