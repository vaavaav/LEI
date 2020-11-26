import java.io.DataInputStream;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ContactList {
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
    
        public void getContacts (DataOutputStream output) throws IOException { 
            for(Contact c : contacts)
                c.serialize(output);
        }
    
}
