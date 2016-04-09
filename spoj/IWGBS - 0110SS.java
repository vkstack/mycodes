import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
class X
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
		int i,n=s.nextInt();
		BigInteger a=new BigInteger("1"),b=new BigInteger("1"),c;
		for(i=2;i<=n;i++){
			c=a.add(b);
			a=b;
			b=c;
		}
		System.out.println(a.add(b));
	}
}
