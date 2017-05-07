// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open System.Net
open Microsoft.FSharp.Control.WebExtensions
open System.Text.RegularExpressions

let fetchAsyncThatDownladsWebPage(url:string) =
    async {
        try
            let uri = new System.Uri(url)
            let webClient = new WebClient()
            return! webClient.AsyncDownloadString(uri)
        with
            | ex -> printfn "%s" (ex.Message);
                    return ex.Message
    }

let fetchAsyncThatDownladsWebPageAndPrintsInfo(url:string) =
    async {
        try
            let uri = new System.Uri(url)
            let webClient = new WebClient()
            let! html = webClient.AsyncDownloadString(uri)
            printfn "%A" <| url + " -- " + string html.Length
        with
            | ex -> printfn "%s" (ex.Message);
    }


// this is pattern that finds references of type: <a href=http://someSite.someDomain
// anySymbolBeforeFirstQuote " andThenQuote "
// anySymbolBeforeFirstClosingBracket > andThenClosingBracket >
let regExprForReference = @"<a\shref=\x22https?://\w+\.[a-zA-Z][^\x22]*\x22[^>]*>"
let regex = new Regex(regExprForReference)

let getReferencesFromPage url =
  printfn "Page is %A" <| url
  let contentOfUrl = fetchAsyncThatDownladsWebPage url |> Async.RunSynchronously

  let referencesTagCollection = regex.Matches contentOfUrl
  let siteRegExpr = @"https?://\w+\.\w[^\x22]*"
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
