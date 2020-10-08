import java.util.List;
import java.util.ArrayList;

public class Main{

    private static final int N = 10;
    private static final int I = 100;


    public static void main(String args[]) throws InterruptedException{

        List<Thread> threads = new ArrayList<>(N);
        Thread aux;

        // Threads em concorrência


        for(int i = 0; i < N; i++){
            threads.add(aux = new Thread (new Print(I)));
            aux.start();
        }

        for(int i = 0; i < N; i++){
            threads.get(i).join();
        }

        System.out.println("fim");
    }
}