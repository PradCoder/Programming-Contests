/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arrivaltime;

/**
 *
 * @author User
 */
import java.util.*;
import java.text.DecimalFormat;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DecimalFormat num = new DecimalFormat("00");
        Scanner scan = new Scanner(System.in);
        String in = scan.nextLine();
        String Sinput[] = in.split(":");
        int input[] = new int[Sinput.length];
        for (int i = 0; i < Sinput.length; i++) {
            input[i] = Integer.parseInt(Sinput[i]);
        }
        int total = input[0] * 60 + input[1];

        int increment = total + 120;
        int new1 = 0;
        int new2 = 0;
        new1 = 120;//increment - total;
        new2 = new1 * 2;
        if (increment > 15 * 60 && increment < 19 * 60) {
            if (increment > 60 * 4) {
                new2 = (increment - 240) * 2 + 240;
            }
            
            if(total>60*4){
                new2 = new2-(total-15*60);
            }else{
            new2+= (15 * 60 - total);
            }
            total = total + new2 ;
        } else if (increment > 7 * 60 && increment < 10 * 60) {
            if (increment > 60 * 3) {
                new2 = (increment - 180) * 2 + 180;
            }
            if(total>60*3){
              new2 = new2-(total-7*60);
            }else{
               new2+= (7 * 60 - total);
            }
            total = total + new2;
        } else {
            total = total + 120;
        }
        int days = total % (24 * 60);
        int minutes = days % 60;
        int hours = (days - minutes) / 60;
        String phrase = num.format(hours) + ":" + num.format(minutes);
        System.out.println(phrase);
        // TODO code application logic here
    }

}
