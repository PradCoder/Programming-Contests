/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package magicsquares;

/**
 *
 * @author User
 */
import java.util.*;
import java.io.*;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        int grid[][] = new int[4][4];
        int number = 0;
        for (int i = 0; i < 4; i++) {
            String in = scan.nextLine();
            String sRow[] =(in.split(" "));
            for (int j = 0; j < sRow.length; j++) {
                grid[i][j] = Integer.parseInt(sRow[j]);
                if(i==0){
                number+=grid[i][j];
                }
            }
            
        }
       
        String phrase = "magic";
        for (int i = 0; i < 4; i++) {
            int sumOfrow = 0;
            int sumOfColumn = 0;
            for (int j = 0; j < 4; j++) {
                sumOfrow += grid[i][j];
                sumOfColumn += grid[j][i];
            }
            if(sumOfrow!=number||sumOfColumn!=number){
              phrase = "not magic";
              i=4;
            }
        }
        System.out.println(phrase);
        // TODO code application logic here
    }
    
}
