package View;

import Controller.Controller;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class AddContact {


    // Main Labels and TextFields

    @FXML
    public Label addContact_Name;
    public TextField addContact_NameInput;

    @FXML
    public Label addContact_Cellphone;
    public TextField addContact_CellphoneInput;

    @FXML
    public Label addContact_Telephone;
    public TextField addContact_TelephoneInput;

    @FXML
    public Label addContact_Address;
    public TextField addContact_AddressInput;

    @FXML
    public Label addContact_Skype;
    public TextField addContact_SkypeInput;

    // Confirm Button and events

    @FXML
    public Button addContact_ConfirmButton;

    @FXML
    public void confirmButtonPressed(ActionEvent event) throws Exception{

        List<String> info = new ArrayList<>();

        info.add(addContact_NameInput.getText());
        info.add(addContact_CellphoneInput.getText());
        info.add(addContact_TelephoneInput.getText());
        info.add(addContact_AddressInput.getText());
        info.add(addContact_SkypeInput.getText());

        View.controller.addContact(info);

        (new Contact()).buildContactInfo(info.get(0));
        View.redirectTo(SceneLoader.GUIFILE.ContactGUI);
    }

    // Back Button and events

    @FXML
    public Button addContact_BackButton;

    @FXML
    public void backButtonPressed(ActionEvent event) throws Exception{
        View.redirectTo(SceneLoader.GUIFILE.MainMenuGUI);
    }








}
