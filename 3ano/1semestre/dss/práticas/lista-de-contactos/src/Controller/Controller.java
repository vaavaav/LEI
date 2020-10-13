package Controller;


import Model.ContactList;
import Model.ContactListFacade;

import java.util.ArrayList;
import java.util.List;

public class Controller implements ControllerFacade{

    private ContactListFacade contactList;

    public Controller() {
        this.contactList = new ContactList();
    }

    public void addContact(List<String> info){
        this.contactList.addContact(info);
    }

    public int getContactListSize(){
        return this.contactList.size();
    }

    public boolean hasInfo(String name){
        return this.contactList.hasInfo(name);
    }

    public List<String> getInfo(String name){
        return this.contactList.getInfo(name);
    }


    public void editContact(String originName, List<String> info) throws NullPointerException{
        this.contactList.setInfo(originName, info);
    }

    public void removeContact(String name) throws NullPointerException{
        this.contactList.removeContact(name);
    }

}
