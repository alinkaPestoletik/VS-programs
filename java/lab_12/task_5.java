import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.nio.charset.MalformedInputException;

public class task_5 {
    public static void main(String[] args) {
        saveImage("https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Promenade_des_Anglais%2C_Nice.jpg/1200px-Promenade_des_Anglais%2C_Nice.jpg");
    }

    public static void saveImage(String imageUrl) { 
        try{
            URL url = new URL(imageUrl);
            String fileName = url.getFile();
            String destName = "C:/Users/Alina/Desktop/books" + fileName.substring(fileName.lastIndexOf("/"));

            InputStream is = url.openStream();
            OutputStream os = new FileOutputStream(destName);

            byte[] b = new byte[2048];
            int length;
            while ((length = is.read(b)) != -1) {
                os.write(b, 0, length);
            }

            is.close();
            os.close();
        }

        catch (MalformedInputException ex){
            System.out.println('1');
            System.out.println(ex.getMessage());
        }
        
        catch(IOException ex){
            System.out.println('2');
            System.out.println(ex.getMessage());
        }
    }

}

