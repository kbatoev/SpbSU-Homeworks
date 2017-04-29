// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open Microsoft.FSharp.Collections

module Program =

    type OS = Linux | Windows | MacOS
    with member x.InfectionProbability = match x with Linux -> 20 | Windows -> 50 | MacOS -> 40
         static member GetOS (osType :int) = match osType with 1 -> Linux | 2 -> Windows | _ -> MacOS 

    type Computer(os:OS, isInfected :bool) = 
        static let mutable amountOfComputers : int = 0
        let number = amountOfComputers <- amountOfComputers + 1
                     amountOfComputers
        let rand = new System.Random()
        let mutable infected = isInfected
        let mutable neighbors = []
        member x.Number = number
        member x.Neighbors = neighbors
        member x.AddNeighbor comp = neighbors <- (comp :: neighbors)
        member x.Infected = infected
        member x.InfectMe() = infected <- (infected || (rand.Next() % 100 <  os.InfectionProbability))
        member x.PrintInfo() = printfn "No%d %A Infected:%A" <| number <| os <| infected 
        static member GetAmount = amountOfComputers

    let infectNet computers =
      printfn "Initial state"
      List.iter (fun (comp :Computer) -> comp.PrintInfo()) computers
      printfn ""
      let rec helper number = 
        let infectedComputers = List.filter (fun (comp:Computer) -> comp.Infected) computers
        if List.length infectedComputers = List.length computers
        then printfn "All computers are infected"
        else List.iter (fun (comp :Computer) -> List.iter (fun (comp2 :Computer) -> comp2.InfectMe()) comp.Neighbors) infectedComputers
             printfn "Iteration %d" <| number
             List.iter (fun (comp :Computer) -> comp.PrintInfo()) computers
             printfn ""
             helper <| number + 1
      helper 1
    
    let CreateConnections (computers : Computer list) connections = 
          List.iter (fun (f,s) -> computers.[f].AddNeighbor(computers.[s])) connections

    let computers = [new Computer(Linux, false);
                     new Computer(Windows, false);
                     new Computer(Windows, true);
                     new Computer(MacOS, false);
                     new Computer(Linux, true)]

    let connections = [(0, 1); (0, 2); (1, 0); (2, 0); (3, 4); (4, 3)]

    [<EntryPoint>]
    let main argv =
    
        CreateConnections computers connections
        infectNet computers

        0 // возвращение целочисленного кода выхода
