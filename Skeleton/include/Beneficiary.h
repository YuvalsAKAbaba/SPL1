#ifndef   BENEFICIARY_H
#define   BENEFICIARY_H
#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;



class Beneficiary {
    public:
        Beneficiary::Beneficiary(int id, const string &name, int locationDistance, int maxRequests)
            :id(id), name(name), locationDistance(locationDistance), maxRequests(maxRequests), requestsId(maxRequests, 0){
        }
        const string &getName() const{return name;}
        int getId() const{return id};
        int getBeneficiaryDistance() const{return locationDistance;}
        int getMaxRequests() const{return maxRequests;} //Returns maxRequests
        int getNumRequests() const{
            int madeReq=0;
            for(int i=0;i<requestsId.size();i++){
                if(requestsId[i]!=0) madeReq++; //Initialize request vectors to 0 if no request was given
            }
        } //Returns num of requests the Beneficiary has made so far
        bool canMakeRequest() const{
            if(getNumRequests()<maxRequests) return true;
            else return false;
            } //Returns true if the Beneficiary didn't reach max requests
        const vector<int> &getRequestsIds() const;
        int addRequest(int RequestId); //return RequestId if request was added successfully, -1 otherwise

        virtual Beneficiary *clone() const = 0; // Return a copy of the Beneficiary

        
    private:
        const int id;
        const string name;
        const int locationDistance;
        const int maxRequests;
        vector<int> requestsId;
};


class HospitalBeneficiary: public Beneficiary {
    public:
        HospitalBeneficiary(int id, const string &name, int locationDistance, int maxRequests);
        HospitalBeneficiary *clone() const override;
    
    private:
        
};

class ClinicBeneficiary: public Beneficiary {
    public:
        ClinicBeneficiary(int id, const string &name, int locationDistance, int maxRequests);
        ClinicBeneficiary *clone() const override;
    
    private:
        
};
#endif