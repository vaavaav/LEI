public class Deposita implements Runnable{

    private int amount;
    private int times;
    private Bank bank;

    Deposita(int amount, int times, Bank bank){
        this.amount = amount;
        this.times = times;
        this.bank = bank;
    }

    public void run(){
        for(int i = 0; i < this.times; i++)
            this.bank.deposit(this.amount);
    }

}