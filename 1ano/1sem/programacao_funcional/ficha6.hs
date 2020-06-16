data BTree a = Empty
             | Node a (BTree a) (BTree a)
           deriving Show

--ExemploTeste--
t :: BTree Int
t = Node 5 (Node 3 (Empty) (Node 2 Empty Empty)) (Empty)


-- (a) --
altura :: BTree a -> Int
altura Empty = 0
altura (Node x l r) = 1 + max (altura l) (altura r) 

-- (b) --
contaNodos :: BTree a -> Int 
contaNodos Empty = 0
contaNodos (Node x l r) = 1 + altura l + altura r

-- (c) --
folhas :: BTree a -> Int
folhas Empty = 0
folhas (Node _ Empty Empty) = 1
folhas (Node x l r) = folhas l + folhas r 

-- (d) --
prune :: Int -> BTree a -> BTree a
prune _ Empty = Empty
prune 0 _ = Empty
prune n (Node x l r) = Node x (prune (n-1) l) (prune (n-1) r) 

-- (e) --
path :: [Bool] -> BTree a -> [a]
path _ Empty = []
path [] (Node x _ _) = [x] 
path (h:t) (Node x l r) | h = x : path t r
                        | otherwise = x : path t l

-- (f) --
mirror :: BTree a -> BTree a
mirror Empty = Empty
mirror (Node x l r) = Node x (mirror r) (mirror l)  

-- (g) -- 
zipWithBT :: (a -> b -> c) -> BTree a -> BTree b -> BTree c 
zipWithBT f x Empty = x
zipWithBT f Empty y = y
zipWithBT f (Node x l1 r1) (Node y l2 r2) = Node (f x y) (zipWithBT f l1 l2) (zipWithBT r1 r2)    
 
