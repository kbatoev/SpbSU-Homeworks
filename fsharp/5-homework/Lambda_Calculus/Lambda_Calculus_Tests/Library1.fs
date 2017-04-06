namespace LambdaCalculusTests


open NUnit.Framework
open FsUnit
open LambdaCalculus.BetaReduction

module BetaReductionTests =

  // (\x.x) y -> y
  let simpleTerm : Term = Application (Abstraction ('x', V 'x'), V 'y')
  [<Test>]
  let checkSimpleTerm () =
    reduce simpleTerm |> should equal (V 'y')

  // (\x. x x) -> (\x. x x)
  let abstraction2 : Term = Abstraction ('x', Application (V 'x', V 'x'))
  [<Test>]
  let checkThatAbstractionIsTheSame () =
    reduce abstraction2 |> should equal abs2

  // (\x. x x) y -> y y 
  let term1 : Term = Application (Abstraction ('x', Application (V 'x', V 'x')), V 'y')
  [<Test>]
  let checkTerm1 () =
    reduce term1 |> should equal (Application (V 'y', V 'y'))

  // (\x y. x y) (w y) -> (\z. w y z)
  let term2 : Term = Application (Abstraction ('x', Abstraction ('y', Application (V 'x', V 'y'))), Application (V 'w', V 'y'))
  [<Test>]
  let checkTerm2 () =
    reduce term2 |> should equal (Abstraction ('z', Application (Application (V 'w', V 'y'), V 'z')))


  let abstraction3 = Abstraction ('x', Application (Application (V 'x', V 'x'), V 'x'))
  let termThatCanBeCalculatedForever = Application (Abstraction ('x', V 'y'), Application (abstraction3, abstraction3))
  // (\x.y) ((\x. x x x) (\x. x x x)) -> y
  [<Test>]
  let checkTermThatCanBeCalculatedForever () =
    reduce termThatCanBeCalculatedForever |> should equal (V 'y')

  // (\x. (\y. y x) w) -> (\x. w x)
  let termThatHasApplicationInsideAbstraction = Abstraction ('x', Application (Abstraction ('y', Application (V 'y', V 'x')), V 'w'))
  [<Test>]
  let checkTermThatHasApplicationInsideAbstraction () =
    reduce termThatHasApplicationInsideAbstraction |> should equal (Abstraction ('x', Application (V 'w', V 'x')))

 
  // (\x. (\y. y x) x) -> (\x. x x)
  let termThatHasApplicationInsideAbstractionAndSameVariables = Abstraction ('x', Application (Abstraction ('y', Application (V 'y', V 'x')), V 'x'))
  [<Test>]
  let checkTermThatHasApplicationInsideAbstractionAndSameVariables () =
    reduce termThatHasApplicationInsideAbstractionAndSameVariables |> should equal (Abstraction ('x', Application (V 'x', V 'x')))

  // (((x y) z) w) ((\x.x) v) -> x y z w v
  let termThatHasApplication_FarRightFromBeginning = Application (Application (Application (Application (V 'x', V 'y'), V 'z'), V 'w'), Application (Abstraction ('x', V 'x'), V 'v'))
  [<Test>]
  let checkTermThatHasApplication_FarRightFromBeginning () =
    reduce termThatHasApplication_FarRightFromBeginning |> should equal (Application (Application (Application (Application (V 'x', V 'y'), V 'z'), V 'w'), V 'v'))
