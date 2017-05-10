// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".
namespace Tree

open System
open System.Collections
open System.Collections.Generic


[<AllowNullLiteral>]
type Node<'T when 'T :> IComparable<'T> >(v : 'T, l : Node<'T>, r : Node<'T>) =
  let mutable value : 'T = v
  let mutable left : Node<'T> = l
  let mutable right : Node<'T> = r

  member this.GetValue = value
  
  member this.GetLeft = left
  
  member this.GetRight = right

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

  // while possible going to right node and in the end returning its value
  member private this.GetMostRightValue = 
    if right = null
    then value
    else right.GetMostRightValue
  
  // recursively check whether elem is stored in some node
  member this.Exists elem = 
    match value.CompareTo(elem) with
    | 0 -> true
    | 1 -> if left = null then false else left.Exists elem
    | -1 -> if right = null then false else right.Exists elem
    | _ -> false
  
  // removing elem from some node
  // there might be 4 situations, connected with amount of node's children when elem = node.GetValue
  // 1) no children -> node becomes null
  // 2) 1 child -> node copies data from this child
  // 3) 2 children -> node copies value from rightMostNode in left subNode and deletes that node
  member this.Remove elem = 
    match value.CompareTo(elem) with
    | 0 -> match (left, right) with
           | (null, _) -> value <- right.GetValue
                          left <- right.GetLeft
                          right <- right.GetRight
           | (_, null) -> value <- left.GetValue
                          right <- left.GetRight
                          left <- left.GetLeft
           | (_, _)    -> value <- left.GetMostRightValue
                          if left.GetRight = null && left.GetLeft = null
                          then left <- null
                          else left.Remove value
    | 1 -> if left <> null 
           then if left.GetRight = null && left.GetLeft = null && left.GetValue.CompareTo(elem) = 0
                then left <- null
                else left.Remove elem
    | -1 -> if right <> null 
            then if right.GetRight = null && right.GetLeft = null && right.GetValue.CompareTo(elem) = 0
                 then right <- null
                 else right.Remove elem
    | _ -> ()
  
  // adding element saving invariant of binary search tree
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

  member this.GetRoot = root

  member this.Remove elem =
    match root with
    | null -> ()
    | _    -> if root.GetLeft = null && root.GetRight = null && root.GetValue.CompareTo(elem) = 0
              then root <- null
              else root.Remove elem
  
  // transforming values of tree to list
  member this.ToList () =
    let mutable list = []
    for value in this do
      list <- (value :: list)
    List.rev list
  
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
  
  member this.GetValue =
    if root = null then None else Some <| root.GetValue
  
  new() =
    new BinaryTree<'T>(null)

  interface IEnumerable with
    member this.GetEnumerator() = (new TreeIterator<'T>(this)) :> (IEnumerator)
 
  interface IEnumerable<'T> with
    member this.GetEnumerator () = (new TreeIterator<'T>(this)) :> (IEnumerator<'T>)
  
  
and TreeIterator<'T when 'T :> IComparable<'T>>(tree : BinaryTree<'T>) = 
  let mutable stack : Stack<Node<'T>> = Stack<Node<'T>> ()
  let mutable cur = tree.GetRoot
  let mutable firstElementWasVisited = false
  
  interface IEnumerator<'T> with
    member this.Current = cur.GetValue
    
    member this.Reset() = cur <- tree.GetRoot
                          firstElementWasVisited <- false
    
    member this.Dispose() = ()
    
    member this.Current = (cur.GetValue) :> obj 
    
    member this.MoveNext() = 
      if firstElementWasVisited
      then match cur.GetLeft, cur.GetRight, stack.Count with
        | (null, null, 0) -> false
        | (null, null, _) -> cur <- stack.Pop()
                             true
        | (null, _, _)    -> cur <- cur.GetRight
                             true
        | (_, null, _)    -> cur <- cur.GetLeft
                             true
        | (_, _, _)       -> stack.Push <| cur.GetRight
                             cur <- cur.GetLeft
                             true
      else firstElementWasVisited <- true
           true

module MainModule = 

  [<EntryPoint>]
  let main argv = 

    let tree1 = new BinaryTree<int> (Node<int> (4, null, null))
    tree1.Add 2
    tree1.Add 100
    tree1.Print()
    tree1.Remove 100
    tree1.Print()
    tree1.Add -7
    tree1.Add 3
    tree1.Print()
  
    0 // возвращение целочисленного кода выхода
