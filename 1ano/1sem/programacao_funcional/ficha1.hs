perimetro :: Double -> Double
perimetro raio = 2 * pi * raio

dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1,y1) (x2,y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

--comentário começam com "--"

primUlt :: [t] -> (t,t)
primUlt lista = (head lista, last lista) -- um par escreve-se entre "(" e ")"  enquanto que uma lista escrev-se entre "[" e "]"

multiplo :: Int -> Int -> Bool
multiplo m n = if (mod m n == 0) then True else False

truncaImpar :: [a] -> [a]
truncaImpar lista = if(mod (length lista) 2 == 0) then lista else tail lista  

max2 :: Int -> Int -> Int
max2 x y = if x >= y then x else y

max3 :: Int -> Int -> Int -> Int
max3 x y z = if(max2 x y > z) then max2 x y else z


nRaizes :: Double -> Double -> Double -> Int
nRaizes a b c = if( binDis > 0) then 2 else (if( binDis == 0) then 1 else 0) 
 where binDis = b^2 - 4*a*c

raizes :: (Double,Double,Double) -> (Double,Double)
raizes (a,b,c) = (r1,r2)
 where r1 = (-b + r) / (2*a)
       r2 = (-b - r) / (2*a)
       d = b^2 - 4*a*c
       r | d >= 0 = sqrt d
         | d < 0 = error "raizes imaginarias"

type Hora = (Int, Int)

isHora :: Hora -> Bool
isHora (h, m)  | (h < 24 && h >= 0) && (m < 60 && m >= 0) = True
               | otherwise = False

isAfter :: Hora -> Hora -> Bool
isAfter (h1, m1) (h2, m2) = isHora (h1,m1) && isHora(h2,m2) &&
                           ((h1 == h2 && m1 < m2)||(h1<h2))
                         

toMin :: Hora -> Int
toMin (h, m) = if (isHora (h,m)) then 
    h * 60 + m
else error "Hora Inválida"  

toHora :: Int -> Hora
toHora x = if (x >= 0 && x <= 1439) then 
    (quot x 60, mod x 60 )
else error "Hora(s) Inválida(s)" 

difHora :: Hora -> Hora -> Int
difHora (h1, m1) (h2, m2) = if (isHora (h1,m1) && isHora(h2,m2)) then 
    abs(h1 - h2) * 60 + abs(m1 - m2)
else error "Hora(s) Inválida(s)"

addMintoHora :: Hora -> Int -> Hora 
addMintoHora (h, m) m1 = (h + quot (m + m1) 60, mod (m + m1) 60)

data Horad = H Int Int deriving (Show,Eq)

isHorad :: Horad -> Bool
isHorad (H h m)  | (h < 24 && h >= 0) && (m < 60 && m >= 0) = True
                 | otherwise = False 

data Semaforo = Verde | Amarelo | Vermelho deriving (Show, Eq)

next :: Semaforo -> Semaforo
next Verde = Amarelo
next Amarelo = Vermelho
next Vermelho = Verde 

stop :: Semaforo -> Bool
stop Vermelho = True
stop _ = False

safe :: Semaforo -> Semaforo -> Bool 
safe Vermelho _ = True
safe _ Vermelho = True
safe _ _ = False

data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show, Eq)

posx :: Ponto -> Double
posx (Cartesiano x y) = (if x >= 0 then 1 else -1 ) * x
posx (Polar r ang) = (if x >= 0 then 1 else -1 ) * x
     where x = r * cos ang   

posy :: Ponto -> Double
posy (Cartesiano x y) = (if y >= 0 then 1 else -1 ) * y
posy (Polar r ang) = (if y >= 0 then 1 else -1 ) * y
     where y = r * sin ang   

posx' :: Ponto -> Double
posx' (Cartesiano x y) =  x
posx' (Polar r ang) =  x
     where x = r * cos ang   

posy' :: Ponto -> Double
posy' (Cartesiano x y) =  y
posy' (Polar r ang) =  y
     where y = r * sin ang   

raio :: Ponto -> Double
raio (Cartesiano x y) = sqrt(x^2 + y^2)
raio (Polar r ang) = r

angulo :: Ponto -> Double
angulo (Cartesiano x y) = atan (y/x)
angulo (Polar r ang) = ang

dista :: Ponto -> Ponto -> Double
dista (Cartesiano x y) (Cartesiano a b) = sqrt( (x - a)^2 + (y - b)^2)  
dista (Cartesiano x y) (Polar r ang) = sqrt( (x - a)^2 + (y - b)^2)
    where (a, b) = (r * cos ang, r * sin ang) 
dista (Polar r ang) (Cartesiano x y) = sqrt( (x - a)^2 + (y - b)^2)
    where (a, b) = (r * cos ang, r * sin ang) 
dista (Polar r1 ang1) (Polar r2 ang2) = sqrt( (x - a)^2 + (y - b)^2)
    where (a, b, x, y) = (r1 * cos ang1, r1 * sin ang1, r2 * cos ang2, r2 * sin ang2)        

data Figura = Circulo Ponto Double
            | Rectangulo Ponto Ponto
            | Triangulo Ponto Ponto Ponto
              deriving (Show,Eq)

poligono :: Figura -> Bool
poligono (Circulo ponto raio) = (raio > 0)
poligono (Rectangulo p1 p2) =  (posx p1 - posx p2 /= 0 && posy p1 - posy p2 /= 0 )
poligono (Triangulo p1 p2 p3) = ((dista p1 p2 > 0) && (dista p1 p3 > 0) && (dista p2 p3 > 0)) 

vertices :: Figura -> [Ponto]
vertices (Circulo ponto raio) = []
-- vertices (Rectangulo p1 p2) = [p1, p2, p3, p4]
 --   where (p3, p4) = (Cartesiano )
vertices (Triangulo p1 p2 p3) = [p1, p2, p3]


perimetro2 :: Figura -> Double
perimetro2 (Circulo _ raio) = 2*pi*raio
-- perimetro2 (Rectangulo p1 p2) = 
perimetro2 (Triangulo p1 p2 p3) = dista p1 p2 + dista p1 p3 + dista p2 p3


