import java.io.IOException;
import java.net.ServerSocket;


public class Server {

    public static final int readerPort = 12345;
    public static final int writerPort = 34567;

    public static void main (String[] args) throws IOException {
        ServerSocket ssReader = new ServerSocket(readerPort);
        ServerSocket ssWriter = new ServerSocket(writerPort);
        ContactList contactList = new ContactList();

        Thread serverReader = new Thread(new ServerReader(ssReader,contactList));
        Thread serverWriter = new Thread(new ServerWriter(ssWriter,contactList));

        serverReader.start();
        serverWriter.start();
     
    }

}