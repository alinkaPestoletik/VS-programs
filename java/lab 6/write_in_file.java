import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;

public class write_in_file {
    private static final String INPUT_FILE_PATH = "lab5/src/files/input.txt";
    private static final String OUTPUT_FILE_PATH = "lab5/src/files/output.txt";
    public static void main(String[] args) {
        copyFileContent(INPUT_FILE_PATH, OUTPUT_FILE_PATH);
    }

    private static void copyFileContent(String inputFilePath, String outputFilePath) {
        try (Reader in = new BufferedReader(new InputStreamReader(new FileInputStream(inputFilePath)));
            Writer out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputFilePath)))) {
            char[] cbuf = new char[2048];
            int length;
            while ((length = in.read(cbuf, 0, cbuf.length)) != -1) {
                out.write(cbuf, 0, length);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


