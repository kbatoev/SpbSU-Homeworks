// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace ADT

exception EmptyStackException of string

module StackCollection =

  // stack is an abstract data type that stores elements
  // elements removing order is LIFO (last in - first out)
  type Stack<'T>() =
    let mutable list : list<'T> = []
    
    // insert element in the head of stack
    member this.Push x = list <- (x :: list)
    
    // check if stack has no elements
    member this.IsEmpty () = List.isEmpty list
    // remove element from head of stack and return it
    member this.Pop () = match list with
                         | [] -> raise (EmptyStackException ("stack is empty"))
                         | x :: xs -> list <- xs
                                      x
    // return element from head of stack
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
