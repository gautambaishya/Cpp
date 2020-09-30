import java.util.Scanner;

public class repeatedMulti {
    public static long powerByRepetedMulti(long num,long pow,long mod){
        long pro=1;
        int i=1;
        while(i<=pow){
            pro = pro * num % mod;
            i++;
       }
        return (pro);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Num whose power is to be calculated : ");
        long num = sc.nextInt();
        System.out.println();
        System.out.print("Enter the power : ");
        long pow = sc.nextInt();
        System.out.println();
        System.out.print("Enter the Mod num : ");
        long mod = sc.nextInt();
        System.out.println();

        if(pow>=0){
            long res = powerByRepetedMulti(num, pow, mod);
            System.out.println("The result is : "+res);
        }
        else{
            System.out.println("Enter a positive number");
        }
    }
}