import Graphics.UI.GLUT
import Graphics.Rendering.OpenGL
import Data.IORef

main :: IO ()
main = do
  -- put GLUT init here
  (_progName, _args) <- getArgsAndInitialize 
  initialDisplayMode $= [DoubleBuffered,WithDepthBuffer]
  _window <- createWindow "CG@DI"

  -- value by ref
  x <- newIORef 0.0
  time <- newIORef 0.0

  -- put callback registry here         
  displayCallback $= renderScene x
  reshapeCallback $= Just resize
  idleCallback $= Just (idle x time)

  -- some OpenGL settings
  depthFunc $= Nothing
  cullFace $= Nothing

  mainLoop


idle :: IORef Double -> IORef Double -> IdleCallback
idle x time = do
  timeV <- readIORef time
  ntimeV <- fromIntegral <$> elapsedTime
  x `modifyIORef` (+ (ntimeV - timeV)/500)
  time `modifyIORef` (const ntimeV)
  postRedisplay Nothing


renderScene :: IORef Double -> DisplayCallback
renderScene size = do 
  size' <- readIORef size  -- *size

  -- clear buffers
  clear [ColorBuffer,DepthBuffer]

  -- set camera
  loadIdentity
  lookAt 
        (Vertex3 (0::GLdouble) (0::GLdouble) (5::GLdouble)) 
        (Vertex3 (0::GLdouble) (0::GLdouble) ((-1)::GLdouble)) 
        (Vector3 (0::GLdouble) (1::GLdouble) (0::GLdouble))

  -- put drawing instructions here
  renderObject Wireframe $ Teapot ((sin size')) -- render objec


  
  --  End of frame
  swapBuffers         
  
resize :: ReshapeCallback
resize size@(Size w h) = do
  
  --  Prevent a divide by zero, when window is too short
  -- (you cant make a window with zero width).
  let h' = fromIntegral(if(h == 0) then 1 else h) :: Double
  let w' = fromIntegral(w) :: Double
  let ratio = w' /  h'

  -- compute window's aspect ratio
  matrixMode $= Projection

  -- Load the identity matrix
  loadIdentity

  -- Set the viewport to be the entire window
  viewport $= (Position 0 0, size)

  -- Set the projection matrix as current
  perspective 45 ratio 1 1000

  -- return to the model view matrix mode
  matrixMode $= Modelview 0
  
  postRedisplay Nothing
  