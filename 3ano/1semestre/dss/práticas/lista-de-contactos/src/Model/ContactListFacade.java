package Model;

import java.util.List;

public interface ContactListFacade {

    /**
     * Method to add a new contact to the contact list.
     * @param info information about the contact
     *                    0 - name
     *                    1 - cellphone number
     *                    2 - telephone number
     *                    3 - address
     *                    4 - skype number
     */
    void addContact(List<String> info);

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
     * @return the information (name and contacts) of the person.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    List<String> getInfo(String name) throws NullPointerException;


    /**
     * Method to change the information (name included) of a person.
     * @param originName name of the person before any possible change.
     * @param info information about the person.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    void setInfo(String originName, List<String> info) throws NullPointerException;

    /**
     * Method to get the size of the contact list.
     * @return the size to contact list (0..).
     */
    int size();

    /**
     * Method to remove a contact.
     * @param name name of the person.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    void removeContact(String name) throws NullPointerException;







}
