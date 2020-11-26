import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerReader implements Runnable {
    private ContactList contactList;
    private ServerSocket ss;

    public ServerReader(ServerSocket ss, ContactList c){
        this.contactList = c;
        this.ss = ss;
    }



    private class ContactReader implements Runnable {
        private Socket socket;
        private ContactList c;
    
    
        public ContactReader(Socket socket, ContactList contactList){
            this.socket = socket;
            this.c = contactList;
        }
    
        // @TODO
        @Override
        public void run() {
    
            
            boolean isOpen = true;
            try{
                DataInputStream input = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                while(isOpen){
                    try{
                        this.c.addContact(input);
                    }
                    catch(EOFException eof){
                        isOpen = false;
                    }
                }
    
                socket.shutdownInput();
                socket.close();
    
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
    }



    public void run() {

        try {
            while(true){
                Socket socket = this.ss.accept();
                Thread contactReader = new Thread(new ContactReader(socket, this.contactList));
                contactReader.start();
    
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


    }
    
}
