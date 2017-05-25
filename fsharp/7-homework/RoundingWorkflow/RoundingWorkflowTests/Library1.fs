namespace RoundingWorkflowTests

open NumbersCalculus
open NUnit.Framework
open FsUnit


module Tests = 
  let roundingPrecision0 = new NumbersRounding.RoundingNumbersBuilder(0)
  let simpleValue = roundingPrecision0 {
    return (12.0 / 1.0)
  }
  [<Test>]
  let checkSimpleValue () = 
    simpleValue |> should equal 12.0
  
  let numberWithoutFraction = roundingPrecision0 {
    let! x = 10.0 / 3.0
    return x
  }
  [<Test>]
  let check_10_0_Div_3_0 () =
    numberWithoutFraction |> should equal 3.0
  
  let roundingPrecision3 = new NumbersRounding.RoundingNumbersBuilder(3)
  let calculusWithAddition = roundingPrecision3 {
    let! a = 3.1239
    let! b = 4.7486
    return a + b
    }
  [<Test>]
  let checkCalculusWithAddition () =
    calculusWithAddition |> should equal 7.873

  let calculusWithSubtraction = roundingPrecision3 {
    let! a = 4.5673
    let! b = 4.567
    return a - b
    }
  [<Test>]
  let checkCalculusWithSubtraction () =
    calculusWithSubtraction |> should equal 0.0
  
  let roundingPrecision5 = new NumbersRounding.RoundingNumbersBuilder(5)
  let calculusWithMultiplication = roundingPrecision5 {
    let! a = 4.5629
    let! b = 652.900567
    return a * b
  }
  [<Test>]
  let checkCalculusWithMultiplication () =
    calculusWithMultiplication |> should equal 2979.12001

  let bigExprPrecision0 = roundingPrecision0 {
    let! a = 0.5
    let! b = 0.5
    let! c = 0.5
    let! d = 0.5
    return a + b + c + d
  }
  [<Test>]
  let checkBigExprPrecision0 () =
    bigExprPrecision0 |> should equal 0.0


  let bigExprPrecision3 = roundingPrecision3 {
    let! a = 0.5
    let! b = 0.5
    let! c = 0.5
    let! d = 0.5
    return a + b + c + d
  }
  [<Test>]
  let checkBigExprPrecision3 () = 
    bigExprPrecision3 |> should equal 2.0
   


