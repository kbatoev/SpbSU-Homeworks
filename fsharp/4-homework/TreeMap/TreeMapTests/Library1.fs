namespace TreeTests

open BinaryTree.TreeMap
open NUnit.Framework
open FsUnit
open FsCheck

module MapOperation =

  let checkTree (xs : Tree<int>) = (mapTree (fun x -> 3 * (x + 2)) xs) = (mapTree (fun x -> x + 6) (mapTree (fun x -> x * 3) xs))
  [<Test>]
  let check_3XPlus6Function_By_FsCheck () =
    Check.Quick checkTree

  let tree = Tree (1, (Tree (2, Tip 123, Tip 456)), Tip 900)
  let treeSquare = mapTree (fun x -> x * x) tree
  [<Test>]
  let checksTreeAfterSquaringEachElement () = 
    treeSquare |> should equal (Tree (1, (Tree (4, (Tip 15129), (Tip 207936))), (Tip 810000)))