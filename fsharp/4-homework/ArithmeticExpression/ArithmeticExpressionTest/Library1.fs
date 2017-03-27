namespace ArithmeticExpressionTest

open Expression.Arithmetic
open NUnit.Framework
open FsUnit


module Tests =

  let expressionNumber = Number 5
  [<Test>]
  let checkNumberExpression () =
    countArithmeticExpression expressionNumber |> should equal 5


  let expr_1_Plus_4 = Plus (Number 1, Number 4)
  [<Test>]
  let checkSumExpression () =
    countArithmeticExpression expr_1_Plus_4 |> should equal 5


  let expr_90_Minus_34 = Minus (Number 90, Number 34)
  [<Test>]
  let checkMinusExpression () =
    countArithmeticExpression expr_90_Minus_34 |> should equal 56


  let expr_23_Multiplication_71 = Multiplication (Number 23, Number 71)
  [<Test>]
  let checkMultiplicationExpression () =
    countArithmeticExpression expr_23_Multiplication_71 |> should equal 1633


  let bigExpression = Multiplication (Plus (Number 45, Number 78), Minus (Number 123, Number 90))
  [<Test>]
  let checkBigExpression () =
    countArithmeticExpression bigExpression |> should equal 4059


  let compositeExpression = Minus (bigExpression, expressionNumber)
  [<Test>]
  let checkCompositeExpression () =
    countArithmeticExpression compositeExpression |> should equal 4054