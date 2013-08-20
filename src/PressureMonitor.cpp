
#include "PressureMonitor.h"


PressureMonitor::PressureMonitor()
{
    this->delay = 1000;
    this->time = ofGetElapsedTimeMillis();
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	serial.setup(0, 9600); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
    
	nTimesRead = 0;
	nBytesRead = 0;
	memset(bytesReadString, 0, 4);
    
    ofAddListener(ofEvents().update, this, &PressureMonitor::onUpdate);
}

void PressureMonitor::onUpdate(ofEventArgs &e)
{
    if (ofGetElapsedTimeMillis() - time >= delay){
        time = ofGetElapsedTimeMillis();
        ofLogNotice("tick");
		// (1) write the letter "a" to serial:
		serial.writeByte('a');
		
		// (2) read
		// now we try to read 3 bytes
		// since we might not get them all the time 3 - but sometimes 0, 6, or something else,
		// we will try to read three bytes, as much as we can
		// otherwise, we may have a "lag" if we don't read fast enough
		// or just read three every time. now, we will be sure to
		// read as much as we can in groups of three...
		
		nTimesRead = 0;
		nBytesRead = 0;
		int nRead  = 0;  // a temp variable to keep count per read
		
		unsigned char bytesReturned[3];
		
		memset(bytesReadString, 0, 4);
		memset(bytesReturned, 0, 3);
		
		while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
			nTimesRead++;
			nBytesRead = nRead;
		};
		
		memcpy(bytesReadString, bytesReturned, 3);
        
        string msg;
        msg += "------------------------------------------\n";
        msg += "nBytes read " + ofToString(nBytesRead) + "\n";
        msg += "nTimes read " + ofToString(nTimesRead) + "\n";
        msg += "read: " + ofToString(bytesReadString) + "\n";
        ofLogNotice(ofToString(msg));
        
    }
    
}