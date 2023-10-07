import java.util.*;

class Producer implements Runnable {
    private Queue<String> Buff;
    private Object lock;
    
    public Producer(Queue<String> Buff, Object lock) {
        this.Buff = Buff;
        this.lock = lock;
    }
    
    public void run() {
        Scanner scanner = new Scanner(System.in);
        String input;
        
        do {
            System.out.print("Enter a string (or 'Stop' to exit): ");
            input = scanner.nextLine();
            
            synchronized (lock) {
                Buff.offer(input);
                lock.notify();
            }
            
        } while (!input.equals("Stop"));
        
        scanner.close();
    }
}

class Consumer implements Runnable {
    private Queue<String> Buff;
    private Object lock;
    
    public Consumer(Queue<String> Buff, Object lock) {
        this.Buff = Buff;
        this.lock = lock;
    }
    public void run() {
        while (true) {
            synchronized (lock) {
                while (Buff.isEmpty()) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                
                String data = Buff.poll();
                System.out.println("Consumed: " + data);
                
                if (data.equals("Stop")) {
                    break;
                }
            }
        }
    }
}

public class question16 {
    public static void main(String[] args) {
        Queue<String> Buff = new LinkedList<>();
        Object lock = new Object();
        
        Thread producer = new Thread(new Producer(Buff, lock));
        Thread consumer = new Thread(new Consumer(Buff, lock));
        
        producer.start();
        consumer.start();
    }
}