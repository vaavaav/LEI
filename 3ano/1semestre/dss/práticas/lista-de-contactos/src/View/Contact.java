package View;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import java.util.List;

public class Contact {

    // Main Labels and TextFields

    @FXML
    public Label contact_Name;
    public Label contact_NameOutput;

    @FXML
    public Label contact_Cellphone;
    public Label contact_CellphoneOutput;

    @FXML
    public Label contact_Telephone;
    public Label contact_TelephoneOutput;

    @FXML
    public Label contact_Address;
    public Label contact_AddressOutput;

    @FXML
    public Label contact_Skype;
    public Label contact_SkypeOutput;

    public void buildContactInfo(String name){
        List<String> info = View.controller.getInfo(name);

        //janela de erro caso n encontre ou assim

        contact_NameOutput = new Label(info.get(0));
        contact_CellphoneOutput = new Label(info.get(1));
        contact_TelephoneOutput = new Label(info.get(2));
        contact_AddressOutput = new Label(info.get(3));
        contact_SkypeOutput = new Label(info.get(4));

    }



    // Remove Button and events

    @FXML
    public Button contact_RemoveButton;

    @FXML
    public void removeButtonPressed(ActionEvent event) throws Exception{

        View.controller.removeContact(contact_NameOutput.getText());

        View.redirectTo(SceneLoader.GUIFILE.MainMenuGUI);
    }


    // Back Button and events

    @FXML
    public Button contact_BackButton;

    @FXML
    public void backButtonPressed(ActionEvent event) throws Exception{
        View.redirectTo(SceneLoader.GUIFILE.MainMenuGUI);
    }

}
