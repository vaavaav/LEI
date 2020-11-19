import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.locks.ReentrantReadWriteLock;

import jdk.internal.org.jline.reader.EOFError;


class ContactList {
    private List<Contact> contacts;
    private ReentrantReadWriteLock lock = new ReentrantReadWriteLock();

    public ContactList() {
        contacts = new ArrayList<>();

        contacts.add(new Contact("John", 20, 253123321, null, new ArrayList<>(Arrays.asList("john@mail.com"))));
        contacts.add(new Contact("Alice", 30, 253987654, "CompanyInc.", new ArrayList<>(Arrays.asList("alice.personal@mail.com", "alice.business@mail.com"))));
        contacts.add(new Contact("Bob", 40, 253123456, "Comp.Ld", new ArrayList<>(Arrays.asList("bob@mail.com", "bob.work@mail.com"))));
    }

    public boolean addContact (DataInputStream input) throws IOException {
        this.lock.writeLock().lock();
        Contact newContact = Contact.deserialize(input);
        this.contacts.add(newContact);
        this.lock.writeLock().unlock();
        return true;
    }

    public void getContacts () throws IOException { 
    }
    
}

class ServerWorker implements Runnable {
    private Socket socket;
    private ContactList c;


    public ServerWorker (Socket socket, ContactList contactList) throws IOException{
        this.socket = socket;
        this.c = contactList;
    }

    // @TODO
    @Override
    public void run() {

        DataInputStream input = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        DataOutputStream output = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));

        boolean isOpen = true;
        try{
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


public class Server {

    public static void main (String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(12345);
        ContactList contactList = new ContactList();

        while (true) {
            Socket socket = serverSocket.accept();
            Thread worker = new Thread(new ServerWorker(socket, contactList));
            worker.start();
        }
    }

}