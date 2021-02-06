package g8;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;


public class FramedConnection implements AutoCloseable{

    protected Socket socket;
    protected DataInputStream in;
    protected DataOutputStream out;
    protected ReentrantLock readLock;
    protected ReentrantLock writeLock;

    public FramedConnection(Socket s) throws IOException{
        this.socket = s;
        this.in = new DataInputStream(socket.getInputStream()); 
        this.out = new DataOutputStream(socket.getOutputStream());
        this.readLock = new ReentrantLock();
        this.writeLock = new ReentrantLock(); 
    }

    public void send(byte[] b) throws IOException{
        
        this.out.writeInt(b.length);
        this.out.write(b);
        this.out.flush();
    }

    public byte[] receive() throws IOException{
        int size = this.in.readInt();
        byte[] b = new byte[size];
        this.in.readFully(b);
        return b;
    }

    public void close() throws IOException{
        this.in.close();
        this.out.close();
        socket.close();
    }
    
}


