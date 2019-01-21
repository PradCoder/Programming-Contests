/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tournamentselection;

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
        int count = 0 ;
        for (int i = 0; i < 6; i++) {
            String in = scan.nextLine();
            if(in.equals("W")){
                count++;
            }
        }
        int group = 1;
        if (count>=5) {
            group=1;
        }else if(count>=3){
            group=2;
        }else if(count>=1){
            group = 3;
        }else{
        group=-1;
        }
        System.out.println(group);
    
        // TODO code application logic here
    }
    
}
