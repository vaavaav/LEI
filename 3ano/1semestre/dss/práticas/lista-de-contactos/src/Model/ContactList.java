package Model;

import java.util.HashMap;
import java.util.List;

public class ContactList implements ContactListFacade {
    
    private HashMap<String, Contact> contacts;

    public ContactList(){
        this.contacts = new HashMap<>();
    }

    ContactList(HashMap<String, Contact> contacts){

        this.contacts = new HashMap<>();
        this.contacts.putAll(contacts);

    }

    public void addContact(Contact newContact){
        this.contacts.put(newContact.getInfoNumber(0), newContact);
    }

    public Contact getContact(String name){
        return new Contact(this.contacts.get(name));
    }

    public boolean hasInfo(String name){
        return this.contacts.get(name) != null;
    }

    public void setInfoNumber(String name, int n, String newInfo) throws NullPointerException{
        Contact maybeC = this.contacts.get(name);
        if(maybeC == null)
            throw new NullPointerException(name + " is not registered in the list.");
        else
            maybeC.setInfoNumber(n, newInfo);

    }

    public String getInfoNumber(String name, int n) throws NullPointerException{
        Contact maybeC = this.contacts.get(name);
        if(maybeC == null)
            throw new NullPointerException(name + " is not registered in the list.");
        return maybeC.getInfoNumber(n);
    }


    public Contact getInfo(String name) throws NullPointerException{
        Contact maybeC = this.contacts.get(name);
        if(maybeC == null)
            throw new NullPointerException(name + " is not registered in the list.");
        return maybeC.clone();
    }

    public int size(){
        return this.contacts.size();
    }



}
