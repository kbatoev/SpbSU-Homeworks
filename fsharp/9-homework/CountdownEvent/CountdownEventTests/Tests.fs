namespace CountdownEventTests

open CountdownEvent

open NUnit.Framework
open FsUnit
open FsCheck

open System.Net

module Tests =
  
  let cde1 = new CountdownEvent(0)

  [<Test>]
  let ``Checking whether cde1 with 0 count has done its job`` () =
    cde1.Signal() |> should equal true

  [<Test>]
  let ``cde1 can't block any thread`` () =
    cde1.Wait() |> should equal false
  
  let cde2 = new CountdownEvent(2)
  [<Test>]
  let ``cde2 must continue blocking after calling its signal method `` () =
    cde2.Signal() |> should equal false

  let cde3 = new CountdownEvent(3)
  cde3.Signal() |> ignore
  cde3.Signal() |> ignore
  [<Test>]
  let ``After 3 times signalling , sde3 stops holding threads `` () =
    cde3.Signal() |> should equal true

  let cde4 = new CountdownEvent(4)
  let call4TimesSignalParallel () =
    let createAsync () = async {
      return cde4.Signal()
    } 
    let list = (List.init 4 id) |> List.map (fun _ -> 
              createAsync()) |> Async.Parallel |> Async.RunSynchronously |> Array.toList
    cde4.Count

  [<Test>]
  let `` count of cde4 should become 0`` () =
    call4TimesSignalParallel() |> should equal 0

  
  let signallingFunction list =
    let cde5 = new CountdownEvent(100000000)
    let createSignallingAsync () = async {
        return cde5.Signal()
    }
    list |> List.map (fun _ -> createSignallingAsync()) |> Async.Parallel |> Async.RunSynchronously |> ignore
    cde5.Count
  
  let checkCounters list = signallingFunction list = if 100000000 - List.length list < 0 then 0 else 100000000 - List.length list
  [<Test>]
  let ``Check Race Conditions `` () =
    Check.Quick checkCounters
    

  
  
