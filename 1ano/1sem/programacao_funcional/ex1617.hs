import Data.List

unlines' :: [String] -> String
unlines' [] = ""
unlines' [x] = x
unlines' (h:i:t) = h ++ ('\n': (unlines' (i:t))) 

b :: Eq a => [a] -> [a] -> [a]
b l [] = l
b [] _ = []
b (h:t) (x:xs) = b (remover (h:t) x) xs
        where remover [] _ = []
              remover (h:t) x | h == x = t
                              | otherwise = h : remover t x

data Seq a = Nil | Inicio a (Seq a) | Fim (Seq a) a
          deriving Show

primeiro :: Seq a -> a
primeiro (Inicio x _) = x
primeiro (Fim s x) = case s of
        Nil -> x
        _ -> primeiro s

semUltimo :: Seq a -> Seq a 
semUltimo (Inicio x s) = case s of
             Nil -> Nil
             _ -> Inicio x (semUltimo s)
semUltimo (Fim s _) = s

data BTree a = Empty | Node a (BTree a) (BTree a)
     deriving Show

prune :: Int -> BTree a -> BTree a
prune _ Empty = Empty
prune n (Node x t1 t2) | n == 0 = Empty
                       | otherwise = Node x (prune (n-1) t1) (prune (n-1) t2)

semMinimo :: (Ord a) => BTree a -> BTree a
semMinimo (Node x Empty d) = d
semMinimo (Node x e d) = Node x (semMinimo e) d

type Tabuleiro = [String]

posicoes :: Tabuleiro -> [(Int,Int)]
posicoes l = aux l 0 0 
    where aux [] _ _ = []
          aux ([]:t) c l = aux t 0 (l+1)
          aux ((x:xs):t) c l = case x of
              '.' -> aux (xs:t) (c+1) l
              'R' -> (c,l): aux (xs:t) (c+1) l

valido :: Tabuleiro -> Bool
valido = aux . posicoes
       where aux [] = True
             aux (h:t) = (verifica h t) && (aux t)
             verifica _ [] = True
             verifica (c,l) ((c',l'):t) = c /= c' && l /= l' && (c'-c) /= (l'-l) && verifica (c,l) t

bemFormado :: Int -> Tabuleiro -> Bool
bemFormado n l = aux n l 0 0 0
 where aux n [] l c r = n == l && n == r
       aux n ([]:t) l c r = c == n && aux n t (l+1) 0 r 
       aux n ((x:xs):t) l c r | x == '.' = aux n (xs:t) l (c+1) r
                              | x == 'R' = aux n (xs:t) l (c+1) (r+1)
                              | otherwise = False
