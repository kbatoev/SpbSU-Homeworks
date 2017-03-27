// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Brackets

open Microsoft.FSharp.Collections

module CorrectExpressions = 

  let checkCorrectnessOfBracketsInExpression stringExpression = 
    let listOfString = List.ofSeq stringExpression
    let isOpenBracket symbol = if symbol = '(' || symbol = '[' || symbol = '{' then true else false
    let isCloseBracket symbol = if symbol = ')' || symbol = ']' || symbol = '}' then true else false
    let getBracketsType bracket =
      match bracket with
      | '(' -> 1
      | ')' -> 1
      | '[' -> 2
      | ']' -> 2
      | '{' -> 3
      | '}' -> 3
      | _   -> 0

    let rec helper list (acc : char list) =
      match list with
      | [] -> if List.length acc = 0 then true else false
      | (x :: xs) when isOpenBracket x -> helper xs (x :: acc)
      | (x :: xs) when isCloseBracket x && List.length acc = 0 -> false 
      | (x :: xs) when isCloseBracket x && getBracketsType x = getBracketsType (List.head acc) -> helper xs (List.tail acc)
      | (x :: xs) when isCloseBracket x && getBracketsType x <> getBracketsType (List.head acc) -> false
      | (x :: xs) -> helper xs acc
    helper listOfString []

  [<EntryPoint>]
  let main argv = 
    let testString = "()[{}]"
    printfn "%A is correct bracket sequence? %A" testString (checkCorrectnessOfBracketsInExpression testString)

    let testString1 = "(()[{}]"
    printfn "%A is correct bracket sequence? %A" testString1 (checkCorrectnessOfBracketsInExpression testString1)

    0 // возвращение целочисленного кода выхода
