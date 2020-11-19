import java.util.concurrent.locks.ReentrantReadWriteLock;

public class Registo {
    ReentrantReadWriteLock lock = new ReentrantReadWriteLock(); 
    int sum = 0;
    int nums = 0;
    double average = 0;


    public void addNum(int newValue){
        this.lock.writeLock().lock();
        sum += newValue;
        nums++;
        average = sum / nums;
        this.lock.writeLock().unlock();
    }

    public int getSum(){
        try{
            this.lock.readLock().lock();
            return sum;
        }
        finally{
            this.lock.readLock().unlock();
        }
    }

    public double getAverage(){
        try{
            this.lock.readLock().lock();
            return average;
        }
        finally{
            this.lock.readLock().unlock();
        }
    }
    
}
