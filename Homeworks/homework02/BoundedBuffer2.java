public class BoundedBuffer {
    private Object[] buffer = new Object[20]; // arbitrary size
    private int numOccupied = 0;
    private int firstOccupied = 0;
    

    public synchronized void insert(Object o)
    throws InterruptedException
    {
        while(numOccupied == buffer.length) {
        // wait for space
            wait();
        }
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        numOccupied++;
        // in case any retrieves are waiting for data, wake them
        if(numOccupied == 1){
        notifyAll();
        }

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
        if(numOccupied == buffer.length){
            notifyAll();
        }
        return retrieved;
    }
}
