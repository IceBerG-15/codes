package hellofx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class Main extends Application
{
    public void start() throws Exception
    {
        Parent root=FXMLLoader.load(getClass().getResource("hellofx.fxml"));
        primarystage.setTitle("HELLO WORLD");
        primarystage.setScene(new Scene(root,400,300));
        primarystage.show();
    }

    public static void main(String[] args)
    {
        launch(args);
        
    }
}
