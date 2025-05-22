package org.main;

import java.util.Date;

public class QSO {
    
    protected String contactType;
    protected String callsign;
    protected String frequency;
    protected String mode;
    protected String time;
    protected String location;
    protected String rstSent;
    protected String rstReceived;

    Date clock = new Date();

    public QSO(){
        contactType = "Standard Contact";
        time = clock.toString();
        callsign = "Undefined";
        frequency = "Undefined";
        mode = "Undefined";
        location = "Undefined";
        rstSent = "Undefined";
        rstReceived = "Undefined";
    }

    public QSO(String c, String f, String m, String l, String rs, String rr) {
        
        time = clock.toString();
        contactType = "Standard Contact";
        callsign = c;
        frequency = f;
        mode = m;
        location = l;
        rstSent = rs;
        rstReceived = rr;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received" + rstReceived + "]";
    } 
 
}

class Contest extends QSO {

    protected String timeOfContestStart;
    protected String contestID;
    protected double pointsEarned;
    protected boolean confirmed;
    protected String stationType;

    public Contest(){
        super();
        contactType = "Contest Contact";
        timeOfContestStart = "Undefined";
        contestID = "Undefined";
        pointsEarned = 0;
        confirmed = false;
        stationType = "Undefined";

    }

    public Contest(String c, String f, String m, String l, String rs, String rr, String st, String id, double pe, boolean cf, String stt) {
        super(c, f, m, l, rs, rr);
        contactType = "Contest Contact";
        timeOfContestStart = st;
        contestID = id;
        pointsEarned = pe;
        confirmed = cf;
        stationType = stt;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received" + rstReceived + "] - "
        + "[Time of Contest Start: " + timeOfContestStart + "] - "
        + "[Contest ID: " + contestID + "] - "
        + "[Points Earned: " + pointsEarned + "] - "
        + "[Confirmed: " + confirmed + "] - "
        + "[Station Type: " + stationType + "] - ";
    } 

}

class Sota extends Contest {

    protected String summitReferenceCode;
    protected String summitName;

    public Sota() {
        super();
        contactType = "Sota Contact";
        summitReferenceCode = "Undefined";
        summitName = "Undefined";
    }

    public Sota(String c, String f, String m, String l, String rs, String rr, String st, String id, double pe, boolean cf, String stt, String src, String sn) {
        super(src, f, m, l, rs, rr, st, id, pe, cf, stt);
        contactType = "Sota Contact";
        summitReferenceCode = src;
        summitName = sn;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received" + rstReceived + "] - "
        + "[Time of Contest Start: " + timeOfContestStart + "] - "
        + "[Contest ID: " + contestID + "] - "
        + "[Points Earned: " + pointsEarned + "] - "
        + "[Confirmed: " + confirmed + "] - "
        + "[Station Type: " + stationType + "] - "
        + "[Contact Type: " + contactType + "] - "
        + "[Summit Name: " + summitName + "] - "
        + "[Summit Reference Code: " + summitReferenceCode + "] - ";
    } 

}

class Pota extends Contest {

    protected String parkReferenceCode;
    protected String parkName;

    public Pota() {
        super();
        contactType = "Pota Contact";
        parkReferenceCode = "Undefined";
        parkName = "Undefined";
    }

    public Pota(String c, String f, String m, String l, String rs, String rr, String st, String id, double pe, boolean cf, String stt, String prc, String pn) {
        super(prc, f, m, l, rs, rr, st, id, pe, cf, stt);
        contactType = "Pota Contact";
        parkReferenceCode = prc;
        parkName = pn;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received" + rstReceived + "] - "
        + "[Time of Contest Start: " + timeOfContestStart + "] - "
        + "[Contest ID: " + contestID + "] - "
        + "[Points Earned: " + pointsEarned + "] - "
        + "[Confirmed: " + confirmed + "] - "
        + "[Station Type: " + stationType + "] - "
        + "[Contact Type: " + contactType + "] - "
        + "[Park Name: " + parkName + "] - "
        + "[Park Reference Code: " + parkReferenceCode + "] - ";
    } 

}

class Special extends QSO {

    protected String propogationType;

    public Special(){
        super();
        contactType = "Special Contact";
        propogationType = "Undefined";

    }

    public Special(String c, String f, String m, String l, String rs, String rr, String pt) {
        super(c, f, m, l, rs, rr);
        contactType = "Special Contact";
        propogationType = pt;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received: " + rstReceived + "] - "
        + "[Propogation Type: " + propogationType + "]";
    } 

}

class Dx extends Special {

    protected String distance;

    public Dx(){
        super();
        contactType = "DX Contact";
        distance = "Undefined";
    }

    public Dx(String c, String f, String m, String l, String rs, String rr, String d, String pt) {
        super(c, f, m, l, rs, rr, pt);
        contactType = "DX Contact";
        distance = d;
        propogationType = pt;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received: " + rstReceived + "] - "
        + "[Propogation Type: " + propogationType + "] - "
        + "[Distance: ]" + distance + "]";
    } 

}

class Satellite extends Special {

    protected String satelliteName;
    protected String orbitType;
    protected boolean isDopplerCorrected;

    public Satellite(){
        super();
        contactType = "Satellite Contact";
        satelliteName = "Undefined";
        orbitType = "Undefined";
        isDopplerCorrected = false;
    }

    public Satellite(String c, String f, String m, String l, String rs, String rr, String pt, String sn, String ot, boolean idc) {
        super(c, f, m, l, rs, rr, pt);
        contactType = "Satellite Contact";
        satelliteName = sn;
        orbitType = ot;
        isDopplerCorrected = idc;
    }

    public String toString(){
        return "[" + time + "] - " 
        + "[Contact Type: " + contactType + "] - "
        + "[Callsign: " + callsign + "] - "
        + "[Frequency: " + frequency + "MHz] - "
        + "[Mode: " + mode + "] - "  
        + "[Location: " + location + "] - " 
        + "[Rst Sent: " + rstSent + "] - "
        + "[Rst Received: " + rstReceived + "] - "
        + "[Satellite Name: " + satelliteName + "] - "
        + "[Orbite Type: " + orbitType + "] - "
        + "[Is Doppler Corrected: " + isDopplerCorrected + "] - "
        + "[Propogation Type: " + propogationType + "]";
    } 

}