package View;

import Controller.Controller;
import Controller.ControllerFacade;
import javafx.application.Application;
import javafx.stage.Stage;

import java.io.IOException;


public class View extends Application {

    private static Stage primaryStage;
    public static ControllerFacade controller;

    @Override
    public void start(Stage primaryStage) throws Exception{
        View.primaryStage = primaryStage;
        View.controller = new Controller();
        View.primaryStage.setTitle("Contact List");
        redirectTo(SceneLoader.GUIFILE.MainMenuGUI);
    }

    public static void main(String[] args){
        launch(args);
    }


    static void redirectTo(SceneLoader.GUIFILE targetScene) throws IOException {
        View.primaryStage.setScene(SceneLoader.getScene(targetScene));
        View.primaryStage.show();
    }




}
