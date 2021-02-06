package g8;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

import g8.TaggedConnection.Frame;

public class Demultiplexer implements AutoCloseable{

    private ReentrantLock lock;
    private HashMap<Integer, Entry> connectionTable;
    private TaggedConnection connection;

    public Demultiplexer(TaggedConnection conn){
        this.connectionTable = new HashMap<>();
        this.lock = new ReentrantLock();
    }

    public void start(){

    }

    public void send(Frame frame) throws IOException{
        send(frame.tag, frame.data);

    }

    public void send(int tag, byte[] data) throws IOException{
        this.connection.send(tag, data);
    }

    public byte[] receive(int tag) throws IOException, InterruptedException{
        this.lock.lock();

        Entry e;
        this.connectionTable.putIfAbsent(tag, e = new Entry(this.lock.newCondition()));

        byte[] r = e.awaitForPoll();

        if(e.awaiters == 0 && e.queue.isEmpty())
            this.connectionTable.remove(tag);

        this.lock.unlock();

        return r;
    }

    public void close() throws IOException{
        this.lock.lock();
        this.connection.close();
    }

    class Entry{
        Condition newMessage;
        ArrayDeque<Frame> queue;
        int awaiters;

        public Entry(Condition c){
            this.newMessage = c;
        }

        public boolean areAwaiting(){
            return this.awaiters > 0;
        }

        public byte[] awaitForPoll() throws InterruptedException{

            this.awaiters++;

            while(this.queue.isEmpty())
                this.newMessage.await();

            this.awaiters--;

            return this.queue.poll().data;
        }

    }

}
