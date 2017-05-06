namespace PointFreeTest

open Functions.PointFreeFunctions
open NUnit.Framework
open FsUnit
open FsCheck


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
  
  let multiplyOnZero (xs : int list) = func 0 xs = List.init (List.length xs) (fun x -> 0) 
  [<Test>]
  let checkMultiplyingOnZero () =
    Check.Quick multiplyOnZero
