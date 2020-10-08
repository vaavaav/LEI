public class Print implements Runnable{

    private int limit;

    Print (int t) {
        this.limit = t;
    }

    public void run() {
        for(int i = 0; i < this.limit; i++)
            System.out.println(i + 1);
    }    

}