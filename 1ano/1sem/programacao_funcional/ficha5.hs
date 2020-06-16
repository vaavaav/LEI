import Data.List 

-- 1 --
-- a)
any' :: (a -> Bool) -> [a] -> Bool
any' _ [] = False
any' f (h:t) = f h || any' f t

-- b)
zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] l2 = []
zipWith' _ l1 [] = []
zipWith' f (x:xs) (y:ys) = (f x y) : zipWith' f xs ys

-- c)
takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile f (h:t) | f h = h : takeWhile' f t
                  | otherwise = []

-- d)
dropWhile' :: (a -> Bool) -> [a] -> [a] 
dropWhile' _ [] = []
dropWhile' f (h:t) | f h = dropWhile' f t
                   | otherwise = t

-- e)
span' :: (a -> Bool) -> [a] -> ([a],[a])
span' _ [] = ([],[])
span' f (h:t) | f h = (h:x,y)
              | otherwise = ([],(h:t))
        where (x,y) = span' f t

-- f)
deleteBy' :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy' _ _ [] = []
deleteBy' f x (h:t) | f x h = t
                    | otherwise = h : deleteBy' f x t

-- g)
sortOn' :: Ord b => (a -> b) -> [a] -> [a]
sortOn' _ [] = []
sortOn' f (h:t) = insertOn' f h (sortOn' f t)
        where insertOn' _ x [] = [x]
              insertOn' f x (h:t) | f x <= f h = x : h : t
                                  | otherwise = h : insertOn' f x t

-- 2 --
type Polinomio = [Monomio]
type Monomio = (Float, Int)

-- a) 
selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau n (h:t) | snd h == n = h : selgrau n t
                | otherwise = selgrau n t

-- b)
conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta n (h:t) = (if (snd h == n) then 1 else 0) + conta n t 

-- c)
grau :: Polinomio -> Int 
grau l = grauAux 0 l
   where grauAux g [] = g
         grauAux g (h:t) | g >= snd h = grauAux g t
                         | otherwise = grauAux (snd h) t 

-- d)
deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((q,g):t) | g == 0 = (0,0) : deriv t
                | otherwise = (q * fromIntegral g,g-1) : deriv t

-- e)
calcula :: Float -> Polinomio -> Float
calcula = undefined

-- f)
simp :: Polinomio -> Polinomio
simp [] = []
simp (h:t) | fst h == 0 = simp t
           | otherwise = h : simp t

-- g)
mult :: Monomio -> Polinomio -> Polinomio
mult _ [] = []
mult (q,g) ((q',g'):t) = (q*q',g+g'): mult (q,g) t

-- h)
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena (h:t) = insertMon h (ordena t)
       where insertMon x [] = [x]
             insertMon x (h:t) | snd x <= snd h = x : h : t
                               | otherwise = h : insertMon x t

-- i)
normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza l = let (h:t) = ordena l in aux h t
         where aux m [] = [m]
               aux (q,g) ((q',g'):t) | g == g' = aux (q+q',g) t
                                     | g < g' = (q,g) : aux (q',g') t

-- j) Já se supõe que estão normalizados
soma :: Polinomio -> Polinomio -> Polinomio
soma [] l2 = l2
soma l1 [] = []
soma (h1:t1) (h2:t2) | snd h1 == snd h2 = (fst h1 + fst h2, snd h1) : soma t1 t2
                     | snd h1 < snd h2 = h1 : soma t1 (h2:t2) 
                     | snd h1 > snd h2 = h2 : soma (h1:t1) t2          

-- k) 
produto :: Polinomio -> Polinomio -> Polinomio
produto [] l2 = []
produto l1 [] = []
produto (h1:t1) l2 = (mult h1 l2) ++ produto t1 l2

-- l)
equiv :: Polinomio -> Polinomio -> Bool
equiv l1 l2 = normaliza l1 == normaliza l2

-- 3 --
type Mat a = [[a]]

-- a)
dimOK :: Mat a -> Bool
dimOK [] = True
dimOK (h:t) = eValida (length h) t
       where eValida n [] = True
             eValida n (h:t) = n == length h && eValida n t 

-- b)
dimMat :: Mat a -> (Int, Int)
dimMat [] = (0,0)
dimMat (h:t) = (length (h:t), length h)

-- c)
addMat :: Num a => Mat a -> Mat a -> Mat a
addMat m1 m2 = zipWith (zipWith (+)) m1 m2

-- d)
transpose' :: Mat a -> Mat a
transpose' [] = []
transpose' m = map head m : transpose' (tail m) 

-- e)
multMat :: Num a => Mat a -> Mat a -> Mat a
multMat [] [] = []
multMat (h1:t1) (h2:t2) = undefined


-- f)
zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c
zipWMat f m1 m2 = zipWith (zipWith f) m1 m2

-- g)
triSup :: Num a => Mat a -> Bool
triSup m = mEscada 0 m
     where mEscada _ [] = True
           mEscada n (h:t) = (qtsZeros n h) && mEscada (n+1) t
           qtsZeros _ [] = True 
           qtsZeros n (h:t) | n == 0 = True
                            | otherwise = h == 0 && qtsZeros (n-1) t
