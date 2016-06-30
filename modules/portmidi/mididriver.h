#pragma once
#include <deque>
#include <mutex>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <map>

struct MidiEvent{
	PmEvent event;
	std::string message;

	MidiEvent(PmEvent e,std::string &m):event(e),message(m){
	}
};

class MidiIn{
public:

	int index;

	PortMidiStream *stream;

	std::queue<MidiEvent> eventStack;
	
	std::stringbuf buffer;
	
	PmError error;
	const char *errorText;

	PmEvent sysEvent;
	std::string emptyString;

	int isOpen=0;
	int isSys=0;

	MidiIn(int id,PortMidiStream *in):index(id),stream(in){
	}
	
	void Close(){
		if(stream){
			Pm_Close(stream);
			stream=nullptr;
		}
	}

	bool bufferSysexByte(int b){
		buffer.sputc(b);
		if (b==0xf7){
			eventStack.push(MidiEvent(sysEvent,emptyString));
			isSys=false;
			return true;
		}
		return false;
	}

	void bufferSysex(int b0,int b1,int b2){
		if (bufferSysexByte(b0)) return;
		if (bufferSysexByte(b1)) return;
		if (bufferSysexByte(b2)) return;
	}

	MidiEvent *currentEvent(){
		if (eventStack.empty()) return nullptr;
		return &eventStack.front();
	}

	int Poll(){

		if (!eventStack.empty()){
			eventStack.pop();
		}

		int result = Pm_Poll(stream);

		if(result<0){
			error=(PmError)result;
			errorText=Pm_GetErrorText(error);
			return -1;
		}
						
		static PmEvent buffer[256];

		if(result>0){
			int n = Pm_Read(stream,buffer,256);		
			for(int i=0;i<n;i++){
				PmMessage message=buffer[i].message;
				int status=Pm_MessageStatus(message);
				int b0=Pm_MessageData1(message);
				int b1=Pm_MessageData2(message);
				if(isSys){
					bufferSysex(status,b0,b1);
				}else{

					if(status==0xf0){
						isSys=true;
						sysEvent=buffer[i];
						bufferSysex(status,b0,b1);
					}else{
						eventStack.push(MidiEvent(buffer[i],emptyString));
					}
				}
			}
		}	
						
		return eventStack.size();
	}

};

class MidiDriver{
	std::mutex mutex;
	std::map<int,MidiIn*> inputs;

public:
	int deviceCount=0;
	const PmDeviceInfo *info;
	PmError error;
	const char *errorText;
	MidiEvent *currentEvent;
	
	MidiDriver(){
		Pm_Initialize();
		Pt_Start(100,0,0);
		deviceCount=Pm_CountDevices();
	}
	
	void Sleep(double duration){
		Pt_Sleep(duration);
	}
	
	void GetInfo(int id){
		info=Pm_GetDeviceInfo(id);
	}
		
	int OpenInput(int id){		

		PortMidiStream *stream;
		error=Pm_OpenInput(&stream, id, nullptr, 512, nullptr, nullptr);
		
		if (error){
			errorText=Pm_GetErrorText(error);			
			printf("error=%d %s\n",error,errorText);
			return -1;
		}
		
		inputs[id]=new MidiIn(id,stream);
		return id;
	}
	
	void CloseDevice(int handle){
		auto input=inputs[handle];
		if(input) input->Close();
		delete input;
		inputs[handle]=nullptr;
	}

	int PollDevice(int handle){		
		auto input=inputs[handle];
		if(input){
			int count=input->Poll();
			if(count>0){
				currentEvent=input->currentEvent();
				return 1;
			}
		}
		return 0;
	}

	int MidiEventData(){
		return currentEvent->event.message;
	}
	
	const char *MidiEventMessage(){
		return currentEvent->message.c_str();
	}
	
	int MidiEventMessageLength(){
		return currentEvent->message.length();
	}
	
	double MidiEventTimestamp(){
		return currentEvent->event.timestamp;
	}

	void *Handle(){
		return (void *)this;
	}
};


/*
PMEXPORT PmError Pm_OpenInput( PortMidiStream** stream,
                PmDeviceID inputDevice,
                void *inputDriverInfo,
                int32_t bufferSize,
                PmTimeProcPtr time_proc,
                void *time_info );

PMEXPORT PmError Pm_OpenOutput( PortMidiStream** stream,
                PmDeviceID outputDevice,
                void *outputDriverInfo,
                int32_t bufferSize,
                PmTimeProcPtr time_proc,
                void *time_info,
                double latency );
*/	
