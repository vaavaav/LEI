package g8;
import java.io.IOException;
import java.net.Socket;


public class TaggedConnection extends FramedConnection{

    public TaggedConnection(Socket s) throws IOException{ super(s); }

    public void send(Frame f) throws IOException{
        this.send(f.tag, f.data);
    }


    public void send(int tag, byte[] data) throws IOException{
        super.writeLock.lock();
        super.out.writeInt(4 + data.length);
        super.out.writeInt(tag);
        super.out.write(data);
        super.out.flush();
        this.writeLock.unlock();
    }

    public Frame receiveFrame() throws IOException{
        this.readLock.lock();
        int size = this.in.readInt();
        int tag = this.in.readInt();
        byte[] b = new byte[size - 4];
        this.in.readFully(b);
        this.readLock.unlock();
        return new Frame(tag, b);
    }

    
    public static class Frame {
    
        public final byte[] data;
        public final int tag;

        public Frame(int tag, byte[] data){
            this.tag = tag;
            this.data = data;
        }
        
    }
}

