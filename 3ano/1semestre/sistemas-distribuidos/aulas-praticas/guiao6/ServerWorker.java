import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.lang.Runnable;

public class ServerWorker implements Runnable {

    private Socket socket;
    private Registo r;

    ServerWorker(Socket s, Registo r){
        this.socket = s;
        this.r = r;
    }

    public void run(){
        try{
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream());

            //exercicio 1
            String line;
            int aux = 0;
            int sum = 0;
            while ((line = in.readLine()) != null) {
                try {
                    aux = Integer.parseInt(line);
                    sum += aux;
                    r.addNum(aux);
                    
                }catch (NumberFormatException e) {}
                out.println(sum);
                out.flush();
            }
            out.println(r.getAverage());
            out.flush();
            socket.shutdownOutput();
            socket.shutdownInput();
            socket.close();
    } catch (IOException e) {
        e.printStackTrace();
    }
    }
}