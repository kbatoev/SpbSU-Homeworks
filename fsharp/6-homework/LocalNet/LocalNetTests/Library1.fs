namespace LocalNetTests

// for testing
open NUnit.Framework
open FsUnit

module LocalNet = 
  open Nets.LocalNet

  // probability is set to 100 to be sure that infection will occur
  
  let netWith1Computer = [new Computer (Linux 20, true)]
  // net is: 0*
  // symbol * means that computer is infected
  [<Test>]
  let checkNetWith1Computer () =
    countIterationsOfNetInfection netWith1Computer |> should equal 0

  let netWith2Computers = [new Computer(Linux 30, true); new Computer(Windows 100, false)]
  let connections1 = [(0, 1)]
  // net is: 0* - 1
  // symbol * means that computer is infected
  createConnections netWith2Computers connections1
  [<Test>]
  let checkNetWith2Computers () =
    countIterationsOfNetInfection netWith2Computers |> should equal 1

  let netWith3SequentComps = [new Computer(MacOS 40, true); new Computer(Windows 100, false); new Computer(Linux 100, false)]
  let connections3 = [(0, 1); (1, 0); (1, 2); (2, 1)]
  // net is: 0* - 1 - 2
  // symbol * means that computer is infected
  createConnections netWith3SequentComps connections3
  [<Test>]
  let checkNetWith3SequentComps () =
    countIterationsOfNetInfection netWith3SequentComps |> should equal 2

  let comp0 = new Computer(Linux 100, false)
  let comp1 = new Computer(Linux 40, true)
  let comp2 = new Computer(Windows 100, false)
  let netWith3ComputersWhereInfectedOneIsInMiddle = [comp0; comp1; comp2]
  comp1.AddNeighbor comp0
  comp1.AddNeighbor comp2
  // net is: 0 - 1* - 2
  // symbol * means that computer is infected
  [<Test>]
  let checkNetWith3ComputersWhereInfectedOneIsInMiddle () =
    countIterationsOfNetInfection netWith3ComputersWhereInfectedOneIsInMiddle |> should equal 1

  let netWith5Computers = [new Computer(Linux 100, false);
                           new Computer(MacOS 100, false);
                           new Computer(Windows 100, false);
                           new Computer(MacOS 100, true);
                           new Computer(Linux 100, false)]

  let connections5 = [(0, 1); (1, 0); (1, 2); (2, 1); (2, 3); (3, 2); (3, 4); (4, 3)]
  createConnections netWith5Computers connections5
  // net is: 0 - 1 - 2 - 3* - 4
  // symbol * means that computer is infected
  [<Test>]
  let checkNetWith5Computers () =
    countIterationsOfNetInfection netWith5Computers |> should equal 3

  let netWith2InfectedComps = 
    [new Computer(Linux 100, false);
     new Computer(MacOS 100, false);
     new Computer(Windows 100, false);
     new Computer(MacOS 100, false);
     new Computer(Windows 100, true);
     new Computer(Linux 100, true)]
  let connections6 = [(0, 1); (1, 0); (1, 5); (5, 1); (0, 2); (2, 0); (0, 3); (3, 0); (2, 4); (4, 2); (3, 4); (4, 3)]
  createConnections netWith2InfectedComps connections6
  // net is: 2  - 0 - 1 - 5*
  //         |    |
  //         4* - 3
  [<Test>]
  let checkNetWith2InfectedComps () =
    countIterationsOfNetInfection netWith2InfectedComps |> should equal 2
