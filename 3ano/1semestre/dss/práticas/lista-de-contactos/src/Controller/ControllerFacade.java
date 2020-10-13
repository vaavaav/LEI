package Controller;

import java.util.List;

public interface ControllerFacade {

    /**
     * Method to add a new contact to the list.
     * @param info Information about the person:
     *             0 - Name
     *             1 - Cellphone number
     *             2 - Telephone number
     *             3 - Address
     *             4 - Skype number
     */
    void addContact(List<String> info);

    /**
     * Method to get the number of contacts in the list.
     * @return the size of the list.
     */
    int getContactListSize();

    /**
     * Method to check if there's any entry about a person.
     * @param name name of the person.
     * @return true if there's any entry associated with the given name.
     */
    boolean hasInfo(String name);

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
    void editContact(String originName, List<String> info) throws NullPointerException;

    /**
     * Method to remove a contact.
     * @param name name of the person.
     * @throws NullPointerException if there's no entry associated with the name.
     */
    void removeContact(String name) throws NullPointerException;


}
