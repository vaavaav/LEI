-- | Este módulo define funções comuns da Tarefa 1 do trabalho prático.
module Tarefa1_2018li1g156 where

import Tarefa0_2018li1g156

import LI11819

-- * Testes

-- | Testes unitários da Tarefa 1.
--
-- Cada teste é uma sequência de 'Instrucoes'.
testesT1 :: [Instrucoes]
testesT1 = [teste1, teste2, teste3, teste4]

teste1 = [Move D, Desenha, Move B, Move B, Move B, Roda, MudaParede, Move D, Move D, Move D, Desenha, Move B]
teste2 = [Move D,Move D,Move D,Move D,Move B,Move B,Move B,Move B,Move D,Move B,Move D,Move B,Move D,Move B,Move D,
             Move B,Desenha,Move C,Move C,Move C,Move C,Move C,Move C,Move C,Move C,Desenha,Move E,Move E,Move E,Move E,
             Move E,Move E,Move E,Move E,Move D,Move E,Desenha,Move B,Move B,Move B,Move B,Move B,Roda,Move D,Move C,
             Move D,Move D,Move C,Move C,Move E,Desenha,Move B,Move B,Move B,Move B,Move B,Move B,Move E,Move E,
             Desenha,Move C,Move C,Move C,Roda,Move D,Move D,Move B,Desenha,Move E,Move E,Move E,Move E]
teste3 = [Move D,Move D,Move D,Move D,Move D,Move B,Move B,Move B,Move B,Move B,Move B,Move E,Move E,Move C,Move C,
          Move E,Move C,Move C,Move C,Move C,Desenha,Move D,Move D,Move D,Move B,Move B,Move D,Move D,Move D,Move D,Move E,Roda,
          Roda,Roda,MudaTetromino,MudaTetromino,Move C,Move C,Desenha,Move B,Move B,Move B,Move B,Desenha,Move B,Move B,Move B,
          Move B,Move B,Move B,Move B,Move E,Move E,Move E,Move E,Roda,MudaTetromino,Move E,Move C,Move C,Move D,Move D,Move D,Move E,
          Move E,Move E,Desenha,Move D,Move D,Move D,Move D,MudaParede,Desenha,Move C,Move C,Move E,Move C,Move C,Move D,Move C,Move D,
          Move D,Desenha,Move E,Move E,Move E,Move E,Move E,Move C,Move C,Move C,Move C,Move C,Move C,Move C,Move C,Move C,Move E,Move E,
          Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move E,Move B,Move B,Move B,Move B,
          Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move B,Move D,
          Move D,Move D,Move D,Move D,Move C,Move C,Move C,Move C,Desenha,Move C,Move C,Move C,Move C,Move C,Move C,Move D,Move D,Desenha,Move C,Move C,
          Move C,Move C,Move C,Move C,Roda,MudaTetromino,MudaTetromino,MudaTetromino,MudaTetromino,Desenha,Move C,MudaParede,Move D,Move D,Move D,
          Move B,Move D,Desenha,Move E,Move E,Move E,Move E,Move E,Move C,Move C,Move C,Desenha,Move B,Roda,Move B,Desenha,Move B,Move B,Move B,Move B,
          Move B,Move B,Desenha,Move B,Move B,Move B,Roda]
teste4 = [Move D,Move D,Move B,Move B,Move B,Move B,Move D,Move D,Move D,Move D,Move D,Move D,Move B,Move B,Move B,Move E,Move C,Move E,Move E,Move C,Move C,
          Move C,Move C,Move C,Move C,Desenha,Move B,Move B,Move B,Move B,Desenha,Move E,Roda,Move E,MudaParede,Desenha,Move B,Move B,Move B,Move B,Move B,Move B,
          Move B,Move B]

-- * Funções principais da Tarefa 1.

-- | Aplica uma 'Instrucao' num 'Editor'.
--
--    * 'Move' - move numa dada 'Direcao'.
--
--    * 'Roda' - roda 90º no sentido dos ponteiros dos relógios.
--
--    * 'MudaTetromino' - seleciona a 'Peca' seguinte (usar a ordem léxica na estrutura de dados),
--       sem alterar os outros parâmetros.
--
--    * 'MudaParede' - muda o tipo de 'Parede'.
--
--    * 'Desenha' - altera o 'Mapa' para incluir o 'Tetromino' atual, sem alterar os outros parâmetros.
instrucao :: Instrucao -- ^ A 'Instrucao' a aplicar.
          -> Editor    -- ^ O 'Editor' anterior.
          -> Editor    -- ^ O 'Editor' resultante após aplicar a 'Instrucao'.
instrucao i edi@(Editor pos dire tet prd _) = case i of
                                     Move d -> edi {posicaoEditor = somaVetores pos (direcaoParaVetor d)}
                                     Roda | dire == E -> edi {direcaoEditor = C}
                                          | otherwise -> edi {direcaoEditor = succ dire}
                                     MudaTetromino | tet == Z -> edi {tetrominoEditor = I}
                                                   | otherwise -> edi {tetrominoEditor = succ tet} 
                                     MudaParede | prd == Indestrutivel -> edi {paredeEditor = Destrutivel}
                                                | otherwise -> edi {paredeEditor = Indestrutivel}                                                     
                                     Desenha -> desenhaTetromino edi t ((fst . dimensaoMatriz) t) (0,0)
                                             where t = tetrominoReal (tetrominoParaMatriz tet) dire

-- | Roda uma 'Matriz' 'Bool' (do 'Tetromino'), dada uma 'Direcao'.

tetrominoReal :: Matriz Bool -- ^ A 'Matriz' 'Bool' anterior.
              -> Direcao     -- ^ A 'Direcao' a aplicar.
              -> Matriz Bool -- ^ A 'Matriz' 'Bool' resultante.
tetrominoReal t C = t
tetrominoReal t d = rodaMatriz $ tetrominoReal t $ pred d


-- | Função auxiliar que atualiza no 'mapaEditor', os elementos 'True' da 'Matriz' 'Bool', em 'Bloco' 'Parede' considerando as várias propriedades do 'Editor'.

desenhaTetromino :: Editor      -- ^ O 'Editor' anterior.
                 -> Matriz Bool -- ^ A 'Matriz' 'Bool' do 'tetrominoEditor' e com a direção 'direcaoEditor'.
                 -> Int         -- ^ A ordem da 'Matriz' 'Bool'.
                 -> Posicao     -- ^ A posição na 'Matriz' 'Bool'.
                 -> Editor      -- ^ O 'Editor' resultante. 
desenhaTetromino edi@(Editor (x,y) _ _ prd m) tetromino ordem (l,c) | l == ordem = edi
                                                                    | c == ordem = desenhaTetromino edi tetromino ordem (l+1, 0)  
                                                                    | otherwise = desenhaTetromino (if elemTet then edi{mapaEditor = newMapa} else edi) tetromino ordem (l,c+1)
                                                      where elemTet = encontraPosicaoMatriz (l,c) tetromino
                                                            newMapa = atualizaPosicaoMatriz (x+l,y+c) (Bloco prd) m

-- | Aplica uma sequência de 'Instrucoes' num 'Editor'.
--
-- __NB:__ Deve chamar a função 'instrucao'.
instrucoes :: Instrucoes -- ^ As 'Instrucoes' a aplicar.
           -> Editor     -- ^ O 'Editor' anterior.
           -> Editor     -- ^ O 'Editor' resultante após aplicar as 'Instrucoes'.
instrucoes [] edi = edi             
instrucoes (h:t) edi = instrucoes t $ instrucao h edi 

-- | Cria um 'Mapa' inicial com 'Parede's nas bordas e o resto vazio.
mapaInicial :: Dimensao -- ^ A 'Dimensao' do 'Mapa' a criar.
            -> Mapa     -- ^ O 'Mapa' resultante com a 'Dimensao' dada.
mapaInicial (l,c) = map ((++ [Bloco Indestrutivel]) . (Bloco Indestrutivel:)) ((replicate (c-2) (Bloco Indestrutivel)) : criaMatriz (l-2, c-2) Vazia ++ [replicate (c-2) (Bloco Indestrutivel)])   

-- | Cria um 'Editor' inicial.
--
-- __NB:__ Deve chamar as funções 'mapaInicial', 'dimensaoInicial', e 'posicaoInicial'.
editorInicial :: Instrucoes  -- ^ Uma sequência de 'Instrucoes' de forma a poder calcular a  'dimensaoInicial' e a 'posicaoInicial'.
              -> Editor      -- ^ O 'Editor' inicial, usando a 'Peca' 'I' 'Indestrutivel' voltada para 'C'.
editorInicial l = Editor  { posicaoEditor = posicaoInicial l
                          , direcaoEditor = C
                          , tetrominoEditor = I
                          , paredeEditor = Indestrutivel
                          , mapaEditor = mapaInicial $ dimensaoInicial l
                          }

-- | Constrói um 'Mapa' dada uma sequência de 'Instrucoes'.
--
-- __NB:__ Deve chamar as funções 'Instrucoes' e 'editorInicial'.
constroi :: Instrucoes -- ^ Uma sequência de 'Instrucoes' dadas a um 'Editor' para construir um 'Mapa'.
         -> Mapa       -- ^ O 'Mapa' resultante.
constroi l = mapaEditor $ instrucoes l $ editorInicial l 