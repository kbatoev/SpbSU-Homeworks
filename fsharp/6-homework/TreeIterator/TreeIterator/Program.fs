// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System
open System.Collections
open System.Collections.Generic


[<AllowNullLiteral>]
type Node<'T when 'T :> IComparable<'T> >(v : 'T, l : Node<'T>, r : Node<'T>) =
  let mutable value : 'T = v
  let mutable left : Node<'T> = l
  let mutable right : Node<'T> = r

  member this.GetValue() = value
  member this.GetLeft() = left
  member this.GetRight() = right

  member this.Print() =
    printf "%A" value
    if left = null
    then printf "()"
    else printf "("
         left.Print()
         printf ")"

    if right = null
    then printf "()"
    else printf "("
         right.Print()
         printf ")"

  member private this.GetMostRightValue() = 
    if right = null
    then value
    else right.GetMostRightValue()

  member this.Exists elem = 
    match value.CompareTo(elem) with
    | 0 -> true
    | 1 -> if left = null then false else left.Exists elem
    | -1 -> if right = null then false else right.Exists elem
    | _ -> false
  member this.Remove elem = 
    match value.CompareTo(elem) with
    | 0 -> match (left, right) with
           | (null, _) -> value <- right.GetValue()
                          left <- right.GetLeft()
                          right <- right.GetRight()
           | (_, null) -> value <- left.GetValue()
                          right <- left.GetRight()
                          left <- left.GetLeft()
           | (_, _)    -> value <- left.GetMostRightValue()
                          left.Remove value
    | 1 -> if left <> null 
           then if left.GetRight() = null && left.GetLeft() = null && left.GetValue().CompareTo(elem) = 0
                then left <- null
                else left.Remove elem
    | -1 -> if right <> null 
            then if right.GetRight() = null && right.GetLeft() = null && right.GetValue().CompareTo(elem) = 0
                 then right <- null
                 else right.Remove elem
    | _ -> ()
        
  member this.Add elem =
    match v.CompareTo(elem) with
    | -1 -> if right = null
            then right <- Node<'T>(elem, null, null)
            else right.Add elem
    | 1 -> if left = null
           then left <- Node<'T>(elem, null, null)
           else left.Add elem
    | _ -> ()


[<AllowNullLiteral>]
type BinaryTree<'T when 'T :> IComparable<'T> >(newRoot : Node<'T>) =
  let mutable root : Node<'T> = newRoot

  member this.GetRoot() = root

  member this.Remove elem =
    match root with
    | null -> ()
    | _    -> if root.GetLeft() = null && root.GetRight() = null && root.GetValue().CompareTo(elem) = 0
              then root <- null
              else root.Remove elem

  member this.Add elem =
    if root = null
    then root <- Node<'T>(elem, null, null)
    else root.Add elem
  
  member this.Exists elem = if root = null then false else root.Exists elem
  member this.IsEmpty() = root = null
  member this.Print() = 
    if root = null
    then printfn "Tree is empty"
    else root.Print()
         printf "\n"
  member this.GetValue() =
    if root = null then None else Some <| root.GetValue()
  new() =
    new BinaryTree<'T>(null)

  interface IEnumerable with
    member this.GetEnumerator() = (new TreeIterator<'T>(this)) :> (IEnumerator)
 
  interface IEnumerable<'T> with
    member this.GetEnumerator () = (new TreeIterator<'T>(this)) :> (IEnumerator<'T>)
  
  
and TreeIterator<'T when 'T :> IComparable<'T>>(tree : BinaryTree<'T>) = 
  let mutable stack : Stack<Node<'T>> = Stack<Node<'T>> ()
  let mutable cur = tree.GetRoot()
  let mutable firstElementWasVisited = false
  interface IEnumerator<'T> with
    member this.Current = cur.GetValue()
    member this.Reset() = cur <- tree.GetRoot()
                          firstElementWasVisited <- false
    member this.Dispose() = ()
    member this.Current = (cur.GetValue()) :> obj 
    member this.MoveNext() = 
      if firstElementWasVisited
      then match cur.GetLeft(), cur.GetRight(), stack.Count with
      | (null, null, 0) -> false
      | (null, null, _) -> cur <- stack.Pop()
                           true
      | (null, _, _)    -> cur <- cur.GetRight()
                           true
      | (_, null, _)    -> cur <- cur.GetLeft()
                           true
      | (_, _, _)       -> stack.Push <| cur.GetRight()
                           cur <- cur.GetLeft()
                           true
      else firstElementWasVisited <- true
           true

[<EntryPoint>]
let main argv = 

  let tree2 = new BinaryTree<int>()
  printfn "%A" <| tree2.IsEmpty()

  tree2.Add 50
  printfn "%A" <| tree2.IsEmpty()

  tree2.Remove 50
  printfn "%A" <| tree2.IsEmpty()

  tree2.Print()
  
  tree2.Add 50
  tree2.Add 100
  tree2.Print()

  tree2.Add 25
  tree2.Add 24
  tree2.Add 26
  tree2.Add 27
  tree2.Add 28
  tree2.Add 45
  tree2.Add 30
  tree2.Add 29
  tree2.Add 31
  tree2.Print()

  tree2.Remove 50
  tree2.Print()

  tree2.Remove 45
  tree2.Print()

  printfn "%A" <| tree2.Exists 29
  printfn "%A" <| tree2.Exists 45

  let tree1 = new BinaryTree<int> (Node<int> (4, null, null))
  tree1.Add 2
  tree1.Add 100
  tree1.Print()
  tree1.Remove 100
  tree1.Print()
  tree1.Add -7
  tree1.Add 3
  tree1.Print()

  printfn "\n"
  let mutable enumer = (tree2:>(IEnumerable<int>)).GetEnumerator()
                                               

  //for node in (tree2:>(IEnumerable<int>)).GetEnumerator(). do
  //printfn "%A" <| v  

  for node in tree1 do
    printfn "%A" <| node
  
  0 // возвращение целочисленного кода выхода
