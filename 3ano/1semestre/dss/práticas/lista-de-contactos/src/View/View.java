package View;

import Controller.Controller;
import Controller.ControllerFacade;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class View extends Application{


    private ControllerFacade controller;
    private Stage window;
    private Scene mainMenuScene;
    private Label mainMenuLabel;
    private Button addContact;

    private Scene addContactGUI;
    private Label addContactLabel;

    public static void main(String args[]){
        launch(args);
    }


    @Override
    public void start(Stage primaryStage){

        this.controller = new Controller();

        this.window = primaryStage;
        primaryStage.setTitle("Contact List");

        // main menu
        mainMenuLabel = new Label("Main menu");
        VBox mainMenuLayout = new VBox(300);


            //buttons
            addContact = new Button("add a new contact");
            this.addContact.setOnAction(e -> window.setScene(addContactGUI));


        mainMenuLayout.getChildren().addAll(mainMenuLabel, addContact);
        mainMenuScene = new Scene(mainMenuLayout);

        //addContactGUI




        this.window.setScene(mainMenuScene);
        this.window.show();
    }


}
