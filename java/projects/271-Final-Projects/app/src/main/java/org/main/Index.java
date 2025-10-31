package org.main;

import java.io.File;
import java.util.ArrayList;

public class Index {
    
    public static void main(String[] args) {

        //Save to file *******

        /* 

        //Object Creation
        Io io = new Io();
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

        while(true) {

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
                    log.logSpecialQSO(filePath);
                    break;
                case 6:
                    log.logSpecialQSO(filePath);
                    break;
                case 7:
                    log.logDXContact(filePath);
                    break;
                case 8:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Enter a valid action");
                    break;
            }
            
        }

        */


        //Print out

        /*

        Io io = new Io();

        QSO qso = new QSO(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived());
        Contest contest = new Contest(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived(), io.getTimeOfContestStart(), io.getContestID(), io.getPointsEarned(), io.getConfirmed(), io.getStationType());

        ArrayList<String> list = new ArrayList<String>();

        list.add(qso.toString());
        list.add(contest.toString());

        System.out.println(list);

        */

    }

}
