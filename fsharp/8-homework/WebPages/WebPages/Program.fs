// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".
namespace WebPages

open System.Net
open Microsoft.FSharp.Control.WebExtensions
open System.Text.RegularExpressions

module ExploreReferencesFromGivenURL =

  let fetchAsyncThatDownladsWebPageAndPrintsInfo(url:string) =
      async {
          try
              let uri = new System.Uri(url)
              let webClient = new WebClient()
              let! html = webClient.AsyncDownloadString(uri)
              printfn "%A" <| url + " -- " + string html.Length
              return html
          with
              | ex -> printfn "%s" (ex.Message)
                      return ex.Message
      }


  // this is pattern that finds references of type: <a href=http://some-Site.someDomain
  // (anySymbolsBeforeFirstQuote ") andThenQuote "
  // (anySymbolsBeforeFirstClosingBracket >) andThenClosingBracket >
  let regExprForReference = @"<a\shref=\x22https?://\w[\w-]*\.[a-zA-Z]+[^\x22]*\x22[^>]*>"
  let regex = new Regex(regExprForReference)

  let getReferencesFromPage url =
    printfn "Page is %A" <| url
    let contentOfUrl = fetchAsyncThatDownladsWebPageAndPrintsInfo url |> Async.RunSynchronously

    let referencesTagCollection = regex.Matches contentOfUrl
    let siteRegExpr = @"https?://\w[\w-]*\.[a-zA-Z]+[^\x22]*"
    let siteRegex = new Regex(siteRegExpr)

    printfn "There are %A references" <| referencesTagCollection.Count
    let rec parseTagReferences number acc =
      if number < referencesTagCollection.Count
      then let reference = (referencesTagCollection.Item number).Value
           let site = siteRegex.Match(reference).Value
           parseTagReferences (number + 1) (site :: acc)
      else acc
    parseTagReferences 0 []

  [<EntryPoint>]
  let main argv = 
      let url = "http://hwproj.me/courses/20"
      //let url = System.Console.ReadLine()

      let list = getReferencesFromPage url
      list |> List.map fetchAsyncThatDownladsWebPageAndPrintsInfo |> Async.Parallel |> Async.RunSynchronously |> ignore
      0 // возвращение целочисленного кода выхода
