
import System.Random
import Data.List

{- bingo :: IO ()
bingo = do (h:t) <- acumulaNums []
           getChar
           put

acumulaNums :: [Int] -> IO [Int]
acumulaNums l = do x <- randomRIO (1,90)
                   if (length l == 90) then return l 
                   	                   else if (any (== x) l) then acumulaNums l else acumulaNums (x:l)
-}

masterMind :: IO ()
masterMind = do x <- geraCodigo
                daRespostas x 15

geraCodigo :: IO [Char]
geraCodigo = do l <- sequence $ replicate 4 $ randomRIO ('1','9')
                return l

daRespostas :: [Char] -> Int -> IO()
daRespostas s 0 = putStrLn "Já Fostes!"
daRespostas segredo n = do putStr "Jogada?"
                           resp <- getLine
                           let (cc,ce) = calcula segredo resp
                           putStrLn ((show cc) ++ " números certos na posição certa" )
                           putStrLn ((show ce) ++ " números certos na posição errada")
                           if (cc == 4) then putStrLn "Parabéns\a\a\a\a" else do putStrLn "Tente novamente"
                                                                                 daRespostas segredo (n-1)

calcula :: String -> String -> (Int,Int)
calcula seg resp = (certos, comuns - certos)
               where certos = cc seg resp
                     comuns = length (intersect seg resp)
                     cc s r = length $ (filter id) $ (zipWith (==) s r)