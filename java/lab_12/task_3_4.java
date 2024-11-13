import java.io.*;
public class task_3_4 {
    public static void main(String[] args) {
        Throwable firstException = null;
        try(FileInputStream in = new FileInputStream("input.txt");
        FileOutputStream out = new FileOutputStream("output.txt")) {

        byte[] buffer = new byte[in.available()];
            in.read(buffer);
            String number = new String(buffer);
            String[] numbers = number.split(" ");
            if (numbers.length != 2)
            {
                throw new WrongAmountOfArg();
            }

            boolean integer = valid(numbers);
            if (!(integer))
            {
                throw new NotIntegerExpection();
            }

            if (Double.parseDouble(numbers[1]) == 0.0) {
                throw new ArithmeticException("Division by zero");
            }

            else {
                double answer = Double.parseDouble(numbers[0]) / Double.parseDouble(numbers[1]);
                System.out.println(answer);
            }

        } 
        catch (IOException ex) {
        System.out.println(ex.getMessage());
        }

        catch (WrongAmountOfArg ex) {
            firstException = ex;
            System.out.println(ex.getMessage());
        }

        catch (NotIntegerExpection ex) {
            System.out.println(ex.getMessage());
        }

        catch (ArithmeticException ex){
            System.out.println(ex.getMessage());
        }

        finally {
            try {
                fileIn.close();
            } catch (NullPointerException npe) {
                if (firstException != null) {
                    npe.addSuppressed(firstException);
                }
                throw npe;
            }
        }
    }

    public static class WrongAmountOfArg extends Exception{
        public WrongAmountOfArg(){
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

    public static class NotIntegerExpection extends Exception{
        public NotIntegerExpection(){
            super("Wrong types of inputs");
        }
    }
}