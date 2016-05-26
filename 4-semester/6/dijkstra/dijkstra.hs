{-# LANGUAGE FlexibleInstances #-}

import Control.Monad
import Data.List
import Control.Monad.Writer


data Edge = Edge {from :: Int, to :: Int, weight :: Int} deriving (Show)
data Vertex = Vertex {number :: Int, distance :: Int} deriving (Show)

instance Eq Vertex where
	v1 == v2 = (number v1 == number v2)

data Graph = Graph {verteces :: [Vertex], edges :: [Edge]} deriving (Show)

type PathToVertex = Writer [Int] Vertex

getNumber :: PathToVertex -> Int
getNumber = number . fst .runWriter

getDistance :: PathToVertex -> Int
getDistance = distance . fst . runWriter

getVertex :: PathToVertex -> Vertex
getVertex = fst . runWriter 

v1 = Vertex 1 100
v2 = Vertex 2 50

instance Eq PathToVertex where
	vp1 == vp2 = fst (runWriter vp1) == fst (runWriter vp2)


instance Ord PathToVertex where
	compare v1 v2
				| (distance $ getVertex v1) > (distance $ getVertex v2) = GT
				| getVertex v1 == getVertex v2        					= EQ
				| otherwise                     						= LT 


addEdge :: PathToVertex -> Int -> Int -> PathToVertex
addEdge vp l newDistance = do
				let (v, edges) = runWriter vp
				let n = getNumber vp
				tell (l:edges) 
				return (Vertex n newDistance)

addToPath :: PathToVertex -> Vertex -> PathToVertex 
addToPath fromPath to@(Vertex n2 d2) = fromPath >> tell [n2] >> return to


makePathVertex :: Int -> Vertex -> PathToVertex
makePathVertex edgeLength v = tell [number v] >> return (Vertex (number v) (edgeLength + distance v))


--xxx = (addToPath (makePathVertex v1) v2)

--data MyGraph = MyGraph {vertecess :: [Vertex], edgess :: [Edge]}

testGraph = Graph [( Vertex 1 0), (Vertex 2 0), (Vertex 3 0), (Vertex 4 0), (Vertex 5 0)] [(Edge 1 2 100), (Edge 1 3 150), (Edge 1 4 70), (Edge 2 3 20), (Edge 2 5 30), (Edge 3 5 1), (Edge 4 3 200), (Edge 4 5 1000)]
graph1 = Graph [(Vertex 1 (0)), (Vertex 2 (-1)), (Vertex 3 (-1))] [(Edge 1 2 10), (Edge 1 3 20), (Edge 2 3 100)]

{--markVerteces :: Graph -> Int -> Graph
markVerteces (Graph vl el) startVertex = Graph (markVerteces' vl startVertex) el
	where 
		markVerteces' :: [(Int, v)] -> Int -> [(Int, Int)]
		markVerteces' [] _ = []
		markVerteces' ((n, _):vs) startVertex
						      | n == startVertex = (n, 0) : (markVerteces' vs startVertex)
						      | otherwise        = (n, -1) : (markVerteces' vs startVertex)

--}

makeWriter :: Writer [String] (Int, Int) -> Int -> Int -> Writer [String] (Int, Int)
makeWriter w number distance = w >> tell ["We came to vertex: " ++ show number] >> return (number, distance)

createAll :: [Vertex] -> [PathToVertex]
createAll []     = []
createAll (v:vs) = (return v) : (createAll vs)

dijkstra :: Graph -> Int -> [PathToVertex]
dijkstra g n = dijkstra' g n (createAll $ verteces g) 0
	where 
		dijkstra' :: Graph -> Int -> [PathToVertex] -> Int -> [PathToVertex]
		dijkstra' g@(Graph vs es) n ps currentLength = do
					--tell ["Here's some testing"]
					let edges = filter (\edge -> (from edge) == n) es
					let newPs = updateLength edges ps currentLength
					--addLog :: Writer [String] (Int, Int)
					--addLog = tell ["We visited vertex: " ++ show number]
					--let newLog = makeWriter w n currentLength
					
			
					case (findNextVertex newPs currentLength) of
						Nothing -> newPs
						Just vp -> dijkstra' g (getNumber vp) newPs (getDistance vp)


		findPosition :: [PathToVertex] -> Int -> Int -> Int
		findPosition (p:ps) aim position
						| getNumber p == aim = position
						| otherwise   = findPosition ps aim (position + 1)

		updateLength :: [Edge] -> [PathToVertex] -> Int -> [PathToVertex]
		updateLength [] ps _ = ps
		updateLength (edge:es) ps currentMin = do
								let positionInList = findPosition ps (to edge) 0
								let finishVertex = ps !! positionInList
								let currentLength = getDistance finishVertex

								case (currentLength == -1 || currentLength > currentMin + (weight edge)) of
									True  -> updateLength es (setLengthToVertex ps (from edge) (to edge) (currentMin + (weight edge))) currentMin
									False -> updateLength es ps currentMin

									where setLengthToVertex :: [PathToVertex] -> Int -> Int -> Int -> [PathToVertex]
									      setLengthToVertex [] _ _ _ = []
									      setLengthToVertex (p:ps) fromNumber currentNumber currentLength =
															  if getNumber p == currentNumber
														      then (addEdge p fromNumber currentLength): ps
														      else p : (setLengthToVertex ps fromNumber currentNumber currentLength)

		
		sortRestVerteces :: [PathToVertex] -> Int -> [PathToVertex]
		sortRestVerteces ps length = sort (filter (\x -> getDistance x > length) ps)	
		
		findNextVertex :: [PathToVertex] -> Int -> Maybe PathToVertex
		findNextVertex [] _ = Nothing
		findNextVertex ps currentLength = do
								let newPs = sortRestVerteces ps currentLength				
								if length newPs > 0
								then Just (head ps)
								else Nothing


