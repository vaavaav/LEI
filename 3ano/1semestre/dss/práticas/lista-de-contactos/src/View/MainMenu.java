package View;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class MainMenu {
    @FXML
    public Button addContactButton;


    @FXML
    public void addContactButtonPressed(ActionEvent event) throws Exception{
        View.redirectTo(SceneLoader.GUIFILE.AddContactGUI);
    }

}
