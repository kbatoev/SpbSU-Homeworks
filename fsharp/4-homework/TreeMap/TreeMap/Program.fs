// Дополнительные сведения о F# см. на http://fsharp.org
// Дополнительную справку см. в проекте "Учебник по F#".

namespace BinaryTree


module TreeMap =
  type Tree<'a> =
      | Tip of 'a
      | Tree of 'a * Tree<'a> * Tree<'a>

  let rec mapTree f tree = 
    match tree with 
    | Tree (x, l, r) -> Tree (f x, mapTree f l, mapTree f r)
    | Tip x -> f x |> Tip
 