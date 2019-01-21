/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package partyinvitation;

/**
 *
 * @author User
 */
import javax.swing.*;

public class PartyInvitation {

    public static int input(String msg) {
        int num = Integer.parseInt(JOptionPane.showInputDialog(msg));
        return num;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int numfriends = input("Enter number of friends");
        int rounds = input("Enter number of rounds of removal");
        int friends[] = new int[numfriends];
       
        for (int i = 0; i < friends.length; i++) {
             friends[i] = i+1;
        }
        
        int length = friends.length;
        
        for (int i = 0; i < rounds; i++) {
            int removal = input("Enter place of removal");
            int count = (length-(length%removal))/removal;
            count = length-count;
            int newfriends[] = new int[count];
            int o = 0;
            for (int j = 0; j < length; j++) {
                if(((j+1)%removal)!=0){
                newfriends[o] = friends[j];
                o++;
                }
            }
                friends = newfriends;
                length = friends.length;
          
        }
        for (int i = 0; i < friends.length; i++) {
            System.out.println(friends[i]);
        }
        // TODO code application logic here
    }

}
