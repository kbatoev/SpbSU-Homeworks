// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Nets

open Microsoft.FSharp.Collections

module LocalNet =

    type OS = Linux of int | Windows of int | MacOS of int
    with
      member x.InfectionProbability = 
        match x with
        | Linux probability -> probability 
        | Windows probability -> probability
        | MacOS probability -> probability
      member x.GetNameOfOs () = 
        match x with
        | Linux _ -> "Linux"
        | Windows _ -> "Windows"
        | MacOS _ -> "MacOS"

    type Computer(os:OS, isInfected :bool) = 
        static let mutable amountOfComputers : int = 0
        let number = amountOfComputers <- amountOfComputers + 1
                     amountOfComputers
        static let rand = new System.Random()
        let mutable infected = isInfected
        let mutable neighbors = []
        member x.Number = number
        member x.Neighbors = neighbors
        member x.AddNeighbor comp = neighbors <- (comp :: neighbors)
        member x.Infected = infected
        member x.InfectMe() = infected <- (infected || (rand.Next() % 100 < os.InfectionProbability))
        member x.PrintInfo() = printfn "No%d %A Infected:%A" <| number <| os.GetNameOfOs() <| infected 
        static member GetAmount = amountOfComputers

    let countIterationsOfNetInfection computers =
      printfn "Initial state"
      List.iter (fun (comp :Computer) -> comp.PrintInfo()) computers
      printfn ""
      let rec helper number = 
        let infectedComputers = List.filter (fun (comp:Computer) -> comp.Infected) computers
        if List.length infectedComputers = List.length computers
        then printfn "All computers are infected"
             number - 1
        else List.iter (fun (comp :Computer) -> List.iter (fun (comp2 :Computer) -> comp2.InfectMe()) comp.Neighbors) infectedComputers
             printfn "Iteration %d" <| number
             List.iter (fun (comp :Computer) -> comp.PrintInfo()) computers
             printfn ""
             helper <| number + 1
      helper 1
    
    let createConnections (computers : Computer list) connections = 
          List.iter (fun (f,s) -> computers.[f].AddNeighbor(computers.[s])) connections

    let computers = [new Computer(Linux 20, false);
                     new Computer(Windows 50, false);
                     new Computer(Windows 50, true);
                     new Computer(MacOS 40, false);
                     new Computer(Linux 20, true)]

    let connections = [(0, 1); (0, 2); (1, 0); (2, 0); (3, 4); (4, 3)]

    // net is:  0 - 1   3 - 4
    //          |
    //          2

    [<EntryPoint>]
    let main argv =
        createConnections computers connections
        countIterationsOfNetInfection computers |> ignore

        0 // возвращение целочисленного кода выхода
