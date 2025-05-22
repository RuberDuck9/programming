package org.main;

import java.util.Scanner;

public class Io {

    Scanner console = new Scanner(System.in);

    private String filePath;
    private int useDefault = 1;
    
    public String getDirectory(){ //Find the file path to use
        
        for (int i = 1; i > 0; i--){

            System.out.println("Should QSO Log use this directory for file management:" + System.getProperty("user.dir") + ", or one of your choice? [0/1]");
            useDefault = console.nextInt();

            if (useDefault == 1) {
                filePath = System.getProperty("user.dir");
                filePath = filePath.concat("/");
                return filePath;
            }
            else if (useDefault == 0) {
                System.out.println("What directory would you like to use?");
                console.nextLine();
                filePath = console.nextLine();
                return filePath;
            }
            else {
                System.out.println("Error: Not a valid option");
                i++;
            }

        }

        return filePath;

    }

    public int getAction() {

        System.out.println("What would you like to do?");
        System.out.println("1 - Log a generic contact");
        System.out.println("2 - Log a generic contest contact");
        System.out.println("3 - Log a Pota contact");
        System.out.println("4 - Log a Sota contact");
        System.out.println("5 - Log a Special contact");
        System.out.println("6 - Log a Satellite contact");
        System.out.println("7 - Log a Dx contact");
        System.out.println("8 - Exit");

        return console.nextInt();

    }

    public String getCallsign(){

        System.out.println("Enter the callsign you would like to log");
        return console.nextLine();

    }

    public String getFrequency() {

        System.out.println("What frequency did you use?");
        return console.nextLine();

    }

    public String getMode() {

        System.out.println("What was your mode of contact?");
        return console.nextLine();

    }

    public String getLocation() {

        System.out.println("What location did you contact?");
        return console.nextLine();

    }

    public String getRstSent() {

        System.out.println("What was your rst sent?");
        return console.nextLine();

    }

    public String getRstReceived() {

        System.out.println("What was your rst received?");
        return console.nextLine();

    }

    public String getTimeOfContestStart() {

        System.out.println("When did the contest begin?");
        return console.nextLine();

    }

    public String getContestID() {

        System.out.println("What was your contest ID?");
        return console.nextLine();

    }

    public double getPointsEarned() {

        System.out.println("How many points did the contact earn you? (Enter a number)");
        return console.nextDouble();

    }

    public boolean getConfirmed() {

        System.out.println("Has the contact been confirmed? [0/1]");

        if(console.nextInt() == 0) {
            return false;
        }
        else if(console.nextInt() == 1) {
            return true;
        }
        else {
            System.out.println("Invalid input, assuming not confirmed");
            return false;
        }

    }

    public String getStationType() {

        System.out.println("What type of station did you use?");
        return console.nextLine();

    }   

    public String getSummitReferenceCode(){

        System.out.println("What was your summit reference code?");
        return console.nextLine();

    }

    public String getSummitName() {

        System.out.println("What was the summit name?");
        return console.nextLine();

    }

    public String getParkReferenceCode() {


        System.out.println("What was your park reference code?");
        return console.nextLine();

    }

    public String getParkName() {

        System.out.println("What was the park name?");
        return console.nextLine();
        
    }

    public String getPropogationType() {

        System.out.println("What was the propogation type?");
        return console.nextLine();
        
    }

    public String getDistance() {

        System.out.println("What was the distance?");
        return console.nextLine();
        
    }

    public String getSatelliteName() {

        System.out.println("What was the satellite name?");
        return console.nextLine();
        
    }

    public String getOrbitType() {

        System.out.println("What was the orbit type?");
        return console.nextLine();
        
    }

    public boolean getIsDopplerCorrected() {

        System.out.println("What was the contact doppler corrected? [0/1]");

        if(console.nextInt() == 0) {
            return false;
        }
        else if(console.nextInt() == 1) {
            return true;
        }
        else {
            System.out.println("Invalid input, assuming not confirmed");
            return false;
        }
        
    }

}
