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

data Graph = Graph {
	vertecess :: [Vertex],
	edgess :: [Edge]
}
instance Show Graph where
	show (Graph vs es) = show vs

instance Eq Vertex where
	v1 == v2 = (number v1) == (number v2)

instance Ord Vertex where
	compare v1 v2 = compareDistances (distance v1) (distance v2)
					where
						compareDistances :: Maybe Int -> Maybe Int -> Ordering
						compareDistances Nothing x = GT
						compareDistances y Nothing = LT
						compareDistances (Just d1) (Just d2) = compare d1 d2

instance Show Vertex where
	show v = case distance v of
			Just d  -> "Vertex: " ++ show (number v) ++ ". Distance: " ++ show d ++ "\n" ++ "Path: " ++ show ((number v): path v) ++ "\n"
			Nothing -> "Vertex: " ++ show (number v) ++ " is unreacheable\n"

createVertex :: Vertex -> Edge -> Vertex
createVertex (Vertex n Nothing p) (Edge f t w)  = (Vertex t Nothing [])
createVertex (Vertex n (Just d) p) (Edge f t w) = Vertex t (Just (d + w)) (n:p)

update :: [Edge] -> Vertex -> [Vertex]
update [] _		= []
update (e:es) v = (createVertex v e) : update es v

chooseNewVerteces :: [Vertex] -> [Vertex] -> [Vertex]
chooseNewVerteces nvs []         = nvs
chooseNewVerteces [] oldvs       = oldvs
chooseNewVerteces (nv:nvs) oldvs = (chooseVertex nv (filter (==nv) oldvs)) : chooseNewVerteces nvs (filter (/=nv) oldvs)

chooseVertex :: Vertex -> [Vertex] -> Vertex
chooseVertex nv [] = nv
chooseVertex nv (v:vs) = if compare nv v == LT
		  				 then chooseVertex nv vs
		  				 else chooseVertex v vs

updateLength :: Vertex -> State Graph ()
updateLength v = do
				 g <- get
				 let edges = edgess g
				 let possibleVs = update (filter (\edge -> cameFrom edge == number v) edges) v
				 let newVs = chooseNewVerteces possibleVs (vertecess g)
				 put (Graph newVs edges)

findBestVertex :: State Graph (Maybe Vertex)
findBestVertex = do
				g <- get
				case (vertecess g) of
					[] -> return $ Nothing
					vs -> do
						    let (v:restVs) = sort vs
						    let restEs = filter (\edge -> cameTo edge /= number v) (edgess g)
						    put (Graph restVs restEs)
						    return (Just v)

dijkstra :: State Graph [Vertex]
dijkstra = do
			currentVertex <- findBestVertex
			case currentVertex of
				Just v   -> do
							updateLength v
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
