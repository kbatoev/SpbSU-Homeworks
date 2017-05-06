// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace LambdaCalculus

open System.Collections.Generic

module BetaReduction = 
  let alphabet = ['a'..'z']
  type Variable = char

  type Term = 
    | V of Variable
    | Application of Term * Term
    | Abstraction of Variable * Term

  let abs2 : Term = Abstraction ('x', Application (V 'x', V 'x'))
  let omega = Application (abs2, abs2)

  let abs3 = Abstraction ('x', Application (Application (V 'x', V 'x'), V 'x'))
  let omega3 = Application (abs3, abs3)


  let rec collectFreeVariables term = 
    match term with
    | V x -> [x]
    | Application (t1, t2) -> collectFreeVariables t1 @ collectFreeVariables t2
    | Abstraction (x, s) -> let list = collectFreeVariables s
                            List.filter (fun y -> y <> x) list


  let rec collectAllVariables term = 
    match term with
    | V x -> [x]
    | Application (t1, t2) -> collectFreeVariables t1 @ collectFreeVariables t2
    | Abstraction (x, s) -> x :: collectAllVariables s

  let getNewVar allVars = (List.filter (fun x -> not (List.exists ((=) x) allVars)) alphabet) |> List.rev |> List.head

  let rec replaceVar oldVar newVar term =
    match term with
    | V x -> if x = oldVar then V newVar else V x
    | Application (t1, t2) -> Application (replaceVar oldVar newVar t1, replaceVar oldVar newVar t2)
    | Abstraction (x, s) -> if x = oldVar
                            then Abstraction (newVar, replaceVar oldVar newVar s)
                            else Abstraction (x, replaceVar oldVar newVar s)

  let rec substitute termS varX termT =
    match termS with 
    | V x -> if x = varX then termT else V x
    | Application (s1, s2) -> Application (substitute s1 varX termT, substitute s2 varX termT)
    | Abstraction (x, s) -> if x = varX 
                            then Abstraction (x, s)
                            else let freeVarsOfTermT = collectFreeVariables termT
                                 let freeVarsOfTermS = collectFreeVariables s
                                 if List.exists ((=) x) freeVarsOfTermT && List.exists ((=) varX) freeVarsOfTermS
                                 then let allVars = collectAllVariables termT @ collectAllVariables s
                                      let newVar = getNewVar allVars
                                      let newTermS = replaceVar x newVar s
                                      Abstraction (newVar, substitute newTermS varX termT)
                                 else Abstraction (x, substitute s varX termT)
  
  let rec reduce (term : Term) =
    match term with
    | V x -> V x
    | Application (t1, t2) -> match t1 with
                              | V x -> Application (t1, reduce t2)
                              | Application (s1, s2) -> 
                                                       let newt1 = reduce t1
                                                       match newt1 with
                                                       | Abstraction (var, s) -> reduce <| Application (newt1, t2)
                                                       | _                    -> Application (newt1, reduce t2)
                                                       
                              | Abstraction (var, s) -> let termAfterSubstitution = substitute s var t2
                                                        reduce termAfterSubstitution
    | Abstraction (var, s) -> Abstraction (var, reduce s)

  [<EntryPoint>]
  let main argv = 
    printfn "Combinator Omega diverges\n"
    printfn "%A" (reduce omega)
    0 // возвращение целочисленного кода выхода
