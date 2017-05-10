namespace TreeIteratorTests

open NUnit.Framework
open FsUnit
open Tree

open System
open System.Collections
open System.Collections.Generic

module Tests = 

  let emptyTree = new BinaryTree<char>(null)
  [<Test>]
  let isEmptyTree () =
    null |> should equal null 

  
  let treeWithOneElement = (new BinaryTree<int>()).Add(100)
  [<Test>]
  let treeWithOneElementIsNotEmpty () =
    treeWithOneElement.IsEmpty() |> should equal false
  
  
  [<Test>]
  let checkExistenceOf100 () =
    treeWithOneElement.Exists 100 |> should equal true
  
  
  [<Test>]
  let checkExistenceOf50 () =
    treeWithOneElement.Exists 50 |> should equal false
  
  let tree2 = new BinaryTree<int> (new Node<int> (4, null, null))
  let tree2AfterRemoving4 = tree2.Remove 4
  [<Test>]
  let checkRootRemoving () =
    tree2AfterRemoving4.GetRoot |> should equal null 
  
  
  let tree3 = (new BinaryTree<int>()).Add(1).Add(4).Remove(4)
  [<Test>]
  let checkRemovingElementInRightSubtree() =
    tree3.ToList() |> should equal [1]
  
  let tree4 = (new BinaryTree<int>()).Add(4).Add(-1).Add(-90).Remove(-90)
  [<Test>]
  let checkRemovingElementInLeftSubtree() =
    tree4.ToList() |> should equal [4; -1]
  
  
  let tree5 = (new BinaryTree<double>()).Add(5.0).Add(4.0).Add(3.0).Remove(4.0)
  [<Test>]
  let removeFromMiddle() =
    tree5.ToList() |> should equal [5.0; 3.0]
  
  [<Test>]
  let existenceOf3 () =
    tree5.Exists 3.0 |> should equal true
  
  
  let tree6 = (new BinaryTree<int>()).Add(5).Add(8).Add(3).Remove(5)
  [<Test>]
  let removingRoot() =
    tree6.ToList() |> should equal [3; 8]
  
  let bigTree = (new BinaryTree<int>()).Add(50).Add(100).Add(25).Add(24).Add(26).Add(27).Add(28)
                                       .Add(45).Add(30).Add(29).Add(31).Remove(50)

  [<Test>]
  let checkTransitionRightMostValue () = 
    bigTree.ToList() |> should equal [45; 25; 24; 26; 27; 28; 30; 29; 31; 100]

  let mutable sum = 0
  for node in bigTree do
    sum <- sum + node
  [<Test>]
  let checkSum () =
    sum |> should equal 365
  


