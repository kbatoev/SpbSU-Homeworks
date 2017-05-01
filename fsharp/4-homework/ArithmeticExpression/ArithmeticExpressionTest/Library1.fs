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

  let compositeExpression = Division (bigExpression, expressionNumber)
  [<Test>]
  let checkCompositeExpression () =
    countArithmeticExpression compositeExpression |> should equal 811

  let exprWithDivision = Division (Number 6, Number 3)
  [<Test>]
  let checkDivision () =
    countArithmeticExpression exprWithDivision |> should equal 2

  [<Test>]
  let checkDivisionOn_1 () = 
    countArithmeticExpression (Division (Number 100, Number 1)) |> should equal 100

  [<Test>]
  let checkIntegerDivision () =
    countArithmeticExpression (Division (Number 10, Number 3)) |> should equal 3