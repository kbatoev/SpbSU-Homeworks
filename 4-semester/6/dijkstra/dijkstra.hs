import Control.Monad.State
import Data.List
import Data.Ord

data Edge = Edge {
	cameFrom :: Int,
	cameTo :: Int,
	weight :: Int
}

data Vertex = Vertex {
	number :: Int,
	distance :: Maybe Int,
	path :: [Int]
}

data Graph = Graph [Vertex] [Edge]

instance Show Graph where
	show (Graph vs es) = show vs

instance Eq Vertex where
	v1 == v2 = (number v1) == (number v2)

instance Ord Vertex where
	compare v1 v2 = compareDistances (distance v1) (distance v2)

compareDistances :: Maybe Int -> Maybe Int -> Ordering
compareDistances Nothing x = GT
compareDistances y Nothing = LT
compareDistances (Just d1) (Just d2) = compare d1 d2

instance Show Vertex where
	show v = case distance v of
			Just d  -> "Vertex: " ++ show (number v) ++ ". Distance: " ++ show d ++ "\n" ++ "Path: " ++ show ((number v): path v) ++ "\n"
			Nothing -> "Vertex: " ++ show (number v) ++ " is unreacheable\n"

isNotGoingToDeletedVertex :: Int -> Edge -> Bool
isNotGoingToDeletedVertex n edge = (cameTo edge) /= n

findBestVertex :: Graph -> (Maybe Vertex, Graph)
findBestVertex g@(Graph [] _ ) = (Nothing, g)
findBestVertex g@(Graph verteces es) = let (v:vs) = sort verteces
					  	  			   in (Just v, (Graph vs (filter (isNotGoingToDeletedVertex (number v)) es))) 

createVertex :: Vertex -> Edge -> Vertex
createVertex (Vertex n Nothing p) (Edge f t w)  = (Vertex t Nothing [])
createVertex (Vertex n (Just d) p) (Edge f t w) = Vertex t (Just (d + w)) (n:p)

update :: [Edge] -> Maybe Vertex -> [Vertex]
update [] _		   = []
update es Nothing  = []
update (e:es) v1@(Just v) = if (cameFrom e == number v)
						 then (createVertex v e) : update es v1
						 else update es v1

chooseNewVerteces :: [Vertex] -> [Vertex] -> [Vertex]
chooseNewVerteces nvs []         = nvs
chooseNewVerteces [] oldvs       = oldvs
chooseNewVerteces (nv:nvs) oldvs = (chooseVertex nv (filter (==nv) oldvs)) : chooseNewVerteces nvs (filter (/=nv) oldvs)

chooseVertex :: Vertex -> [Vertex] -> Vertex
chooseVertex nv [] = nv
chooseVertex nv (v:vs) = if compare nv v == LT
		  				 then chooseVertex nv vs
		  				 else chooseVertex v vs

updateLength :: Maybe Vertex -> State Graph (Maybe Vertex)
updateLength Nothing = return Nothing
updateLength v1@(Just v) = state $ \(Graph vs es) -> (v1, (Graph (chooseNewVerteces (update (filter (isFrom (number v)) es) v1) vs) es)) 

isFrom :: Int -> Edge -> Bool
isFrom n e = n == cameFrom e

findBestVertexState :: State Graph (Maybe Vertex)
findBestVertexState = state findBestVertex

oneStepDijkstra :: State Graph (Maybe Vertex)
oneStepDijkstra = findBestVertexState >>= updateLength

dijkstra :: State Graph [Vertex]
dijkstra = do
			currentVertex <- oneStepDijkstra
			case currentVertex of
				Just v   -> do
							vs <- dijkstra
							return (v:vs)
				Nothing  -> return []



v1 = Vertex 1 (Just 0) []
vs = [v1, (Vertex 2 Nothing []), (Vertex 3 Nothing [])]
es = [(Edge 1 2 10), (Edge 1 3 4), (Edge 2 3 5)]
g1 = Graph vs es

g2 = Graph [v1, (Vertex 2 Nothing []), (Vertex 3 Nothing [])] [(Edge 1 2 10)]
g3 = Graph [(Vertex 1 Nothing []), (Vertex 2 Nothing []), (Vertex 3 (Just 0) [])] [(Edge 1 2 10)]


testEdges = [(Edge 1 2 100), (Edge 1 3 150), (Edge 1 4 70), (Edge 2 3 20), (Edge 2 5 30), (Edge 3 5 1), (Edge 4 3 200), (Edge 4 5 1000)]
testVerteces = [(Vertex 1 (Just 0) []), (Vertex 2 Nothing []), (Vertex 3 Nothing []), (Vertex 4 Nothing []), (Vertex 5 Nothing [])]
testGraph = Graph testVerteces testEdges

{--

To run dijkstra, use this command:
fst $ (runState dijkstra ) testGraph 

--}
