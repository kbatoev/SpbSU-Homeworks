namespace PrimeNumbers

module Sequence =

  let isPrime n =
    let rec check i = 
      if i > n / 2 
      then true 
      elif n % i = 0
      then false
      else check (i + 1)
    if n < 2 then false else check 2

  let primeNumbersSeq () = Seq.filter isPrime (Seq.initInfinite (fun x -> x))

  printf "First 100 prime numbers: \n"
  for x in (Seq.take 100 (primeNumbersSeq ()))
    do printf "%d " x

