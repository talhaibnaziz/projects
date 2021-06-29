
public class task2 {
	public int getbest(int a, int b, int c, int d)
	{
		int sum=0;
		if(a>=d && b>=d && c>=d)	sum=a+b+c;
		else if(b>=a && c>=a && d>=a)	sum=b+c+d;
		else if(a>=c && b>=c && d>=c)	sum=a+b+d;
		else if(a>=b && c>=b && d>=b)	sum=a+c+d;
		
		return sum;
	}
	public String getLetergrade(double totalMarks,double credit)
	{
		double per;
		per=totalMarks/credit;
		if(per>=80)	return "A+";
		else if(per>=60)	return "A";
		else if(per>=50) return "B";
		else return "F";
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		task2 student=new task2();
		System.out.println("Best out of three sum is: " + student.getbest(13, 12, 15, 10));
		System.out.println("Grade is: " + student.getLetergrade(240, 3));
	}

}
