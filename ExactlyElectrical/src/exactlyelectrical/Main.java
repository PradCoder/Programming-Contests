/*
 * This question can be solved using if statements and mathematical logic

Concept 1 visualization: the input consists of only two points
because of this one point can be used as the origin(0,0) of a grid
and the other point can be represented on the said grid with horizontal 
and vertical distances relative to the point being used as the origin.
I isolated the distances and represented everything in the positive quadrant.
The total number of moves must be the sum of the horizontal distances and the 
vertical distance.

Concept 2 movement logic: the car can move and only move up,down,left, or right 
to get to destination and also make u-turns; to go from the starting position 
to ending position one must have;
1. Enough electric charge
2. Total number of electric charge should get you to destination by using up total.

The first case is simple to solve.

The second case can be solved by thinking thus:
"If I have extra battery life and I can make uturns I can go back and forth
between the destination and a point adjacent to it."
 */
package exactlyelectrical;

/**
 *
 * @author peama2543
 */
//import package util to get access to scanner class
import java.util.*;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //make(construct) scanner and define input source
        Scanner s = new Scanner(System.in);
        //make two arrays to store coordinates
        //for Starting Coordinates (SC)
        String sSC[] = (s.nextLine()).split(" ");
        //for Ending Coordinates (EC)
        String sEC[] = (s.nextLine()).split(" ");

        //stores battery life
        int ba = Integer.parseInt(s.nextLine());
        //arrays that will store the converted values
        int[] SC = new int[2];
        int[] EC = new int[2];
        //convert and store
        for (int i = 0; i < sSC.length; i++) {
            SC[i] = Integer.parseInt(sSC[i]);
            EC[i] = Integer.parseInt(sEC[i]);
        }
        //calculate the absolute distance(magnitude) between the the two x coordinates
        int distancex = Math.abs(SC[0] - EC[0]);
        //calculate the absolute distance(magnitude) between the the two y coordinates
        int distancey = Math.abs(SC[1] - EC[1]);
        //store these values in an array(not necessary)
        int array[] = {distancex, distancey};

        //o for output
        String o = "";

        //calculates minimum amount of moves necessary
        int taxi = array[0] + array[1];

        //if the battery life is less then the minimum number of moves necessary
        if (taxi > ba) {
            o = "N";
        } else {
            //if the minimum number of moves necessary is odd and the battery life is odd
            if (taxi % 2 == 1 && ba % 2 == 1) {
                o = "Y";
            } //if the minimum number of moves necessary is even and the battery life is even
            else if (taxi % 2 == 0 && ba % 2 == 0) {
                o = "Y";
            } //if battery life is odd and total number of moves is even or vice versa
            else {
                o = "N";
            }

        }
        //displays output
        System.out.println(o);

        // TODO code application logic here
    }

}
