// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System
open System.Collections
open System.Collections.Generic


[<AllowNullLiteral>]
type BinaryTree<'T when 'T :> IComparable<'T> >(v : 'T, l : BinaryTree<'T>, r : BinaryTree<'T>) =
  let mutable value : Option<'T> = Some v
  let mutable left : BinaryTree<'T> = l
  let mutable right : BinaryTree<'T> = r

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
               
                if left = null
                then printf "()"
                else  printf "("
                      left.Print()
                      printf ")"
                if right = null
                then printf "()"
                else printf "("
                     right.Print()
                     printf ")"
  member this.Add elem =
    match value with
    | None -> value <- Some elem
    | Some v -> match v.CompareTo(elem) with
                | 0 -> ()
                | 1 -> if left = null 
                       then left <- BinaryTree<'T>(elem, null, null)
                       else left.Add elem
                | -1 -> if right = null
                        then right <- BinaryTree<'T>(elem, null, null)
                        else right.Add elem
                | _ -> ()
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
                
  new(v: 'T) =
    BinaryTree(v, null, null)


[<EntryPoint>]
let main argv = 

  let tree = BinaryTree<int> (4, BinaryTree<int> (2), BinaryTree<int> (100))
  tree.Print()
  printfn "\n100 was removed: %A" <| tree.Remove 100
  tree.Print()
  printf "\n"
  
  tree.Add(-7)
  tree.Print()
  printf "\n"

  tree.Add(100)
  tree.Print()
  printf "\n"

  tree.Add(3)
  tree.Print()
  printf "\n"

  let tree1 = BinaryTree<int> (50)
  tree1.Add 100
  tree1.Add 25
  tree1.Add 24
  tree1.Add 26
  tree1.Add 27
  tree1.Add 28
  tree1.Add 45
  tree1.Add 30
  tree1.Add 29
  tree1.Add 31
  tree1.Print()
  printf "\n"

  tree1.Remove 50
  tree1.Print()
  printf "\n"


  
  0 // возвращение целочисленного кода выхода
