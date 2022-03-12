import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
 
public class Solution implements Runnable {
 
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");
 
    public static void main(String[] args) {
        new Thread(null, new Solution(), "", 256 * (1L << 20)).start();
    }
 
    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            if (System.getProperty("ONLINE_JUDGE") != null) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            }
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }
 
    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
 
    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }
 
    long readLong() throws IOException {
        return Long.parseLong(readString());
    }
 
    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
 
    // solution
 
    void solve() throws IOException {
        
        int t = readInt();

        while(t-- >0){
            
            int n = readInt();
            int k = readInt()+1;
            int x = readInt();

            String str = readString();
            char[] cs = str.toCharArray();
            StringBuilder sb = new StringBuilder("");

            // int l = 0;
            int factor = 1;
            for(int i=n-1; i>=0; i--){

                if(cs[i] == 'a'){
                    sb.append('a');
                }else{

                    int b = 0;
                    if(factor == 1){
                        b = (x-1) % k;
                    }else{
                        b = (x-1) / factor;
                    }
                    while(b-->0) sb.append('b');
                    factor *= k;
                }
            }

            System.out.println(sb.reverse().toString());
        }
    }
 
}
