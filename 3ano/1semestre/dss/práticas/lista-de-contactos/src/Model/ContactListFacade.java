package Model;

import java.util.List;

public interface ContactListFacade {

    /**
     * Method to add a new contact to the contact list.
     * @param newContact
     */
    void addContact(Contact newContact);

    /**
     * Method to get a contact by giving a person's name.
     * @param name name of the person.
     * @return the person's contact or null if there's no entry associated with the name.
     */
    Contact getContact(String name);

    /**
     * Method to check if there's any information (contacts) of a person.
     * @param name name of the person.
     * @return true if there's any entry associated with the name.
     */
    boolean hasInfo(String name);

    /**
     * Method to set (or change) a specific information about a person.
     * @param name name of the person.
     * @param n the specific information to be changed (see numbers of the different information types).
     * @param newInfo the new information to be set or changed with.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    void setInfoNumber(String name, int n, String newInfo) throws NullPointerException;

    /**
     * Method to get a specific information about a person.
     * @param name name of the person.
     * @param n the specific information to get.
     * @return the information requested.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    String getInfoNumber(String name, int n) throws NullPointerException;

    /**
     * Method to get the information (contacts) of a person.
     * @param name name of the person.
     * @return the contact of the person.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    Contact getInfo(String name) throws NullPointerException;

    /**
     * Method to get the size of the contact list.
     * @return the size to contact list (0..).
     */
    int size();







}
