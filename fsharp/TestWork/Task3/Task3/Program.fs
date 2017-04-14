// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace ADT

exception EmptyStackException of string

module StackCollection =

  type Stack<'T>() =
    let mutable list : list<'T> = []

    member this.Push x = list <- (x :: list)
    member this.IsEmpty () = List.isEmpty list
    member this.Pop () = match list with
                         | [] -> raise (EmptyStackException ("stack is empty"))
                         | x :: xs -> list <- xs
                                      x

    member this.Front () = match list with
                         | [] -> raise (EmptyStackException ("stack is empty"))
                         | x :: xs -> x

  [<EntryPoint>]
  let main argv = 
    let st = Stack<int>()
    st.Push 123
    st.Push 77
    printfn "Is empty: %A" <| st.IsEmpty () 
    printfn "Element on top: %A" <| st.Front ()
    printfn "Element on top: %A" <| st.Pop () 

    0 // возвращение целочисленного кода выхода
