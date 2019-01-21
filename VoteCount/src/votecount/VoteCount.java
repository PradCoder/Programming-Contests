/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package votecount;

/**
 *
 * @author User
 */
import javax.swing.*;
import java.text.*;
public class VoteCount {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DecimalFormat num = new DecimalFormat("#,##0.00");
        int numVote = Integer.parseInt(JOptionPane.showInputDialog(null,"Number of votes"));
        String sequence = JOptionPane.showInputDialog("Enter sequence");
        int count = 0;
        String phrase = "Tie";
        for (int i = 0; i < numVote; i++) {
            if(sequence.charAt(i)== 'A'){
                count++;
            }
        }
        if(numVote-count>count){
           phrase = "B";
        }else if(numVote-count<count){
           phrase = "A";
        }
        System.out.println(phrase);
        JOptionPane.showMessageDialog(null,num.format((double)22/(double)3));
        // TODO code application logic here
    }
    
}
