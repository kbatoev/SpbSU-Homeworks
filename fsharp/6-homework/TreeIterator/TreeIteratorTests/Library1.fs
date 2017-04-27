namespace TreeIteratorTests

open NUnit.Framework
open FsUnit
open Tree

open System
open System.Collections
open System.Collections.Generic

module Tests = 

  let emptyTree = new BinaryTree<char>()
  [<Test>]
  let isEmptyTree () =
    emptyTree.IsEmpty() |> should equal true 

  let treeWithOneElement = new BinaryTree<int>()
  treeWithOneElement.Add 100
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
  tree2.Remove 4
  [<Test>]
  let checkRootRemoving () =
    tree2.GetRoot() |> should equal null 
    
  let tree3 = new BinaryTree<int>()
  tree3.Add 1
  tree3.Add 4
  tree3.Remove 4
  [<Test>]
  let checkRemovingElementInRightSubtree() =
    tree3.ToList() |> should equal [1]
  
  let tree4 = new BinaryTree<int>()
  tree4.Add 4
  tree4.Add -1
  tree4.Add -90
  tree4.Remove -90
  [<Test>]
  let checkRemovingElementInLeftSubtree() =
    tree4.ToList() |> should equal [4; -1]


  let tree5 = new BinaryTree<double>()
  tree5.Add 5.0
  tree5.Add 4.0
  tree5.Add 3.0
  tree5.Remove 4.0
  [<Test>]
  let removeFromMiddle() =
    tree5.ToList() |> should equal [5.0; 3.0]
  [<Test>]
  let existenceOf3 () =
    tree5.Exists 3.0 |> should equal true

  
  let tree6 = new BinaryTree<int>()
  tree6.Add 5
  tree6.Add 8
  tree6.Add 3
  tree6.Remove 5
  [<Test>]
  let removingRoot() =
    tree6.ToList() |> should equal [3; 8]

  let bigTree = new BinaryTree<int>()
  bigTree.Add 50
  bigTree.Add 100
  bigTree.Add 25
  bigTree.Add 24
  bigTree.Add 26
  bigTree.Add 27
  bigTree.Add 28
  bigTree.Add 45
  bigTree.Add 30
  bigTree.Add 29
  bigTree.Add 31
  bigTree.Print()

  bigTree.Remove 50
  [<Test>]
  let checkTransitionRightMostValue () = 
    bigTree.ToList() |> should equal [45; 25; 24; 26; 27; 28; 30; 29; 31; 100]

  let mutable sum = 0
  for node in bigTree do
    sum <- sum + node
  [<Test>]
  let checkSum () =
    sum |> should equal 365
  