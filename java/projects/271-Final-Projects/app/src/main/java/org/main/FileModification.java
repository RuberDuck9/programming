package org.main;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Date;

public class FileModification {

    Scanner console = new Scanner(System.in);
    Io io = new Io();
    Date clock = new Date();

    public void initializeLog(String filePath) {

        try (FileWriter fw = new FileWriter(filePath.concat("log.txt"), true)) {
            fw.write("Log file generated using QSO logger v0.0.2");
        } catch (IOException e) {
            System.out.println("Error initializing log file ... quiting");
            e.printStackTrace();
        }

    }
    
    public void logQSO(String filePath) {

        QSO qso = new QSO(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived());

        try (FileWriter fw = new FileWriter(filePath.concat("log.txt"), true)) {
            fw.write("\n" + qso.toString());
        } catch (IOException e) {
            System.out.println("Error adding text ... quiting");
            e.printStackTrace();
        }

    }

    public void logContestQSO(String filePath) {

        Contest contest = new Contest(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived(), io.getTimeOfContestStart(), io.getContestID(), io.getPointsEarned(), io.getConfirmed(), io.getStationType());

        try (FileWriter fw = new FileWriter(filePath.concat("log.txt"), true)) {
            fw.write("\n" + contest.toString());
        } catch (IOException e) {
            System.out.println("Error adding text ... quiting");
            e.printStackTrace();
        }

    }

    public void logSotaQSO(String filePath) {

        Sota sota = new Sota(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived(), io.getTimeOfContestStart(), io.getContestID(), io.getPointsEarned(), io.getConfirmed(), io.getStationType(), io.getSummitReferenceCode(), io.getSummitName());

        try (FileWriter fw = new FileWriter(filePath.concat("log.txt"), true)) {
            fw.write("\n" + sota.toString());
        } catch (IOException e) {
            System.out.println("Error adding text ... quiting");
            e.printStackTrace();
        }

    }

    public void logPotaQSO(String filePath) {

        Pota pota = new Pota(io.getCallsign(), io.getFrequency(), io.getMode(), io.getLocation(), io.getRstSent(), io.getRstReceived(), io.getTimeOfContestStart(), io.getContestID(), io.getPointsEarned(), io.getConfirmed(), io.getStationType(), io.getParkReferenceCode(), io.getParkName());
        try (FileWriter fw = new FileWriter(filePath.concat("log.txt"), true)) {
            fw.write("\n" + pota.toString());
        } catch (IOException e) {
            System.out.println("Error adding text ... quiting");
            e.printStackTrace();
        }

    }

}

