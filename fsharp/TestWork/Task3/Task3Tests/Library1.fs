namespace Task3Tests

open ADT
open NUnit.Framework
open FsUnit

module Tests =
  
  let stack1 = StackCollection.Stack<int>()
  [<Test>]
  let checkWhetherNewStackIsEmpty () =
    stack1.IsEmpty () |> should equal true
  
  
  [<Test>]
  let checkExceptionRaisingFromPop () =
    (fun () -> stack1.Pop () |> ignore)
     |> should throw typeof<ADT.EmptyStackException>

  let checkExceptionRaisingFromFront () =
    (fun () -> stack1.Front () |> ignore)
     |> should throw typeof<ADT.EmptyStackException>

  let stack2 = StackCollection.Stack<char>()
  stack2.Push 'a'
  [<Test>]
  let checkPush () =
    stack2.Front () |> should equal 'a'

  [<Test>]
  let checkWhetherFrontDoesNotRemoveElement () =
    stack2.IsEmpty () |> should equal false
 
  let stack3 = StackCollection.Stack<double>()
  stack3.Push 5.8
  stack3.Push 10.0
  stack3.Push 14.8
  stack3.Pop ()
  stack3.Pop ()
  [<Test>]
  let checkPop () =
    stack3.Pop () |> should equal 5.8





