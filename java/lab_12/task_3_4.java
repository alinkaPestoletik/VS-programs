import java.io.*;
public class task_3_4 {
    public static void main(String[] args) {
        Throwable firstException = null;
        String[] numbers = {};
        try(FileInputStream in = new FileInputStream("input.txt");
        FileOutputStream out = new FileOutputStream("output.txt")) {

            byte[] buffer = new byte[in.available()];
            in.read(buffer);
            String number = new String(buffer);
            numbers = number.split(" ");

            if (Double.parseDouble(numbers[1]) == 0.0) {
                throw new ArithmeticException("Cannot be divided by zero");
            }
        }

        catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        
        catch (ArithmeticException ex) {
            firstException = ex;
            System.out.println(ex.getMessage());
        }

        finally {
            try {
                if (numbers.length != 2)
                { throw new AmountOfIntegersException(); }
    
                boolean integer = valid(numbers);
                if (!(integer))
                { throw new TypeExpection(); }
    
                else {
                    double answer = Double.parseDouble(numbers[0]) / Double.parseDouble(numbers[1]);
                    System.out.println(answer);
                }
            } 
    
            catch (AmountOfIntegersException ex) {
                if (firstException != null) {
                    ex.addSuppressed(firstException);
                }
                System.out.println(ex.getMessage());
            }
    
            catch (TypeExpection ex) {
                System.out.println(ex.getMessage());
            }
        }
    }

    public static class AmountOfIntegersException extends Exception{
        public AmountOfIntegersException(){
            super("Wrong amount of inputs");
        }
    }

    public static boolean valid(String[] array){
        boolean flag = true;
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j < array[i].length(); j++){
                if (!(array[i].charAt(j)>='0' && array[i].charAt(j)<='9')){
                    flag = false;
            }
            }
        }
        return flag;
    }

    public static class TypeExpection extends NullPointerException{
        public TypeExpection(){
            super("Wrong types of inputs");
        }
    }
}