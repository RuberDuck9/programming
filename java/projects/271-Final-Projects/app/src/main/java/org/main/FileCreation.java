package org.main;

import java.io.File;
import java.util.Scanner;

public class FileCreation {

    Scanner console = new Scanner(System.in);
    FileModification filemodifier = new FileModification();

    public File generateFile(String filePath) {

        File file = new File(filePath.concat("log.txt"));

        return file;

    }

    public void generateMainLog(File file) { //Method to generate a main log file if one is not found

        try {
            file.createNewFile();
            System.out.println("Generated log file successfully...");
        } catch (Exception e) {
            System.out.println("Failed to generate main log file. Have you tried giving r/w permissions to this program?");
        }

    }

    public void checkLogFile(File file, String filePath) {

        if(file.exists() == true) {
            
            System.out.println("Log file found!");

        }
        else {
            System.out.println("Log file not found, would you like to create one? [0/1]");

            if (console.nextInt() == 1) {
                generateMainLog(file);
                filemodifier.initializeLog(filePath);
            }
            else {
                System.out.println("No log file to use, quitting ...");
                System.exit(0);
            }
            
        }
    }

    

}
