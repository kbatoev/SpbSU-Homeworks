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

  member this.GetValue() = v
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
  let mutable size : int = 0

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

  member this.IsEmpty() = root = null
  member this.Print() = 
    if root = null
    then printfn "Tree is empty"
    else root.Print()
         printf "\n"

  new() =
    BinaryTree(null)

   (*

  interface IEnumerator<'T> with
    member this.Current = value :> obj
    member this.MoveNext () = false
    member this.Reset () = ()
    member this.Dispose () = ()
    member this.Current = v 
  
  
  *)


[<EntryPoint>]
let main argv = 

  let tree2 = BinaryTree<int>()
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

  let tree1 = BinaryTree<int> (Node<int> (4, null, null))
  tree1.Add 2
  tree1.Add 100
  tree1.Print()
  tree1.Remove 100
  tree1.Print()
  tree1.Add -7
  tree1.Add 3
  tree1.Print()

  
  0 // возвращение целочисленного кода выхода
