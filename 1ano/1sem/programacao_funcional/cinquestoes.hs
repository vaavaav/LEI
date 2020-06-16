--1--

deAaB :: Int -> Int -> [Int]
deAaB a b  | a < b = a : deAaB (a + 1) b 
           | a == b = b : []

--2--
deAporBaC :: Int -> Int -> Int -> [Int]
deAporBaC a b c | k < 0 && a < c = []
                | k > 0 && a > c = []
                | a == c = [c]
                | otherwise = a : (deAporBaC (a + k) (b + k) c)
                where k = b - a

--3--
somList :: [a] -> [a] -> [a]
somList [] [] = []
somList x [] = x
somList [] y = y
somList (h:t) l = h : somList t l

--4--
oElemN :: [a] -> Int -> a 
oElemN (h:t) 0 = h
oElemN (h:t) n = oElemN t (n - 1)

--5--
inversaList :: [a] -> [a]
inversaList [] = []
inversaList (h:t) = inversaList t ++ [h] 

--6--
primNelem :: Int -> [a] -> [a]
primNelem _ [] = []
primNelem 0 _ = []
primNelem n (h:t) = h : primNelem (n - 1) t 

--7--
tiraNelem :: Int -> [a] -> [a]
tiraNelem _ [] = []
tiraNelem 0 l = l
tiraNelem n (h:t) = tiraNelem (n - 1) t  

--8--
listPares :: [a] -> [b] -> [(a,b)]
listPares [] _ = []
listPares _ [] = []
listPares (a:x) (b:y) = (a,b) : listPares x y

--9--
eElem :: Eq a => a -> [a] -> Bool
eElem _ [] = False
eElem a (h:t) = a == h ||  eElem a t

--10--
replicar :: Int -> a -> [a]
replicar 0 _ = []
replicar n a = a : replicar (n - 1) a

--11--
intercalar :: a -> [a] -> [a]
intercalar _ [] = []
intercalar _ [h] = [h]
intercalar x (h:t) = h : x : intercalar x t

--12-- (Versão da Beatriz)
agrupaCons :: Eq a => [a] -> [[a]]
agrupaCons [] = []
agrupaCons [x] = [[x]]
agrupaCons (h:t) | h == x = ((h:x:l1):l2)
                 | otherwise = ([h]:(x:l1):l2)
                 where ((x:l1):l2) = agrupaCons t

--13--
concatenar :: [[a]] -> [a]
concatenar [] = []
concatenar (h:t) = juntaL h (concatenar t)
                 where juntaL [] l = l
                       juntaL (x:xs) l = x : juntaL xs l   

--14--  (Visto pela resolução em aula)
myInits :: [a] -> [[a]]
myInits [] = [[]]
myInits (h:t) = [] : (junta h ( myInits t))   
      where junta h [] = []        
            junta h (x:xs) = (h : x) : (junta h xs)   

--15--
myTails :: [a] -> [[a]]
myTails [] = [[]]
myTails (x:xs) = l : myTails xs      
    where l = (x:xs) 

--16--
myIsPrefixOf :: Eq a => [a] -> [a] -> Bool
myIsPrefixOf [] _ = False
myIsPrefixOf _ [] = False
myIsPrefixOf (h:t) (x:xs) | h == x = True && myIsPrefixOf t xs  
                          | otherwise = False 

--17--
myIsSufixOf :: Eq a => [a] -> [a] -> Bool
myIsSufixOf [] [] = True
myIsSufixOf _ [] = False
myIsSufixOf (h:t) (x:xs) | length (h:t) == length (x:xs) = (h == x) && myIsSufixOf t xs                       
                         | otherwise = myIsSufixOf (h:t) xs


--18--
myIsSubsequenceOf :: Eq a => [a] -> [a] -> Bool
myIsSubsequenceOf [] _ = True
myIsSubsequenceOf _ [] = False
myIsSubsequenceOf (h:t) (x:xs) | h == x = myIsSubsequenceOf t (x:xs)
                               | otherwise = myIsSubsequenceOf (h:t) xs

--19--
myElemIndices :: Eq a => a -> [a] -> [Int]
myElemIndices _ [] = []


 
--20--
myNub :: Eq a => [a] -> [a]
myNub [] = []
myNub [x] = [x]
myNub (x:xs) = x : encontra x (myNub xs) 
      where encontra x [] = []
            encontra a (h:t) | a == h = encontra a t 
                             | otherwise = h : encontra a t

--21--
myDelete :: Eq a => a -> [a] -> [a]
myDelete _ [] = []
myDelete a (x:xs) | a == x = xs
                  | otherwise = x : myDelete a xs

--22--
myDeleteL :: Eq a => [a] -> [a] -> [a]
myDeleteL [] _ = []
myDeleteL l [] = l 
myDeleteL (a:as) (x:xs) = myDeleteL (deleteX x (a:as)) xs
           where deleteX _ [] = []
                 deleteX n (h:t) | n == h = t
                                  | otherwise = h : deleteX n t

--23--
myUnion :: Eq a => [a] -> [a] -> [a]
myUnion [] l = l
myUnion l [] = l
myUnion (a:as) (x:xs) = junta (a:as) (encontra (x:xs) (a:as))
        where encontra [] _ = []
              encontra (x:xs) [] = x : encontra xs (a:as)
              encontra (x:xs) (a:as) | x == a = encontra xs (a:as)
                                     | otherwise = encontra (x:xs) as
              junta l [] = l
              junta [] l = l                       
              junta (a:b) l = a : junta b l  

--24--
myIntersect :: Eq a => [a] -> [a] -> [a]
myIntersect _ [] = []
myIntersect [] _ = []
myIntersect (h:t) (x:xs) = junta (retiraNX h (x:xs)) (myIntersect t (x:xs)) 
                         where retiraNX h [] = []
                               retiraNX h (x:xs) | h == x = [h]
                                                 | otherwise = retiraNX h xs
                               junta [] l = l
                               junta l [] = l
                               junta (h:t) l = h : junta t l

--25--
myInsert :: Ord a => a -> [a] -> [a]
myInsert a [] = [a]
myInsert a (h:t) | a <= h = a:(h:t)
                 | a > h = h : myInsert a t

--26--
myUnwords :: [String] -> String
myUnwords [] = []
myUnwords (h:t) = junta h (' ':myUnwords t)
                where junta h [] = h
                      junta [] l = l
                      junta (x:xs) l = x : junta xs l

--27--
myUnlines :: [String] -> String
myUnlines [] = []
myUnlines (h:t) = junta h (('\n'):(myUnlines t))
                where junta h [] = h
                      junta [] l = l 
                      junta (x:xs) l = x : junta xs l

--28--
pMaior :: Ord a => [a] -> Int
pMaior [h] = 0
pMaior (h:t) | qtsMaiores h t == 0 = 0 
             | otherwise = 1 + pMaior t
             where qtsMaiores x [] = 0
                   qtsMaiores x (h:t) | x >= h = 0 + qtsMaiores x t
                                      | x < h = 1 + qtsMaiores x t

--29--
temRepetidos :: Eq a => [a] -> Bool
temRepetidos [x] = False
temRepetidos (h:t) = (repetido h t) || temRepetidos t
                   where repetido h [] = False
                         repetido h (x:xs) | h == x = True
                                           | otherwise = repetido h xs

--30--
algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (h:t) | h >= '0' && h <= '9' = h : algarismos t
                 | otherwise = algarismos t

--31--
posImpares :: [a] -> [a]
posImpares [] = []
posImpares [h] = []
posImpares (h:i:t) = i:(posImpares t)

--32--
posPares :: [a] -> [a]
posPares [] = []
posPares [h] = [h]
posPares (h:i:t) = h:(posPares t) 

--33--
isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (h:i:t) | h <= i = True && isSorted (i:t)
                 | otherwise = False

--34--
iSort :: Ord a => [a] -> [a]
iSort [] = []
iSort (h:t) = insert h (iSort t)
              where insert h [] = [h]
                    insert h (x:xs) | h <= x = h : x : xs 
                             | otherwise = x : insert h xs      


--35--
menor :: String -> String -> Bool
menor _  [] = False
menor [] _  = True
menor (x:xs) (y:ys) | 'x' <= 'y' = True && (menor xs ys)
                    | otherwise = False

--36--
elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet _ [] = False
elemMSet x ((a,_):t) | x == a = True
                     | otherwise = False || elemMSet x t 

--37--
lengthMSet :: [(a,Int)] -> Int 
lengthMSet [] = 0
lengthMSet ((_,n):t) = n + lengthMSet t 

--38--
convertMSet :: [(a,Int)] -> [a]
convertMSet [] = []
convertMSet ((a,n):t) | n > 0 = a : convertMSet ((a,n-1):t)
                      | otherwise = convertMSet t 

--39--
insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet b [] = [(b,1)]
insereMSet b ((a,n):t) | b == a = ((a,n+1):t)
                       | otherwise = (a,n) : insereMSet b t

--40--
removeMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet b [] = []
removeMSet b ((a,n):t) | b == a && n == 1 = t
                       | b == a && n > 1 = (a,n-1):t
                       | otherwise = (a,n) : removeMSet b t

--41--
constroiMSet :: Ord a => [a] -> [(a,Int)]
constroiMSet [] = []
constroiMSet (h:t) = juntaP ((h,1) : constroiMSet t) 
                   where juntaP [] = []
                         juntaP [(a,n)] = [(a,n)]
                         juntaP ((a,n):(b,m):t) | a == b = (a,n + m) : juntaP t
                                                | otherwise = (a,n) : juntaP ((b,m):t)

--42--
myPartitionEithers :: [Either a b] -> ([a],[b])
myPartitionEithers [] = ([],[]) 
myPartitionEithers ((Left a):t)  = (a:x, y)              -- (let (x,y) = myPartitionEithers t 
                    where (x,y) = myPartitionEithers t   -- in (a:x, y))
myPartitionEithers ((Right b):t) = (x, b:y)              -- (let (x,y) = myPartitionEithers t 
                    where (x,y) = myPartitionEithers t   -- in (x, b:y))

                                 
--43--
catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes ((Just a):t) = a : catMaybes t
catMaybes (Nothing:t) = catMaybes t 

--ROBOT P1--
data Movimento = Norte | Sul | Este | Oeste
               deriving Show
----

--44--
posicao :: (Int,Int) -> [Movimento] -> (Int,Int)
posicao (x,y) [] = (x,y)
posicao (x,y) (Norte:t) = posicao (x,y+1) t
posicao (x,y) (Sul:t) = posicao (x,y-1) t
posicao (x,y) (Este:t) = posicao (x+1,y) t
posicao (x,y) (Oeste:t) = posicao (x-1,y) t

--45--
caminho :: (Int, Int) -> (Int, Int) -> [Movimento]
caminho (a,b) (c,d) | a == c && b == d = []
                    | a == c && d - b > 0 = Norte : caminho (a, b+1) (c,d) 
                    | a == c && d - b < 0 = Sul : caminho (a, b-1) (c,d)
                    | c - a > 0 = Este : caminho (a+1, b) (c,d)
                    | otherwise = Oeste : caminho (a-1, b) (c,d)

--46--
vertical :: [Movimento] -> Bool 
vertical [] = True
vertical ((Norte):t) = True && vertical t
vertical ((Sul):t) = True && vertical t 
vertical ((_):t) = False 

--ROBOT P2--
data Posicao = Pos Int Int
             deriving Show
----

--47--
maisCentral :: [Posicao] -> Posicao
maisCentral [t] = t
maisCentral ((Pos x1 y1):(Pos x2 y2):t) | x1^2 + y1^2 <= x2^2 + y2^2
                                         = maisCentral ((Pos x1 y1):t) 
                                        | otherwise = maisCentral ((Pos x2 y2):t)     

--48--
vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos _ [] = []
vizinhos (Pos x y) ((Pos x1 y1):t) |  ( x - x1 == 1 || x - x1 == -1
                                    || x - x1 == 0) && (y - y1 == 0
                                    || y - y1 == 1 || y - y1 == -1)
                                    = (Pos x1 y1) : (vizinhos (Pos x y) t)
                                   | otherwise = vizinhos (Pos x y) t

--49--
mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada [] = True
mesmaOrdenada [Pos x y] = True
mesmaOrdenada ((Pos x1 y1):(Pos x2 y2):t) | y1 == y2 = True && mesmaOrdenada ((Pos x2 y2):t)
                                          | otherwise = False 

--Info 50--
data Semaforo = Verde | Amarelo | Vermelho
              deriving Show
----

--50--
interseccaoOK :: [Semaforo] -> Bool
interseccaoOK [] = True
interseccaoOK [_] = True
interseccaoOK l | valorSmf l > 1 = False
                | otherwise = True 
                where valorSmf [] = 0
                      valorSmf (Verde:t) = 1 + valorSmf t
                      valorSmf (Amarelo:t) = 1 + valorSmf t
                      valorSmf (Vermelho:t) = 0 + valorSmf t 
