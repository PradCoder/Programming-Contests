/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package triangletimes;

/**
 *
 * @author User
 */
import javax.swing.*;

public class Triangletimes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int x = Integer.parseInt(JOptionPane.showInputDialog("Input angle"));
        int y = Integer.parseInt(JOptionPane.showInputDialog("Input angle"));
        int z = Integer.parseInt(JOptionPane.showInputDialog("Input angle"));
        String phrase = "Error";
        if (x + y + z == 180) {
            if (x == 60 && y == 60 && x == 60) {
                phrase = "equilateral";
            } else if (x == y || y == z || x == z) {
                phrase = "Isosceles";
            } else {
                phrase = "Scalene";
            }
        }
        System.out.println(phrase);
        // TODO code application logic here
    }

}
