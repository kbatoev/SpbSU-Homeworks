namespace BracketsTest

open Brackets.CorrectExpressions
open NUnit.Framework
open FsUnit

module Tests =

  let simpleString = "()[]{}"
  [<Test>]
  let checkSimpleString () =
    checkCorrectnessOfBracketsInExpression simpleString |> should equal true

  let emptyString = ""
  [<Test>]
  let checkEmptyString () =
    checkCorrectnessOfBracketsInExpression emptyString |> should equal true


  let stringWithoutBrackets = "Hello World!"
  [<Test>]
  let checkStringWithoutBrackets () =
    checkCorrectnessOfBracketsInExpression stringWithoutBrackets |> should equal true


  let stringWithOneOpenBracket = "("
  [<Test>]
  let checkStringWithOneOpenBracket () =
    checkCorrectnessOfBracketsInExpression stringWithOneOpenBracket |> should equal false


  let stringWithOneCloseBracket = ")"
  [<Test>]
  let checkStringWithOneCloseBracket () =
    checkCorrectnessOfBracketsInExpression stringWithOneCloseBracket |> should equal false


  let stringWithDifferentPairBrackets = "(]"
  [<Test>]
  let checkStringWithDifferentPairBrackets () =
    checkCorrectnessOfBracketsInExpression stringWithDifferentPairBrackets |> should equal false


  let stringWithCompositePairBrackets = "([{}])"
  [<Test>]
  let checkstringWithCompositePairBrackets () =
    checkCorrectnessOfBracketsInExpression stringWithCompositePairBrackets |> should equal true



