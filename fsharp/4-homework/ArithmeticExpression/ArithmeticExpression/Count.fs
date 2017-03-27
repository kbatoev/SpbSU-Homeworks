namespace Expression

open NUnit.Framework
open FsUnit

module Arithmetic = 

  type ArithmeticExpression =
    | Number of int
    | Plus of ArithmeticExpression * ArithmeticExpression
    | Minus of ArithmeticExpression * ArithmeticExpression
    | Multiplication of ArithmeticExpression * ArithmeticExpression

  let rec countArithmeticExpression expression = 
    match expression with
    | Number x -> x
    | Plus (expr1, expr2) -> countArithmeticExpression expr1 + countArithmeticExpression expr2
    | Minus (expr1, expr2) -> countArithmeticExpression expr1 - countArithmeticExpression expr2
    | Multiplication (expr1, expr2) -> countArithmeticExpression expr1 * countArithmeticExpression expr2
