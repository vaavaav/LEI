import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class EchoServer {

    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(12345);
            Registo r = new Registo();

            while (true) {
                Socket socket = ss.accept();

                Thread t = new Thread(new ServerWorker(socket, r));
                t.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}