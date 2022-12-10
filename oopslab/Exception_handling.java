public class Exception_handling {

    static void nestedtry() throws ArrayIndexOutOfBoundsException,ArithmeticException{
        int[] randomintegers = {12,15,3,7,19};
        try{
            System.out.println(randomintegers[4]);
            try{
                System.out.println(randomintegers[1]/0);
            }
            catch(ArithmeticException e){
                System.out.println("You can't divide anything with 0 dummy");
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("You can't use an index bigger than the array");
        }
        System.out.println("nestedtry has been executed successfully.\n");
    }

    static void multicatch() throws ArrayIndexOutOfBoundsException,ArithmeticException{
        int[] randomintegers = {12,15,3,7,19};
        try{
            System.out.println(randomintegers[9]);
            System.out.println(randomintegers[1]/0);

        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("You can't use an index bigger than the array");
        }
        catch(ArithmeticException e){
            System.out.println("You can't divide anything with 0 dummy");
        }
        System.out.println("multicatch has been executed successfully.\n");

    }

    static void finallytest() throws ArrayIndexOutOfBoundsException,ArithmeticException{
        int[] randomintegers = {12,15,3,7,19};
        try{
            System.out.println(randomintegers[9]);
            System.out.println(randomintegers[1]/0);

        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("You can't use an index bigger than the array");
        }
        catch(ArithmeticException e){
            System.out.println("You can't divide anything with 0 dummy");
        }
        finally{
            System.out.println("I'm always here no matter what. You can be successful, handled or not handled, I always stay.");
        }
        System.out.println("multicatch has been executed successfully.\n");

    }

    static void trythrowthrows() throws NullPointerException,ArithmeticException{
        int[] randomintegers = null;
        try{
            System.out.println(randomintegers[4]);
            throw new ArrayIndexOutOfBoundsException("lmao");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("You can't use an index bigger than the array");
        }
        catch(NullPointerException e){
            System.out.println("I caught you first you empty bish");
            throw new NullPointerException("hehe you null ass");
        }
        catch(ArithmeticException e){
            System.out.println("You can't divide anything with 0 dummy");
        }
        System.out.println("trythrowthrows has been executed successfully.\n");
    }

    public static void main(String args[]) {
        nestedtry();
        multicatch();
        finallytest();
        trythrowthrows();
    }

}