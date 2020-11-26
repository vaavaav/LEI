import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ClientReader {

    public static void main (String[] args) throws IOException {
        Socket socket = new Socket("localhost", 34567);

        DataInputStream in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));

        boolean isOpen = true;

        while(isOpen){
            try{
                Contact newContact = Contact.deserialize(in);
                System.out.println(newContact.toString() + "\n\n");
            }
            catch(EOFException eof){
                isOpen = false;
            }
        }
            
        socket.close();
    }
}