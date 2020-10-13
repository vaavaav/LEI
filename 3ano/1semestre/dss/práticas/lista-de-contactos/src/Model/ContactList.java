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

    public void addContact(List<String> info)
    {
        this.contacts.put(info.get(0), new Contact(info));
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


    public List<String> getInfo(String name) throws NullPointerException{
        Contact maybeC = this.contacts.get(name);
        if(maybeC == null)
            throw new NullPointerException(name + " is not registered in the list.");
        return maybeC.getInfo();
    }

    public int size(){
        return this.contacts.size();
    }


    public void setInfo(String originName, List<String> info){
        Contact maybeC = this.contacts.get(originName);
        if(maybeC == null)
            throw new NullPointerException(originName + " is not registered in the list.");
        this.contacts.remove(originName);
        this.contacts.put(info.get(0), new Contact(info));

    }

    public void removeContact(String name){
        Contact maybeC = this.contacts.get(name);
        if(maybeC == null)
            throw new NullPointerException(name + " is not registered in the list.");
        this.contacts.remove(name);
    }


}
