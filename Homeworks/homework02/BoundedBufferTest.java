public class BoundedBufferTest{
    public static void main(String[] args){
        BoundedBuffer buff = new BoundedBuffer();
        try {
            buff.insert("Hello");
            buff.insert("Hi");
            buff.insert("buff");
            
            //Retrieve elements from the buffer
            Object obj1 = buff.retrieve();
            Object obj2 = buff.retrieve();
            Object obj3 = buff.retrieve();
            
            //Check that the retrieved elements are the same as the ones inserted

            System.out.println(obj1.equals("Hello"));
            System.out.println(obj2.equals("Hi"));
            System.out.println(obj3.equals("buff"));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        
    }
}
