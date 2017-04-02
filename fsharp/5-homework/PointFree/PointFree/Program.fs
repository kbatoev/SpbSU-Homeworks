// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Functions

module PointFreeFunctions = 

    // let func x l = List.map (fun y -> y * x) l
    // let func x = List.map (fun y -> y * x)
    // let func x = List.map (fun y -> ((*) x) y)
    // let func x = List.map ((*) x)
    // let func x = ((*) >> List.map) x
    let func = (*) >> List.map 

    [<EntryPoint>]
    let main argv = 
        let list = [1; 4; 5; 6;]
        printfn "List before: %A\n" list
        printfn "List after multiplying by 4: %A\n" <| func 4 list
        0 // возвращение целочисленного кода выхода
