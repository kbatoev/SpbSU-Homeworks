// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System
open System.Collections
open System.Collections.Generic

//type Node<'T> = 'T * Node<'T> * Node<'T>

type BinaryTree<'T when 'T :> IComparable<'T> >(v : 'T, ?l : BinaryTree<'T>, ?r : BinaryTree<'T>) =
  let mutable value : Option<'T> = Some v
  let mutable left : Option<BinaryTree<'T>> = l
  let mutable right : Option<BinaryTree<'T>> = r

  let rec helper (tree : BinaryTree<'T>) = 
      printf "%A " <| tree.GetValue()
      match tree.GetLeft () with
      | None -> ()
      | Some l -> helper l
      match tree.GetRight () with
      | None -> ()
      | Some r -> helper r

  interface IEnumerator<'T> with
    member this.Current = value :> obj
    member this.MoveNext () = false
    member this.Reset () = ()
    member this.Dispose () = ()
    member this.Current = v 
  
  member this.GetValue () = value
  member this.GetLeft () = left
  member this.GetRight () = right

  member this.Print () = helper this
  member this.Remove elem = 
    match value with
    | None -> ()
    | (Some x) -> match x.CompareTo(elem) with
                  | 0 -> match (left, right) with
                         | (None, None) -> value <- None
                         | (Some l, None) -> value <- l.GetValue ()
                                             right <- l.GetRight ()
                                             left <- l.GetLeft ()
  //                          then 
    
  //override this.GetEnumerator () = null

  
  //let leftTree : BinaryTree<'T> = null
  //let mutable elementsList : list<'a> = []
  //let count = List.length elementsList




[<EntryPoint>]
let main argv = 

  let tree = new BinaryTree<int> ((1), 
    new BinaryTree<int> (2), new BinaryTree<int> (100))
  tree.Print ()

  
  0 // возвращение целочисленного кода выхода
