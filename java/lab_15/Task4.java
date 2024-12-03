import java.lang.reflect.Method;
import java.util.Arrays;

public class Task4 {
    public static void main(String[] args) {
        Class<?> cls = Code.class;
        Method[] methods = cls.getDeclaredMethods();
        for (Method method : methods)
            System.out.println(method.getReturnType() + " "
            + method.getName() + " "
            + Arrays.toString(method.getParameterTypes()));
    }
}

class Code{
    // a private field
    private String value;

    // a public constructor
    public Code() { value = "Nothing is there yet"; }

    // getter for value
    public String getValue() {
        return value;
    }

    // setter for value
    public void setValue(String newValue) {
        value = newValue;
    }

    // private method
    private void printToTerminal() {
        System.out.println(value);
    }
}
