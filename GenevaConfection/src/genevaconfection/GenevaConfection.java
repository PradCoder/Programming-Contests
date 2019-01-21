/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package genevaconfection;

/**
 *
 * @author User
 */
import java.util.Scanner;

public class GenevaConfection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = Integer.parseInt(scan.nextLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(scan.nextLine());
            int input[] = new int[n];
            int lake[] = new int[n];
            int branch[] = new int[n];
            int order[] = new int[n];//store
            for (int j = 0; j < n; j++) {
                order[j] = j + 1;
            }//store
            for (int j = n - 1; j >= 0; j--) {
                int in = Integer.parseInt(scan.nextLine());
                input[j] = in;
            }
            sorting(input, lake, branch);

        }
        // TODO code application logic here
    }

    private static void sorting(int[] input, int[] lake, int[] branch) {
        
        int temp1 = 0;        
        int temp2 = 0;
        for(int i = 0;i<input.length;i++){
        if(i==0){
         if(input[i]-lake[i]==1){
            lake[temp1] = input[i];
            temp1++;
         }else{
             branch[temp2]= input[i];
              temp2++;
         }
        }else{
         if(input[i]-lake[temp1]==1){
            temp1++;
            lake[temp1] = input[i];
         }else if(branch[temp2]-lake[temp1]==1){
             temp1++;
             lake[temp1] = branch[temp2];
             temp2--;
         }else{
          temp2++;
          branch[temp2]=input[i];
         }
        }
        }
        
        String phrase = "Y";
        for (int i = 0; i < lake.length; i++) {
        if(lake[i]==0){
        phrase = "N";
        }
        }
        System.out.println();
        for (int i = 0; i < lake.length; i++) {
          System.out.print(input[i]+" ");  
        }
        System.out.println();
        for (int i = 0; i < lake.length; i++) {
          System.out.print(branch[i]+" ");  
        }
        System.out.println();
        for (int i = 0; i < lake.length; i++) {
          System.out.print(lake[i]+" ");  
        }
        
        
        //To change body of generated methods, choose Tools | Templates.
    }

}
