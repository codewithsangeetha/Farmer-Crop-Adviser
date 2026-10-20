#include<iostream>
#include<string>
using namespace std;

class Farmer {
protected:
    string name;
    float landSize;

public:
    void getFarmerDetails() {
        cout<<"Enter Farmer Name: ";
        cin>>name;
        cout<<"Enter Land Size (in acres): ";
        cin>>landSize;
    }
};

class Crop {
public:
    string name;
    float profit;
};


class CropAdvisor : public Farmer {
private:
    string soilType;
    float rainfall;
    float temperature;
    string season;
    bool dataEntered = false;

public:
    void getInput() {
        getFarmerDetails();

        cout<<"Enter Soil Type (clay/sandy/loamy): ";
        cin>>soilType;

        cout<<"Enter Rainfall (in mm): ";
        cin>>rainfall;

        cout<<"Enter Temperature (°C): ";
        cin>>temperature;

        cout<<"Enter Season (summer/winter/monsoon): ";
        cin>>season;

        dataEntered = true;
    }

    
    void compareCrops() {
        if(!dataEntered) {
            cout<<"\n⚠ Enter details first!\n";
            return;
        }

        Crop crops[4];

        crops[0].name = "Rice";
        crops[1].name = "Wheat";
        crops[2].name = "Millets";
        crops[3].name = "Pulses";

        for(int i=0;i<4;i++) {

            if(crops[i].name == "Rice") {
                if(soilType=="clay" && rainfall>200 && temperature>=20)
                    crops[i].profit = 50000 * landSize;
                else
                    crops[i].profit = 20000 * landSize;
            }

            else if(crops[i].name == "Wheat") {
                if(soilType=="loamy" && temperature>=15 && temperature<=25)
                    crops[i].profit = 45000 * landSize;
                else
                    crops[i].profit = 25000 * landSize;
            }

            else if(crops[i].name == "Millets") {
                if(rainfall<100 && temperature>25)
                    crops[i].profit = 30000 * landSize;
                else
                    crops[i].profit = 20000 * landSize;
            }

            else if(crops[i].name == "Pulses") {
                crops[i].profit = 28000 * landSize;
            }
        }

        cout<<"\n--- Crop Comparison ---\n";
        for(int i=0;i<4;i++) {
            cout<<crops[i].name<<" -> Estimated Profit: Rs."<<crops[i].profit<<endl;
        }

        int best = 0;
        for(int i=1;i<4;i++) {
            if(crops[i].profit > crops[best].profit)
                best = i;
        }

        cout<<"\n✅ Best Crop: "<<crops[best].name;
        cout<<"\n💰 Maximum Profit: Rs."<<crops[best].profit<<endl;
    }

    void riskAnalysis() {
        if(!dataEntered) {
            cout<<"\n⚠ Enter details first!\n";
            return;
        }

        cout<<"\n--- Risk Analysis ---\n";

        if(rainfall < 50 || temperature > 40)
            cout<<"Risk Level: HIGH\n";
        else if(rainfall < 150 || temperature > 30)
            cout<<"Risk Level: MEDIUM\n";
        else
            cout<<"Risk Level: LOW\n";
    }

    
    void fertilizerAdvice() {
        if(!dataEntered) {
            cout<<"\n⚠ Enter details first!\n";
            return;
        }

        cout<<"\n--- Fertilizer Suggestion ---\n";

        if(soilType=="clay")
            cout<<"Use Organic + Nitrogen Fertilizer\n";
        else if(soilType=="sandy")
            cout<<"Use Potassium-rich Fertilizer\n";
        else
            cout<<"Use Balanced NPK Fertilizer\n";
    }
};

int main() {
    CropAdvisor c;
    int choice;

    do {
        cout<<"\n===== Farmer Decision Support System =====\n";
        cout<<"1. Enter Farmer Details\n";
        cout<<"2. Compare Crops & Profit\n";
        cout<<"3. View Risk Analysis\n";
        cout<<"4. Fertilizer Advice\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                c.getInput();
                break;

            case 2:
                c.compareCrops();   
                break;

            case 3:
                c.riskAnalysis();
                break;

            case 4:
                c.fertilizerAdvice();
                break;

            case 5:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}