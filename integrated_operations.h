#include<iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;


int hashfunction(const string &s){
	int sum{};
	
	for(int i=0; i<s.length(); i++){
		sum = sum + s[i];
	}
	return sum;
}

bool searchsubstring(string S, string s){
	if(s.length()==1){
		for(int i=0; i<S.length(); i++){
			if(s[0]==S[i]){
				return true;
			}
		}
	}
	else{
		bool found = false;
		int Len = S.length();
		int len = s.length();
		int count =0;
		string temp;
		temp.resize(len);
		
		for(int i=0; i<len; i++){
			temp[i] = S[i];
		}
		
		int hashval = hashfunction(s);
		int val = hashfunction(temp);	
		
		
		for(int i=0; i<Len; i++){
			count++;
			if(val==hashval){
				for(int j=0; j<len; j++){
					count++;
					if(s[j]==S[i+j]){
						if(j+1==len){
							found = true;
							break;
						}
					}
				}		
			}
				
			val = (val - (S[i])) + (S[i+len]);
			
			if(found){
				return true;
			}
		}
	
	}
	return false;
}



void invalid(string s){
	cout<<"Invalid "<<s<<"! Please Enter a valid one."<<endl;
}

string capitalize(string s){
	for (int i=0; i<s.length(); i++){
		if(s[i]>=97 && s[i]<=122){
			s[i] = s[i]-32;
		}
	}
	return s;
}

bool checknumvalid(string num){
    if (num.length() < 6 || num.length() > 15){
        return false;
    }
    bool valid;
    if (num[0] == '+' || (num[0] >= 48 && num[0] <= 57)){
        valid = true;
    }
    else{
        valid = false;
    }

    int dashcount = 0;
    for (int i = 1; i < num.length(); i++){
        if ((num[0] >= 48 && num[0] <= 57) || num[i] == '-'){
            valid = true;
        }
        if (num[i] == '-'){
            dashcount++;
        }
    }

    if (dashcount > 3){
        valid = false;
    }

    return valid;
}

bool checknamevalid(string name) // checking if a name is valid or not
{
    if (name.length() > 15 || name.length() < 3)
    {
        return false;
    }
	
	name = capitalize(name);
	
    bool valid;

    for (int i = 0; i <= name.length(); i++)
    {
        if (name[i] >= 65 || name[i] <= 122)
        {
            valid = true;
        }
        else
        {
            return false;
        }
    }

    return valid;
}


struct CallLog {
    string phoneNumber;
    string callType; // Incoming or Outgoing
    time_t startTime; // Start time of the call
    time_t endTime; // End time of the call
    double duration; // Duration of the call in seconds

    CallLog(string number, string type, time_t start, time_t end, double dur)
        : phoneNumber(number), callType(type), startTime(start), endTime(end), duration(dur) {}
};

class CallLogManager {
private:
    vector<CallLog> logs;

public:
    void addCallLog(const string& number, const string& type, time_t start, time_t end, double duration) {
        logs.push_back(CallLog(number, type, start, end, duration));
    }

    // Function to display call logs
    void displayCallLogs() {
        for (const auto& log : logs) {
            cout << "Number: " << log.phoneNumber
                 << ", Type: " << log.callType
                 << ", Start Time: " << asctime(localtime(&log.startTime))
                 << ", End Time: " << asctime(localtime(&log.endTime))
                 << ", Duration: " << log.duration << " seconds"
                 << endl;
        }
    }
};
