package Controller;


import Model.ContactList;
import Model.ContactListFacade;

public class Controller implements ControllerFacade{

    private ContactListFacade contactList;

    public Controller() {
        this.contactList = new ContactList();
    }


}
