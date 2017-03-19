// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

open NUnit.Framework
open FsUnit
open FsCheck

type Tree<'a> =
    | Tip of 'a
    | Tree of 'a * Tree<'a> * Tree<'a>

let rec mapTree f tree = 
    match tree with 
    | Tree (x, l, r) -> Tree (f x, mapTree f l, mapTree f r)
    | Tip x -> f x |> Tip

let checkTree (xs : Tree<int>) = (mapTree (fun x -> ((*) 3 >> (+) 6) x) xs) = (mapTree (fun x -> x + 6) (mapTree (fun x -> x * 3) xs))
Check.Quick checkTree



let tree = Tree (1, (Tree (2, (Tip 123), (Tip 456))), (Tip 900))
let treeSquare = mapTree (fun x -> x * x) tree
treeSquare |> should equal (Tree (1, (Tree (4, (Tip 15129), (Tip 207936))), (Tip 810000)))