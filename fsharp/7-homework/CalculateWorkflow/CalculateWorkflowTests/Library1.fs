namespace CalculateWorkflowTests

open NUnit.Framework
open FsUnit
open Workflows


module Tests =

  let calculate = new Calculator.NumberBuilder()
  
  let simpleNumber = calculate {
    let! x = "1"
    return x
    }

  [<Test>]
  let simpleTest() =
    Calculator.compareDoubles simpleNumber (Some 1.0) |> should equal true

  let sum = calculate {
    let! a = "10"
    let! b = "15.5"
    return a + b
    }
  [<Test>]
  let sumEquals25 () =
    Calculator.compareDoubles sum (Some 25.5) |> should equal true
  
  
  let sum2 = calculate {
    let! a = "10000"
    let! b = "25."
    return a + b
    }
  [<Test>]
  let pointInTheEnd () =
    sum2 |> should equal None

  
  let letterInString = calculate {
    let! x = "7.8"
    let! y = "1239"
    let! z = "96A34"
    return x + y + z
    }
  [<Test>]
  let checkLetterInString () =
    letterInString |> should equal None

  let workFlowWithIntNumber = calculate {
    let! x = 90
    let! y = "9.9"
    return x + y
    }
  [<Test>]
  let checkWorkFlowWithIntNumber () =
    Calculator.compareDoubles workFlowWithIntNumber (Some 99.9) |> should equal true

  let workFlowWithDoubleNumber = calculate {
    let! x = 50.5
    let! y = "5.0"
    return x / y
    }
  [<Test>]
  let checkWorkFlowWithDoubleNumber () =
    Calculator.compareDoubles workFlowWithDoubleNumber (Some 10.1) |> should equal true

  let workflowWithCommas = calculate {
    let! x = "0,44"
    let! y = "10,7"
    return x * y
    }
  [<Test>]
  let checkWorkflowWithCommas () =
    Calculator.compareDoubles workflowWithCommas (Some 4.708) |> should equal true


  
