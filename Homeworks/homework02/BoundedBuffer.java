package Homeworks.homework02;

public class BoundedBuffer {
    private Object[] buffer = new Object[20]; // arbitrary size
    private int numOccupied = 0;
    private int firstOccupied = 0;
    
    /* invariant: 0 <= numOccupied <= buffer.length
    0 <= firstOccupied < buffer.length
    buffer[(firstOccupied + i) % buffer.length]
    contains the (i+1)th oldest entry,
    for all i such that 0 <= i < numOccupied */

    public synchronized void insert(Object o)
    throws InterruptedException
    {
        while(numOccupied == buffer.length)
        // wait for space
            wait();
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        numOccupied++;
        // in case any retrieves are waiting for data, wake them
        notifyAll();
    }
    public synchronized Object retrieve()
    throws InterruptedException
    {
        while(numOccupied == 0)
        // wait for data
            wait();
        Object retrieved = buffer[firstOccupied];
        buffer[firstOccupied] = null; // may help garbage collector
        firstOccupied = (firstOccupied + 1) % buffer.length;
        numOccupied--;
        // in case any inserts are waiting for space, wake them
        notifyAll();
        return retrieved;
    }

    public static void main(String[] args){
        BoundedBuffer buff = new BoundedBuffer();
        try {
            buff.insert("Hello");
            buff.insert("Hi");
            buff.insert("buff");
            buff.retrieve();
            buff.retrieve();
            buff.retrieve();
            Object obj1 = buff.retrieve();
            Object obj2 = buff.retrieve();
            Object obj3 = buff.retrieve();
            
            //Check that the retrieved elements are the same as the ones inserted
            System.out.print(obj1.equals("Hello"));
            System.out.print(obj2.equals("Hi"));
            System.out.print(obj3.equals("buff"));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //Retrieve elements from the buffer
        
    }
}
