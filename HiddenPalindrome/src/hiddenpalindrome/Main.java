/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package hiddenpalindrome;

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
        String in = scan.nextLine();
        boolean state = false;
        int length = 0;
        char[] letters = new char[in.length()];
        for (int k = 0; k <= in.length(); k++) {
        for (int i = k; i <= in.length(); i++) {
        for (int j = i; j <= in.length(); j++) {
           String line = in.substring(i,j);
           state = identify(line); 
           if(state){
           length = (Math.max(line.length(),length));
           }
        }
        }
        }
        System.out.println(length);
        // TODO code application logic here
    }

    private static boolean identify(String in) {
        boolean state = true;
        int length = (in.length()-(in.length()%2))/2;
        for (int i = 0; i < length; i++) {
            if(in.charAt(i)!=in.charAt(in.length()-1-i)){
               state = false;
               i= in.length();
            }
        }
        return state;
    }
    
}
