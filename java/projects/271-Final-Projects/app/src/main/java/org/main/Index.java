package org.main;

import java.io.File;
import java.util.Scanner;

public class Index {
    
    public static void main(String[] args) {

        //Object Creation
        Io io = new Io();
        Scanner console = new Scanner(System.in);
        FileCreation fileCreator = new FileCreation();
        FileModification log = new FileModification(); 
        
        System.out.println("QSO Log v0.0.1 loaded successfully.");

        //Get the working directory from the user
        String filePath = io.getDirectory();
        System.out.println("Using " + filePath + "..."); 

        //Open an instance of file for the directory selected by user
        File file = fileCreator.generateFile(filePath);

        //Check if a log file exists, if not create one
        fileCreator.checkLogFile(file, filePath); 

        boolean loggerActive = true;

        while(loggerActive == true) {

            switch (io.getAction()) {
                case 1:
                    log.logQSO(filePath);
                    break;
                case 2:
                    log.logContestQSO(filePath);
                    break;
                case 3:
                    log.logPotaQSO(filePath);
                    break;
                case 4:
                    log.logSotaQSO(filePath);
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Enter a valid action");
                    break;
            }
            
        }

        console.close();

    }

}
