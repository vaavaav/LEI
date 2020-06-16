import Data.Char

----2
--a
dobros :: [Float] -> [Float] 
dobros []  = []
dobros (x:l) = 2 * x : dobros l

--b
numOcorre :: Char -> String -> Int
numOcorre char [] = 0
numOcorre char (x:l) = (if char == x then 1 else 0) + numOcorre char l

--c
positivos :: [Int] -> Bool
positivos [] = False
positivos [x] = (x > 0)
positivos (x:l) = (x > 0) && (positivos l)

--d
soPos :: [Int] -> [Int]
soPos [] = []
soPos (x:l) = if x > 0 then x : soPos l else soPos l

--e
somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (x:l) = if x < 0 then x + somaNeg l else somaNeg l

--f
tresUlt :: [a] -> [a]
tresUlt [] = []
tresUlt [a] = [a]
tresUlt (a:b:[]) = [a,b]
tresUlt (a:b:c:[]) = [a,b,c]
tresUlt (a:b:l) = tresUlt (b:l)

--g
segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((a,b):l) = b : segundos l

--h
nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros x [] = False
nosPrimeiros x ((a,b):l) = (x == a) || nosPrimeiros x l

--i
sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumTriplos [(a,b,c)] = (a,b,c)
sumTriplos ((a,b,c):(x,y,z):[]) = (a+x,b+y,c+z)
sumTriplos ((a,b,c):(x,y,z):l) = sumTriplos ((a+x,b+y,c+z):l)  

----3
--a
soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (x:l) = if isNumber x then x : soDigitos l else soDigitos l

--b
minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (x:l) = (if isLower x then 1 else 0) + minusculas l

--c
nums :: String -> [Int]
nums [] = []
nums (x:l) = if isNumber x then fromEnum x - 48 : nums l else nums l 

----4
type Polinomio = [Monomio]
type Monomio = (Float, Int)

--a
conta :: Int -> Polinomio -> Int
conta n [] = 0
conta n ((coe,exp):l) = (if n == exp then 1 else 0) + conta n l
 
--b
grau :: Polinomio -> Int 
grau [] = 0
grau ((coe, exp):l) = if exp > grau l then exp else grau l

--c
selgrau :: Int -> Polinomio -> Polinomio
selgrau n [] = []
selgrau n ((coe, exp):l) = if n == exp then (coe,exp) : selgrau n l else selgrau n l

--d
deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((coe,0):l) = (0,0) : deriv l
deriv ((coe,exp):l) = (fromIntegral exp * coe, exp - 1) : deriv l

--e
calcula :: Float -> Polinomio -> Float 
calcula _ [] = 0
calcula 0 _ = 0
calcula x ((coe,exp):l) = coe * x ^ fromIntegral(exp) + calcula x l  

--f
simp :: Polinomio ->  Polinomio
simp [] = []
simp ((coe,exp):l) = if (exp == 0) then simp l else (coe,exp) : simp l

--g
mult :: Monomio -> Polinomio -> Polinomio
mult _ [] = []
mult (c,n) ((coe,exp):l) = (c * coe, exp + n) : mult (c,n) l

--h
normaliza :: Polinomio -> Polinomio 
normaliza [] = []
normaliza (h:t) = junta h (normaliza t)
          where junta h [] = [h]
                junta (a,b) ((x,y):t) |b == y = ((a+x,b):t)
                                      |otherwise = (x,y) : junta (a,b) t



{-
Ex: >normaliza [(1,2),(4,2),(1,1),(5,1)] = junta (1,2) (normaliza [(4,2),(1,1),(5,1)]) = junta (1,2) (junta (4,2) (normaliza [(1,1),(5,1)]))) = 
= junta (1,2) (junta (4,2) (junta (1,1) (normaliza [(5,1)]))) =  junta (1,2) (junta (4,2) (junta (1,1) (junta (5,1) [] ))) =  junta (1,2) (junta (4,2) (junta (1,1) [(5,1)] )))
= junta (1,2) (junta (4,2)  [(6,1)])
= junta (1,2) [(6,1),(4,2)] 	
= [(6,1),(5,2)]
-}


--i
soma :: Polinomio -> Polinomio -> Polinomio
soma a b = 

--j 
produto :: Polinomio -> Polinomio -> Polinomio
produto _ [] = []
produto [] _ = []
produto (h:t) (i:q) =          produto t (i:q) 

{-
Ex: >produto [(1,1),(1,0)] [(1,1),(-1,0)] =



-} 