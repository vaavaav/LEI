import Data.List

data SReais = AA Double Double | FF Double Double
            | AF Double Double | FA Double Double
            | Uniao SReais SReais

instance Show SReais where
       show (AA x y) = "]" ++ show x ++ "," ++ show y ++ "["
       show (FF x y) = "[" ++ show x ++ "," ++ show y ++ "]"
       show (AF x y) = "]" ++ show x ++ "," ++ show y ++ "]"
       show (FA x y) = "[" ++ show x ++ "," ++ show y ++ "["
       show (Uniao s1 s2) = "(" ++ show s1 ++ " U " ++ show s2 ++ ")"

pertence :: Double -> SReais -> Bool
pertence z (AA x y) = z > x && z < y
pertence z (FF x y) = z >= x && z <= y
pertence z (AF x y) = z > x && z <= y
pertence z (FA x y) = z >= x && z < y
pertence z (Uniao s1 s2) = pertence z s1 || pertence z s2

tira :: Double -> SReais -> SReais
tira z (AA x y) | z <= x || z >= y = AA x y
                | otherwise = Uniao (AA x z) (AA z y)
tira z (FF x y) | z < x || z > y = FF x y
                | z == x = AF x y
                | z == y = FA x y
                | otherwise = Uniao (FA x z) (AF z y)                
tira z (AF x y) | z <= x || z > y = AF x y
                | z == y = AA x y
                | otherwise = Uniao (AA x z) (AF z y)                
tira z (FA x y) | z < x || z >= y = FA x y
                | z == x = AA x y
                | otherwise = Uniao (FA x z) (AA z y)
tira z (Uniao s1 s2) = Uniao (tira z s1) (tira z s2)   

data RTree a = R a [RTree a]

percorre :: [Int] -> RTree a -> Maybe [a]
percorre [] (R x _) = Just [x]
percorre (h:t) (R x []) = Nothing 
percorre (h:t) (R x (y:ys)) | h == 1 = case result of 
                              Nothing -> Nothing 
                              Just y' -> Just (x : y')
                            | otherwise = percorre ((h-1):t) (R x ys)
         where result = percorre t y                             

procura :: Eq a => a -> RTree a -> Maybe [Int]
procura x r = procura' x r 1
procura' x (R y []) _ | x == y = Just []
                      | otherwise = Nothing
procura' x (R y (h:t)) n | x == y = Just []
                         | otherwise = case procura' x h 1 of
                                  Just h' -> Just (n : h')
                                  Nothing -> procura' x (R y t) (n+1)                     
