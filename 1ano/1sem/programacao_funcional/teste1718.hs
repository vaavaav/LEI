import Data.List
import System.Random

myInsert :: Ord a => a -> [a] -> [a]
myInsert x [] = [x]
myInsert x (h:t) | x <= h = x:h:t
                 | otherwise = h : (myInsert x t)

myCatMaybes :: [Maybe a] -> [a]
myCatMaybes [] = []
myCatMaybes (h:t) = case h of
            Just x -> x : (myCatMaybes t)
            Nothing -> myCatMaybes t

data Exp a = Const a
           | Var String
           | Mais (Exp a) (Exp a)
           | Mult (Exp a) (Exp a)

instance Show a => Show (Exp a) where
      show (Const x) = show x
      show (Var s) = s
      show (Mais e1 e2) = "(" ++ show (e1) ++ " + " ++ show (e2) ++ ")"
      show (Mult e1 e2) = "(" ++ show (e1) ++ " * " ++ show (e2) ++ ")"

sortOn' :: Ord b => (a -> b) -> [a] -> [a]
sortOn' _ [] = []
sortOn' f (h:t) = insertOn f h (sortOn' f t)
          where insertOn _ h [] = [h]
                insertOn f h (x:xs) | f h <= f x = h : x : xs
                                    | otherwise = x : (insertOn f h xs)

amplitude :: [Int] -> Int 
amplitude [] = 0
amplitude (h:t) = aux t h h
       where aux [] max min = max - min
             aux (h:t) max min | h > max = aux t h min
                               | h < min = aux t max h
                               | otherwise = aux t max min

parte :: [Int] -> ([Int],[Int])                                   
parte [] = ([],[])
parte [x] = ([x],[])  
parte l = aux (maiorDif t h h 0) (h:t) 
      where aux (a,b) (h:i:t) | h == a && b == i = ([h],(i:t))
                              | otherwise = ((h:x),xs)
                        where (x,xs) = aux (a,b) (i:t)
            (h:t) = sort l
            maiorDif [] e d _ = (e,d)
            maiorDif [x] e d _ = (e,d)
            maiorDif (h:i:t) e d amp | i - h > amp = maiorDif (i:t) h i (i-h)
                                     | otherwise = maiorDif (i:t) e d amp



data Imagem = Quadrado Int
            | Mover (Int,Int) Imagem
            | Juntar [Imagem]
        deriving Show
conta :: Imagem -> Int
conta (Quadrado _) = 1
conta (Mover _ i) = conta i
conta (Juntar []) = 0
conta (Juntar (h:t)) = conta h + conta (Juntar t)             


apaga :: Imagem -> IO Imagem
apaga im = do let x = conta im
              q <- randomRIO (1,x)
              return (fst (removeIm im q))

removeIm :: Imagem -> Int -> (Imagem,Int)
removeIm (Quadrado x) q | q == 1 = (Juntar [],0)
                        | otherwise = (Quadrado x, q - 1)
removeIm (Mover p i) q = (Mover p i',q')
               where (i',q') = removeIm i q
removeIm (Juntar []) q = (Juntar [], q)
removeIm (Juntar (h:t)) q = (Juntar (h':t'), q'')
                  where (h',q') = removeIm h q
                        (Juntar t',q'') = removeIm (Juntar t) q'                
