import java.util.Scanner;
public class source {
	public int getDistance(int t)
	{
		return 16*t;
	}
	public int getdif(int t1, int t2)
	{
		return 16*(t2*t2-t1*t1);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Enter time in time:");
		Scanner input=new Scanner(System.in);
		int t=input.nextInt();
		source ob=new source();
		source ob2=new source();
		System.out.println("The distance traversed is: " + ob.getDistance(t));
		System.out.println("The distance traversed is: " + getDistance2(t));
		System.out.println("The distance difference is: " + ob2.getdif(t-1, t));
		System.out.println("The distance difference is: " + getdif2(t-1, t));
	}
	public static int getDistance2(int t)
	{
		return 16*t;
	}
	public static int getdif2(int t1, int t2)
	{
		return 16*(t2*t2-t1*t1);
	}
}