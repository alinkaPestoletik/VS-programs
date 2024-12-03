import java.io.*;
public class Task2 {
        public static void main(String[] args) {
            Throwable firstException = null;
            String[] numbers = {};
            valid(numbers);
        }
    
        public static class AmountOfIntegersException extends Exception{
            public AmountOfIntegersException(){
                super("Wrong amount of inputs");
            }
        }
        @Deprecated
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
