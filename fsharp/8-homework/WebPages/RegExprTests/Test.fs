namespace RegExprTests

open NUnit.Framework
open FsUnit
open WebPages.ExploreReferencesFromGivenURL

module RegexTests = 

  let str1 = "<a href=\"http://google.com\">"
  [<Test>]
  let `` <a href="http://google.com"> - ok`` () =
    regex.IsMatch str1 |> should equal true

  let str2 = "<a href=\"google.com\">"
  [<Test>]
  let `` <a href="google.com"> - Bad`` () =
    regex.IsMatch str2 |> should equal false


  let str3 = "<a href=\"http:/google.com\">"
  [<Test>]
  let `` <a href="http:/google.com"> - Bad`` () =
    regex.IsMatch str3 |> should equal false


  let siteBeginningWithDigit = "<a href=\"http://42site.com\">"
  [<Test>]
  let ``site can begin with digit`` () =
    regex.IsMatch siteBeginningWithDigit |> should equal true


  let siteContainingHyphen = "<a href=\"http://some-site.com/somePage\">"
  [<Test>]
  let ``site can contain '-' inside`` () =
    regex.IsMatch siteContainingHyphen |> should equal true

  let siteContainingHyphenInTheBeginning = "<a href=\"http://-site2.com/\">"
  [<Test>]
  let ``site can't begin with '-'`` () =
    regex.IsMatch siteContainingHyphenInTheBeginning |> should equal false

  let tagContainsMoreThan1Attribute = "<a href=\"http://abc.domain/somePage\" attr1=\"yellow\" attr2=\"square\">"
  [<Test>]
  let `` Tag <a> can contain more than 1 attribute`` () =
    regex.IsMatch tagContainsMoreThan1Attribute |> should equal true
 

 
