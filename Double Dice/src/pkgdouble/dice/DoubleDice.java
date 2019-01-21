/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkgdouble.dice;

/**
 *
 * @author User
 */
import javax.swing.*;

public class DoubleDice {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int rounds = Integer.parseInt(JOptionPane.showInputDialog("Enter The Number of Rounds"));
        int ahundred = 100;
        int dhundred = 100;
        for (int i = 0; i < rounds; i++) {
            String input = (JOptionPane.showInputDialog("Enter scores"));
            int index = input.indexOf(" ");
            int antoniapoints = Integer.parseInt(input.substring(0, index));
            int davidpoints = Integer.parseInt(input.substring(index + 1, input.length()));

            if (davidpoints < antoniapoints) {
                dhundred -= antoniapoints;
            } else if (davidpoints > antoniapoints) {
                ahundred -= davidpoints;
            }

        }
        JOptionPane.showMessageDialog(null, ahundred + "\n" + dhundred);
        // TODO code application logic here
    }

}
