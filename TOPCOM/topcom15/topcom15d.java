// reset
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class topcom15d{
	
	public static void main(String[] args){
        BigInteger z = new BigInteger("0");
        BigInteger one = new BigInteger("1");
        BigInteger[] resp = new BigInteger[105];
		
        Scanner s = new Scanner(new BufferedReader (new InputStreamReader(System.in)));

        resp[0] = z;
        resp[1] = one;
        for(int i=2; i<=100; i++)
        {
            resp[i] = BigInteger.valueOf(i).multiply(resp[i-1]);
        }

		while(s.hasNext()){
            int n = s.nextInt();
            if(n<0 || n>100)
                break;
            System.out.println(resp[n]);
		}
		
		s.close();
	}
};