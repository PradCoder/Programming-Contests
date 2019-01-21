/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tandembicycle;

/**
 *
 * @author User
 */
import java.util.*;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int question = Integer.parseInt(scan.nextLine());
        int arraySize = Integer.parseInt(scan.nextLine());
        String Dmojistan[] = (scan.nextLine()).split(" ");
        String Pegland[] = (scan.nextLine()).split(" ");
        int dput[]= new int[arraySize];
        int pput[] = new int[arraySize];
        for (int i = 0; i < Dmojistan.length; i++) {
            dput[i] = Integer.parseInt(Dmojistan[i]);
            pput[i] = Integer.parseInt(Pegland[i]);
        }
        Arrays.sort(dput);
        Arrays.sort(pput);
        int ans = 0;
        if(question==1){
        ans = method1(dput,pput);
        }else{
        ans = method2(dput,pput);
        }
        System.out.println(ans);
        // TODO code application logic here
    }

    private static int method1(int[] dput, int[] pput) {
       int min = 0;
        for (int i = 0; i < dput.length; i++) {
             min += Math.max(dput[i],pput[i]);
        }
     return min;
    }

    private static int method2(int[] dput, int[] pput) {
        int max = 0;
        for (int i = 0; i < dput.length; i++) {
             max += Math.max(dput[dput.length-1-i],pput[i]);
        }
        return max;
    }
    
}
