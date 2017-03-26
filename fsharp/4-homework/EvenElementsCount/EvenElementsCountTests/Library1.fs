namespace EvenElementsCountTests

open EvenElements.Functions
open NUnit.Framework
open FsUnit

module TestModule = 

  let list1 = [1; 3; 5; 7]
  let list2 = [2; 4; 6; 8]
  let list3 = []
  let list4 = [2]
  let list5 = [3]
  

  [<Test>]
  let checkListWithOddElements_By_Filter () = 
    countEvenElementsFilter list1 |> should equal 0
  
  [<Test>]
  let checkListWithEvenElements_By_Filter () = 
    countEvenElementsFilter list2 |> should equal 4

  [<Test>]
  let checkEmptyList_By_Filter () = 
    countEvenElementsFilter list3 |> should equal 0

  [<Test>]
  let checkListWithEvenElement_By_Filter () = 
    countEvenElementsFilter list4 |> should equal 1

  [<Test>]
  let checkListWithOddElement_By_Filter () = 
    countEvenElementsFilter list5 |> should equal 0

  // For countEvenElementsMap
  [<Test>]
  let checkListWithOddElements_By_Map () = 
    countEvenElementsMap list1 |> should equal 0
  
  [<Test>]
  let checkListWithEvenElements_By_Map () = 
    countEvenElementsMap list2 |> should equal 4

  [<Test>]
  let checkEmptyList_By_Map () = 
    countEvenElementsMap list3 |> should equal 0

  [<Test>]
  let checkListWithEvenElement_By_Map () = 
    countEvenElementsMap list4 |> should equal 1

  [<Test>]
  let checkListWithOddElement_By_Map () = 
    countEvenElementsMap list5 |> should equal 0


  // For countEvenElementsFold
  [<Test>]
  let checkListWithOddElements_By_Fold () = 
    countEvenElementsFold list1 |> should equal 0
  
  [<Test>]
  let checkListWithEvenElements_By_Fold () = 
    countEvenElementsFold list2 |> should equal 4

  [<Test>]
  let checkEmptyList_By_Fold () = 
    countEvenElementsFold list3 |> should equal 0

  [<Test>]
  let checkListWithEvenElement_By_Fold () = 
    countEvenElementsFold list4 |> should equal 1

  [<Test>]
  let checkListWithOddElement_By_Fold () = 
    countEvenElementsFold list5 |> should equal 0