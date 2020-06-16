import Data.List
import Data.Char

-- 2 --
a = [2^x| x <- [0..10]]

b = [(x,6-x)| x <- [1..5]]

c = [[x | x <- [1..y]]| y <- [1..5]]

d = undefined

e = undefined

-- 3 --

digitAlpha :: String -> (String, String)
digitAlpha [] = ("","")
digitAlpha (h:t) | isDigit h = (h:ns,ls) 
                 | isAlpha h = (ns,h:ls)
             where (ns,ls) = digitAlpha t

-- 4 --
nzp :: [Int] -> (Int, Int, Int)
nzp [] = (0,0,0)
nzp (h:t) | h > 0 = (n,z,1+p)
          | h == 0 = (n,1+z,p)
          | h < 0 = (n+1,z,p)
    where (n,z,p) = nzp t 

-- 5 --
div' :: Integral a => a -> a -> a
div' n d | n >= d = 1 + div' (n - d) d
         | otherwise = 0

mod' :: Integral a => a -> a -> a
mod' n d | n >= d = mod' (n - d) d
         | n < d = n

divMod' :: Integral a => a -> a -> (a,a)
divMod' n d | n >= d = (1+a,b)
            | otherwise = (0, n)
        where (a,b) = divMod (n-d) d 
 
-- 6 --
fromDigits :: [Int] -> Int
fromDigits l = fAux 0 l
    where fAux c [] = c
          fAux c (x:xs) = fAux(c*10+x) xs


-- 7 --
maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit l = auxMax 0 0 l

auxMax :: (Num a, Ord a) => a -> a -> [a] -> a
auxMax max _ [] = max
auxMax max total (h:t) | max < total + h = auxMax (total + h) (total + h) t
                       | otherwise = auxMax max (total + h) t

-- 8 --
fib :: Int -> Int
fib n = fibA 0 1 n

fibA :: Int -> Int -> Int -> Int
fibA e d n | n == 0 = e
           | n == 1 = d
           | otherwise = fibA d (e + d) (n-1)