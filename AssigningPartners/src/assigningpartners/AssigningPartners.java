/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assigningpartners;

/**
 *
 * @author User
 */
import javax.swing.*;

public class AssigningPartners {

    /**
     * @param args the command line arguments
     */
    public static int input(String msg) {
        int num = Integer.parseInt(JOptionPane.showInputDialog(msg));
        return num;
    }

    public static void main(String[] args) {
        int numS = input("Number of students");
        String inputline1 = JOptionPane.showInputDialog("Enter line 1") + " ";
        String inputline2 = JOptionPane.showInputDialog("Enter line 2") + " ";
        String array1[] = inputline1.split(" ");
        String array2[] = inputline2.split(" ");
        String phrase = "bad";
        for (int i = 0; i < numS; i++) {
            if (!array1[i].equals(array2[i])) {
                phrase = "good";
            }
        }
        for (int i = 0; i < numS; i++) {
            for (int j = 0; j < numS; j++) {
                if (array1[i].equals(array2[j])) {
                    if (array2[i].equals(array1[j])) {
                        phrase = "good";
                    } else {
                        phrase = "bad";
                        j = numS;
                        i = numS;
                    }
                }
            }
        }
        System.out.println(phrase);
        // TODO code application logic here
    }

}
