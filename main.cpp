#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Job {
    public:
        string jobName;
        string jobCrystal;  // The crystal that corresponds with the job.
};

Job myListOfJobs[25];

Job myChosenJobs[4];

bool ChoseWind = false;
bool ChoseWater = false;
bool ChoseFire = false;
bool ChoseEarth = false;


void createListOfJobs() {
    Job Knight{"Knight", "Wind"};
    Job Monk{"Monk", "Wind"};
    Job Thief{"Thief", "Wind"};
    Job BlackMage{"Black Mage", "Wind"};
    Job WhiteMage{"White Mage", "Wind"};
    Job BlueMage{"Blue Mage", "Wind"};
    Job RedMage{"Red Mage", "Water"};
    Job TimeMage{"Time Mage", "Water"};
    Job Summoner{"Summoner", "Water"};
    Job Berserker{"Berserker", "Water"};
    Job MysticKnight{"Mystic Knight", "Water"};
    Job Mime{"Mime", "Special"};
    Job BeastMaster{"BeastMaster", "Fire"};
    Job Geomancer{"Geomancer", "Fire"};
    Job Ninja{"Ninja", "Fire"};
    Job Ranger{"Ranger", "Fire"};
    Job Bard{"Bard", "Fire"};
    Job Dragoon{"Dragoon", "Earth"};
    Job Dancer{"Dancer", "Earth"};
    Job Samurai{"Samurai", "Earth"};
    Job Chemist{"Chemist", "Earth"};
    Job Necromancer{"Necromancer", "Sealed"};
    Job Cannoneer{"Cannoneer", "Sealed"};
    Job Gladiator{"Gladiator", "Sealed"};
    Job Oracle{"Oracle", "Sealed"};
    myListOfJobs[0] = Knight;
    myListOfJobs[1] = Monk;
    myListOfJobs[2] = Thief;
    myListOfJobs[3] = BlackMage;
    myListOfJobs[4] = WhiteMage;
    myListOfJobs[5] = BlueMage;
    myListOfJobs[6] = RedMage;
    myListOfJobs[7] = TimeMage;
    myListOfJobs[8] = Summoner;
    myListOfJobs[9] = Berserker;
    myListOfJobs[10] = MysticKnight;
    myListOfJobs[11] = Mime;
    myListOfJobs[12] = BeastMaster;
    myListOfJobs[13] = Geomancer;
    myListOfJobs[14] = Ninja;
    myListOfJobs[15] = Ranger;
    myListOfJobs[17] = Bard;
    myListOfJobs[16] = Dragoon;
    myListOfJobs[18] = Dancer;
    myListOfJobs[19] = Samurai;
    myListOfJobs[20] = Chemist;
    myListOfJobs[21] = Necromancer;
    myListOfJobs[22] = Cannoneer;
    myListOfJobs[23] = Gladiator;
    myListOfJobs[24] = Oracle;
}

void selectNormalRunJobs() {
    int num = 0;
    srand(time(0));
    while (!ChoseWind || !ChoseWater || !ChoseFire || !ChoseEarth) {
        int jobNumber = rand() % 25;
        Job job = myListOfJobs[jobNumber];
        if (job.jobCrystal.compare("Wind") == 0 && !ChoseWind) {
            myChosenJobs[num] = job;
            num++;
            ChoseWind = true;
        } else if (job.jobCrystal.compare("Water") == 0 && !ChoseWater) {
            myChosenJobs[num] = job;
            num++;
            ChoseWater = true;
        } else if (job.jobCrystal.compare("Fire") == 0 && !ChoseFire) {
            myChosenJobs[num] = job;
            num++;
            ChoseFire = true;
        } else if (job.jobCrystal.compare("Earth") == 0 && !ChoseEarth) {
            myChosenJobs[num] = job;
            num++;
            ChoseEarth = true;
        }
    }

}
void selectChaosJobs() {
    srand(time(0));
    for (int x = 0; x < 4; x++) {
        int num = rand() % 25;
        myChosenJobs[x] = myListOfJobs[num];
    }
}
int main() {
    int choice = 0;
    bool properResponse = false;
    createListOfJobs();
    cout << "Hello, welcome to the Final Fantasy V four job fiesta generator. Please select what run you would like to generate." << endl;
    cout << "1 for a normal run" << endl;
    cout << "2 for chaos run" << endl;
    cin >> choice;
    while (properResponse == false) {
        if (choice == 1) {\
            selectNormalRunJobs();
            properResponse = true;
        } else if (choice == 2) {
            selectChaosJobs();
            properResponse = true;
        } else {
            cout << "Invalid answer! Select Again." << endl;
            cin >> choice;
        }
    }
    cout << myChosenJobs[0].jobName << endl;
    cout << myChosenJobs[1].jobName << endl;
    cout << myChosenJobs[2].jobName << endl;
    cout << myChosenJobs[3].jobName << endl;
    return 0;
}
