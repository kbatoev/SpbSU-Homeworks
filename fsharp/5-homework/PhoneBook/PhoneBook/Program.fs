// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace Books

open System.IO
open Microsoft.FSharp.Collections

module PhoneBook = 

  let showActions () =
    printfn "Enter 0 to show this help"
    printfn "Enter 1 to exit"
    printfn "Enter 2 to add note"
    printfn "Enter 3 to lookup telephone number by name"
    printfn "Enter 4 to lookup name by number"
    printfn "Enter 5 to show notes in phonebook"
    printfn "Enter 6 to save phonebook to file"
    printfn "Enter 7 to load phonebook from file"

  let rec dealWithPhoneBook book = 
    let choice = System.Console.ReadLine ()
    match choice with
    | "0" -> showActions ()
             dealWithPhoneBook book
    | "1" -> printfn "Bye."
    | "2" -> printf "Enter name: "
             let name = System.Console.ReadLine ()
             printf "Enter number: "
             let number = System.Console.ReadLine ()
             dealWithPhoneBook <| Map.add number name book
    | "3" -> printf "Enter name: "
             let name = System.Console.ReadLine ()
             printfn "%A" <| (Map.filter (fun k v -> if v = name then true else false) book |> Map.toList |> List.map fst)
             dealWithPhoneBook book
    | "4" -> printf "Enter number: "
             let number = System.Console.ReadLine ()
             match Map.tryFind number book with
             | Some name -> printfn "%s" name
             | _ -> printfn "There's no person who has this number"
             dealWithPhoneBook book
    | "5" -> if Map.isEmpty book 
             then printfn "PhoneBook is empty"
             else Map.iter (fun number name -> (printfn "%s has number: %s" name number)) book
             dealWithPhoneBook book
    | "6" -> printf "Enter name of file: "
             let fileName = System.Console.ReadLine () 
             use writer = new StreamWriter(File.OpenWrite(fileName))
             let nl = System.Environment.NewLine
             book |> Map.toList |> List.fold (fun acc pair -> acc + (snd pair) + " " + (fst pair) + nl) "" |> writer.Write 
             writer.Close()
             printfn "Saved."
             dealWithPhoneBook book
    | "7" -> printf "Enter name of file: "
             let fileName = System.Console.ReadLine () 
             let reader = 
               seq {
                 use reader = new StreamReader(File.OpenRead(fileName))
                 while not reader.EndOfStream do
                   let nameAndNumber = List.ofArray (reader.ReadLine().Split([|' '|]))
                   let name = List.head nameAndNumber
                   let number = List.head <| List.tail nameAndNumber
                   yield (number, name) }
             let newBook = Map.ofSeq reader
             printfn "Loaded."
             dealWithPhoneBook newBook
    | _   -> dealWithPhoneBook book

  [<EntryPoint>]
  let main argv =
    showActions ()
    dealWithPhoneBook <| Map.ofList []
    0 // возвращение целочисленного кода выхода
