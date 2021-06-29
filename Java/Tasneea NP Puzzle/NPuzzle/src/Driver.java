
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author TASNEEA
 */
public class Driver {

    public static void main(String[] args) throws IOException {

        int[][] array = new int[4][4];
        Scanner scanner = new Scanner(new File("src/input.txt"));
             for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                array[i][j] = scanner.nextInt();
            }
        }
        Solver solver = new Solver(array);
        solver.solve();
    }
}
