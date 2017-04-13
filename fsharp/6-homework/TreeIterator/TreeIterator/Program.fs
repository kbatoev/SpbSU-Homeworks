// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System.Collections
open System.Collections.Generic

type BinaryTree<'T>(v : 'T, ?l : BinaryTree<'T>, ?r : BinaryTree<'T>) =
  let mutable value : 'T = v
  let mutable left : Option<BinaryTree<'T>> = l
  let mutable right : Option<BinaryTree<'T>> = r

  let rec helper (tree : BinaryTree<'T>) = 
      printfn "%A" <| tree.GetValue()
      match tree.GetLeft () with
      | None -> ()
      | Some l -> helper l
      match tree.GetRight () with
      | None -> ()
      | Some r -> helper r

  interface IEnumerator<'T> with
    member this.Current = v :> obj
    member this.MoveNext () = false
    member this.Reset () = ()
    member this.Dispose () = ()
    member this.Current = v
  
  member this.GetValue () = value
  member this.GetLeft () = left
  member this.GetRight () = right

  member this.Print () = helper this
    
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
