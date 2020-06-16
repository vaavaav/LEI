-- | Este módulo define funções comuns da Tarefa 3 do trabalho prático.
module Tarefa3_2018li1g156 where

import LI11819
import Tarefa0_2018li1g156
import Tarefa1_2018li1g156
import Tarefa2_2018li1g156

-- * Testes

-- | Testes unitários da Tarefa 3.
--
-- Cada teste é um 'Estado'.
testesT3 :: [Estado]
testesT3 = [Estado (constroi teste2) ljogs1 ldps1, Estado (constroi teste4) ljogs2 ldps2]

-- * Funções principais da Tarefa 3.

-- | Comprime um 'Estado' para formato textual.
--
-- __NB:__ A função 'show' representa um 'Estado' num formato textual facilmente legível mas extenso.
--
-- __NB:__ Uma boa solução deve representar o 'Estado' dado no mínimo número de caracteres possível.
comprime :: Estado -> String
comprime (Estado m jgs dps) = (unwords ( map (codificaEmChar . divideEm6Char 0) (abc m)) ++ ('.':converteListaJogadores jgs) ++ ('.':converteListaDisparos dps))

-- | Codifica um 'Mapa' numa lista de 'String'.

abc :: Mapa     -- ^ 'Mapa' em questão. 
    -> [String] -- ^ Lista de 'String' final.
abc [] = []
abc m = map converteListaMapa ((take (fst (dimensaoMatriz m) - 2) . (drop 1)) (map (take (snd (dimensaoMatriz m) - 2) . (drop 1))  m))

-- | Divide uma 'String' numa lista de 'String' em que cada elemento contém 6 carateres.

divideEm6Char :: Int      -- ^ 'Int' pretendido.
              -> String   -- ^ 'String' em causa.
              -> [String] -- ^ Lista de 'String' resultante.
divideEm6Char _ [] = []
divideEm6Char _ [h] = [[h]]
divideEm6Char n (h:t) | n == 5 = [h]:divideEm6Char 0 t
                      | otherwise = (h:h1):t1
                      where (h1:t1) = divideEm6Char (n+1) t

-- | Transforma uma lista de 'String' numa 'String' convertendo números em carateres.

codificaEmChar :: [String] -- ^ Lista 'String' a converter.
               -> String   -- Resultado final.
codificaEmChar [] = []
codificaEmChar (s:ls) = (toEnum (read s :: Int):: Char) : codificaEmChar ls

-- | Codifica uma lista de 'Peca' numa 'String'.

converteListaMapa :: [Peca] -- ^ Lista de 'Peca' em causa.
                  -> String -- ^ 'String' tipo código resultante.
converteListaMapa [] = ""
converteListaMapa (h:t) = case h of
                        Vazia -> '1':converteListaMapa t             
                        Bloco Indestrutivel -> '3':converteListaMapa t  
                        Bloco Destrutivel -> '2':converteListaMapa t

-- | Comprime uma lista de 'Jogador' em 'String'.

converteListaJogadores :: [Jogador] -- ^ Lista de 'Jogador' em questão.
                       -> String    -- ^ 'String' resultante.
converteListaJogadores [] = []
converteListaJogadores (h:t) = hString ++ converteListaJogadores t
                    where hString = "J" ++ unwords [show x , show y , show (direcaoJogador h), show (vidasJogador h) , show (lasersJogador h) , show (choquesJogador h)]
                          (x,y) = posicaoJogador h 

-- | Comprime uma lista de 'Disparo' em 'String'.

converteListaDisparos :: [Disparo] -- ^ Lista de 'Disparo' em causa.
                      -> String    -- ^ 'String' final.
converteListaDisparos [] = []
converteListaDisparos (h:t) = case h of
                       DisparoChoque n ti -> "dX" ++ unwords [show n , show ti] ++ converteListaDisparos t
                       DisparoLaser a (x,y) c -> "dL" ++ unwords [show a , show x , show y , show c] ++ converteListaDisparos t
                       DisparoCanhao a (x,y) c -> "dC" ++ unwords [show a , show x , show y , show c] ++ converteListaDisparos t

-- | Descomprime um 'Estado' no formato textual utilizado pela função 'comprime'.
--
-- __NB:__ A função 'comprime' é válida de for possível recuperar o 'Estado' utilizando a função 'descomprime', i.e.:
--
-- prop> descomprime . comprime = id
--
-- __NB:__ Esta propriedade é particularmente válida para a solução pré-definida:
--
-- prop> read . show = id
descomprime :: String -> Estado
descomprime x = Estado {
                       mapaEstado = constroiMapa (mapaInicial dim) (0,0) dim mDes,
                       jogadoresEstado = (map (criaJogador) . drop 1) (separador j 'J'),
                       disparosEstado = criaDisparos (drop 1 (separador d 'd'))
                       }
               where dim = (l + 2, (div e l) +2)
                     (l,e) = calculaDimensao mDes
                     mDes = descodificaMapa m
                     [m, j, d] = separador x '.'

-- | Transforma 'Char' to 'Int'

descodificaMapa :: String -- ^ 'String' em causa
                -> String -- ^ 'String' obtida
descodificaMapa [] = []
descodificaMapa (h:t) | h == ' ' = h : descodificaMapa t 
                      | otherwise = show(fromEnum h) ++ (descodificaMapa t)

-- | Descodifica uma 'String' numa 'Dimensao'.

calculaDimensao :: String    -- ^ 'String' em causa.
                -> (Int,Int) -- ^ 'Dimensao' resultante.
calculaDimensao [] = (1,0) 
calculaDimensao (h:t) | h == ' ' = (l+1,e)
                      | otherwise = (l, e+1)
                    where (l,e) = calculaDimensao t


-- | Converte uma 'String' em 'Mapa'.

constroiMapa :: Mapa     -- ^ 'Mapa' inicial .
             -> Posicao  -- ^ Primeira 'Posicao' do 'Mapa'.
             -> Dimensao -- ^ 'Dimensao' do 'Mapa'.
             -> String   -- ^ 'Mapa' codificado em 'String'.
             -> Mapa     -- ^ 'Mapa' resultante.
constroiMapa _ (_,_) (0,_) [] = []
constroiMapa _ (_,_) (_,0) [] = []
constroiMapa m (_,_) (_,_) [] = m 
constroiMapa m (x,y) (l,c) (h:t) | x == l - 2 = m
                                 | y == c - 2 = constroiMapa m (x+1,0) (l,c) t 
                                 | h == '1' = constroiMapa m (x,y+1) (l,c) t
                                 | otherwise = constroiMapa newMap (x,y+1) (l,c) t
                                 where newMap = atualizaPosicaoMatriz (x+1,y+1) elem m 
                                       elem = if h == '2' then Bloco Destrutivel else Bloco Indestrutivel

-- | Descodifica uma 'String' num 'Jogador' com as respetivas propriedades.

criaJogador :: String  -- ^ 'String' em questão.   
            -> Jogador -- ^ 'Jogador' obtido.
criaJogador s = Jogador { posicaoJogador = (read x :: Int , read y :: Int) ,
                          direcaoJogador = read d :: Direcao,
                          vidasJogador = read v :: Int ,
                          lasersJogador = read l :: Int,
                          choquesJogador = read c :: Int}
              where [x,y,d,v,l,c] = separador s ' '

-- | Converte uma lista de 'String' numa lista de 'Disparo' com as respetivas propriedades para cada tipo de 'Disparo'.

criaDisparos :: [String]  -- ^ Lista de 'String' a tratar.
             -> [Disparo] -- ^ Lista de 'Disparo' originada.
criaDisparos [] = []
criaDisparos ((h:hs):t) = case h of
                       'X' -> DisparoChoque { jogadorDisparo = read n :: Int , 
                                           tempoDisparo = read ti :: Ticks } : criaDisparos t
                              where [n,ti] = separador hs ' '
                       'L' -> DisparoLaser { jogadorDisparo = read n :: Int,
                                          posicaoDisparo = (read x :: Int, read y :: Int),
                                          direcaoDisparo = read c :: Direcao } : criaDisparos t
                              where [n,x,y,c] = separador hs ' '
                       'C' -> DisparoCanhao { jogadorDisparo =  read n :: Int,
                                            posicaoDisparo = (read x :: Int, read y :: Int),
                                            direcaoDisparo = read c :: Direcao } : criaDisparos t
                              where [n,x,y,c] = separador hs ' '  

-- | Separa uma 'String' numa lista de 'String' separando-as quando encontra um dado 'Char'.

separador :: String   -- ^ 'String' em causa.
          -> Char     -- ^ 'Char' onde é separada.
          -> [String] -- ^ Lista de 'String' resultante.
separador [] _ = [""]
separador [h] k = if (h == k) then ["",""] else [[h]]
separador (h:i:t) k | h == k = "" : separador (i:t) k
                    | otherwise = (h : h1) :t1
                  where (h1:t1) = separador (i:t) k

-- A compressão de ficheiros reduz a quantidade de espaço necessário para o armazenamento de Data. O uso de ficheiros comprimidos permite libertar espaço valioso numa Hard Drive. Alguns ficheiros, por exemplo .doc, podem ser comprimidos até 90% do seu tamanho original.
-- O objetivo da tarefa 3 era comprimir, o máximo possível, um ‘Estado’ para um ‘String’, de forma a se conseguir descomprimir posteriormente. Para isso, utilizaram-se as funções ‘comprime’ e ‘descomprime’, respetivamente. O nosso objetivo inicial foi o de conseguir comprimir de forma estruturada e bem definida, e só posteriormente, maximizar a taxa de compressão obtida.
-- A primeira estratégia adotada foi estruturar o ‘Estado’ comprimido em 4 partes (separadas por ‘.’): 
-- Dimensão do ‘mapaEstado’;
-- ‘mapaEstado’: Retiravam-se as bordas do mapa, pois era informação desnecessária uma vez que os mapas têm sempre bordas constituídas por ‘Bloco Indestrutível’. A seguir, através da função ‘converteListaMapa’ convertiam-se todas as linhas do ‘Mapa’ em ‘String’ (ficando-se assim com ‘[String]’). 
-- OBS: O ‘Bloco’ ficaram associados a números do tipo ‘String’ (‘Vazia’ com “0”, ‘Bloco’ ‘Destrutivel’ com “1”, ‘Bloco’ ‘Indestrutivel’ com “2”). O ‘Mapa’ = [] ficou associado com “”.
-- ‘jogadoresEstado’: Através da função ‘converteListaJogadores’ Os jogadores eram separados por “J” e todas as informações sobre o jogador apareciam a seguir, pela ordem definida (posição x – posição y – direção – vidas – lasers – choques, cada componente separadas por espaços (“ “)).
-- ‘disparosEstado’: Através da função ‘converteListaDisparo’ cada ‘Disparo’ era separado por um indentificador (“dX”, “dL” ou “dC”, respetivamente, ‘disparoChoque’, ‘disparoLaser’ ou “disparoCanhao”) e também as informações de cada disparo apareciam, pela ordem definida, (jogador que disparou – posição x – posição y – direção, ou, para caso dos choques, jogador que disparou – tempo de disparo) 
-- Na função ‘descomprime’, recorriam-se a funções “inversas” das funções auxiliares usadas na ‘comprime’, sendo que estas recorriam ainda à função ‘read’ que lê a lista de ‘String’ originada através da compressão realizada. 
-- A segunda estratégia, de forma a maximizar a taxa de compressão, diminuiu-se a ‘String’ sobre o ‘Mapa’. Para isto, recorreu-se aos caracteres especiais começados por '/’, através das funções ‘divideEm6Char’ e ‘codificaEmChar’. De forma inversa, utiliza-se a função ‘descodificaMapa’. Observou-se ainda que era possível omitir a dimensão do ‘Mapa’ na ‘String’, podendo esta ser calculada posteriormente, para tal usa-se a função ‘calculaDimensao’.
-- Em conclusão, observou-se um crescimento de mais de 4% na taxa de compressão com a segunda estratégia, evidenciando-se um grande potencial no uso dos caracteres especiais. O aspeto negativo é na leitura, uma vez que comprimido é quase impossível fazer uma leitura do mapa, mas visto que serve para armazenamento, o problema não é muito relevante. O resultado final foi bastante do nosso agradado, fruto de um bom trabalho em equipa.