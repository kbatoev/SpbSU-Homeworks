// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System
open System.Collections
open System.Collections.Generic

//type Node<'T> = 'T * Node<'T> * Node<'T>

[<AllowNullLiteral>]
type BinaryTree<'T when 'T :> IComparable<'T> >(v : 'T, l : BinaryTree<'T>, r : BinaryTree<'T>) =
  let mutable value : Option<'T> = Some v
  let mutable left : BinaryTree<'T> = l
  let mutable right : BinaryTree<'T> = r

  (*
  let rec helper (tree : BinaryTree<'T>) = 
      printf "%A " <| tree.GetValue()
      match tree.GetLeft () with
      | None -> ()
      | Some l -> helper l
      match tree.GetRight () with
      | None -> ()
      | Some r -> helper r
   *)

   (*

  interface IEnumerator<'T> with
    member this.Current = value :> obj
    member this.MoveNext () = false
    member this.Reset () = ()
    member this.Dispose () = ()
    member this.Current = v 
  
  
  *)
  member private this.getMostRightValue() = 
    match (left, right) with
    | (null, null) -> let result = value
                      value <- None
                      result
    | (_, null)    -> let result = value
                      value <- left.GetValue()
                      right <- left.GetRight()
                      left <- left.GetLeft()
                      result
    | (_,_)        -> right.getMostRightValue()                    

  member this.GetValue () = value
  member this.GetLeft () = left
  member this.GetRight () = right

  member this.Print () = 
    match value with
    | None -> printfn "Tree is empty"
    | Some v -> printf "%A " <| v
                printf "("
                if left = null
                then printf "null"
                else left.Print()
                printf ")"
                printf "("
                if right = null
                then printf "null"
                else right.Print()
                printf ")"
  member this.Remove elem =
    match value with
    | None -> false
    | Some v -> match v.CompareTo(elem) with
                | 0 -> match (left, right) with 
                       | (null, null) -> value <- None
                       | (null, _)    -> value <- right.GetValue()
                                         left <- right.GetLeft()
                                         right <- right.GetRight()
                       | (_, null)    -> value <- left.GetValue()
                                         right <- left.GetRight()
                                         left <- left.GetLeft()
                       | _            -> value <- left.getMostRightValue() 
                       true
                | 1 -> if left = null
                       then false
                       else let result = left.Remove elem
                            match left.GetValue() with
                            | None -> left <- null
                            | _    -> ()
                            result
                | -1 -> if right = null 
                        then false
                        else let result = right.Remove elem
                             match right.GetValue() with
                             | None -> right <- null
                             | _    -> ()
                             result
                | _ -> false
                

   
  //                          then 
    
  //override this.GetEnumerator () = null

  
  //let leftTree : BinaryTree<'T> = null
  //let mutable elementsList : list<'a> = []
  //let count = List.length elementsList




[<EntryPoint>]
let main argv = 

  let tree = BinaryTree<int> ((1), BinaryTree<int> (2, null, null), BinaryTree<int> (100, null, null))
  tree.Print()
  printfn "\n100 was removed: %A" <| tree.Remove 100
  tree.Print()
  

  
  0 // возвращение целочисленного кода выхода
