import java.util.List;
import java.util.ArrayList;

public class Main{

    private static final int N = 10;

    public static void main (String args[]) throws InterruptedException {


        Bank bank = new Bank();
        List<Thread> threads = new ArrayList<>(N);
        Thread aux;

        for(int i = 0; i < N; i++){
            threads.add(aux = ( new Thread( new Deposita(100, 1000, bank))));
            aux.start();
        }

        for(int i = 0; i < N; i++)
            threads.get(i).join();

        System.out.println("Account balance: " + bank.balance() + " €");
    } 


}