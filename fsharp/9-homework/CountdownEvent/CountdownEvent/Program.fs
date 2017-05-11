// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace CountdownEvent

open System.Threading

/// <summary>
/// CountdownEvent Class. Its purpose is holding calling threads in blocked state until its count becomes 0
/// So after count has become 0 CountdownEvent doesn't hold any new calling threads.
/// </summary>
type MyCountdownEvent(count) = 
  let mutable currentCount = if count > 0 then count else 0
  let manualReset = new ManualResetEvent(false)
  
  member this.Count = currentCount

  /// <summary>
  /// Method Wait() tries to block calling thread processing.
  /// if currentCount <= 0 then it does nothing and returns false
  /// otherwise it delegates requset to ManualResetEvent
  /// </summary>
  member this.Wait() = if currentCount > 0 
                       then manualReset.WaitOne()
                       else false
  
  /// <summary>
  /// Method Signal() tries to decrement count
  /// returning value says if currentCount reached 0 and blocked threads became able to execute
  /// </summary>
  member this.Signal() = if currentCount > 0
                         then currentCount <- Interlocked.Decrement(&currentCount)
                              //currentCount <- currentCount - 1
                              if currentCount = 0 
                              then let rec helper () =
                                     if manualReset.Set() then true else helper ()
                                   helper ()
                              else false
                         else true 


module MainModule =

  [<EntryPoint>]
  let main argv = 
    
      let cde = new MyCountdownEvent(3)

      let someWork () =
        printfn "Hello from Thread %A" <| Thread.CurrentThread.ManagedThreadId
        cde.Wait() |> ignore
        printfn "Exiting Thread %A" <| Thread.CurrentThread.ManagedThreadId


      let thread1 = new Thread(new ThreadStart(someWork))
      let thread2 = new Thread(new ThreadStart(someWork))
      printfn "Thread1 = %A" <| thread1.ManagedThreadId
      printfn "Thread2 = %A" <| thread2.ManagedThreadId
      thread1.Start()
      thread2.Start()

      cde.Signal() |> ignore
      cde.Signal() |> ignore



      printfn "\nWhen you click Enter CoundownEvent.Signal() will be called \nand its count will become zero, \nso Threads will continue executing"
      //System.Console.ReadLine() |> ignore
      cde.Signal() |> ignore

      cde.Wait() |> ignore
      
      let signallingFunction list =
        let cde5 = new MyCountdownEvent(100000000)
        Monitor.Enter cde5 
        try 
          let createSignallingAsync () = async {
            return cde5.Signal()
          }
          list |> List.map (fun _ -> createSignallingAsync()) |> Async.Parallel |> Async.RunSynchronously |> ignore
          cde5.Count
        finally 
          Monitor.Exit cde5
      
      for i = 1 to 1000 do
        printfn "%A" <| signallingFunction [1;2;3;4;5;5] 
      0 // возвращение целочисленного кода выхода
