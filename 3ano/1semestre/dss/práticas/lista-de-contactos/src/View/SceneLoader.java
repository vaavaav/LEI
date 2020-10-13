package View;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;

import java.io.IOException;
import java.util.HashMap;
import java.util.Objects;

class SceneLoader {

    private static HashMap<String, Scene> scenes;

    public static Scene getScene(GUIFILE target_scene) throws IOException, NullPointerException {
        Scene target;
        String target_name = target_scene.getPath();

        if(scenes == null)
            scenes = new HashMap<>();
        if((target = scenes.get(target_name)) == null) {
            scenes.put(target_name, new Scene(FXMLLoader.load(Objects.requireNonNull(SceneLoader.class.getClassLoader().getResource(target_name)))));
            target = scenes.get(target_name);
        }

        return target;
    }



    enum GUIFILE {

        MainMenuGUI("Resources/mainMenu.fxml"),
        AddContactGUI("Resources/addContact.fxml"),
        ContactGUI("Resources/contact.fxml"),
        ;

        private final String path;


        GUIFILE(String path){
            this.path = path;
        }

        private String getPath() {
            return this.path;
        }

    }

}
