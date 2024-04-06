//Student Name: Nathan Wandera
//LSU ID: 891973040

package RecursionProject;

public class Fibonacci {
    

    public static long recursiveFib(int fib)
    {   
        if (fib <= 1)
        {
            return fib;
        }
        else
        {
            return(recursiveFib(fib - 1) + recursiveFib(fib - 2));
        }
    }
    
    public static long iterativeFib(int fib)
    {
        long n = 0;
        long n2 = 1;
        long n3 = 0;

        for(int i = 1; i < fib; ++i)
        {
            n3 = n + n2;     
            
            n = n2;
            n2 = n3;

        }
        
        return n3;
    }
    

    public static void main(String[] args)
    {
        
        System.out.printf("%-10s%-15s%-20s%-10s\n", "x", "fib(x)", "Recursive(ns)", "Iterative(ns)");
        System.out.println("==========================================================");
        
        for(int i = 10; i <= 50; i += 10) {
        //Calculate time in nanosecond for recursive Fibonacci
        long start = System.nanoTime();
        Fibonacci.recursiveFib(i);  
        long elapsedRec = System.nanoTime() - start;
        //Calculate time in nanosecond for iterative Fibonacci
        start = System.nanoTime();
        long fib = Fibonacci.iterativeFib(i);
        long elapsedIter = System.nanoTime() - start;
        System.out.printf("%-10d%-15d%,-20d%,-10d\n",i, fib, elapsedRec, elapsedIter);
        }
        System.out.println("==========================================================");  
        
    }
}
