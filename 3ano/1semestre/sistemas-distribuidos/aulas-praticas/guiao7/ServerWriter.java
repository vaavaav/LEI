import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerWriter implements Runnable {
    private ContactList contactList;
    private ServerSocket ss;

    public ServerWriter(ServerSocket ss, ContactList c){
        this.contactList = c;
        this.ss = ss;
    }



    private class ContactWriter implements Runnable {
        private Socket socket;
        private ContactList c;
    
    
        public ContactWriter(Socket socket, ContactList contactList){
            this.socket = socket;
            this.c = contactList;
        }
    
        // @TODO
        @Override
        public void run() {

            try{
                DataOutputStream output = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
                this.c.getContacts(output);
                socket.shutdownInput();
                socket.close();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }



    public void run() {

        try {
            while(true){
                Socket socket = ss.accept();
                Thread contactWriter = new Thread(new ContactWriter(socket, this.contactList));
                contactWriter.start();
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


    }


    
}

