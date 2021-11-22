// artillery.cpp
// Description: A simple game with a little physics
#include <math.h>
#include <time.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int number_killed = 0;
const int kNumShells = 10;
const int KMinDist = 200;
const int kMaxDist = 900;
const double kVelocity = 200.0;
const double kGravity = 32.2;
const double kPi = 3.1415;

// Returns the distance a shot travels
int DistanceCalc (double in_angle) {
    double time_in_air;
    time_in_air = (2.0 * kVelocity * sin(in_angle)) / kGravity;
    return (int) round((kVelocity * cos(in_angle)) * time_in_air);
}

int CheckShot() {
    int distance;
    double angle;
    cout << "Welcome to Artillery." << endl;
    cout << "What Angle?"<< endl;
    if (!(cin >> angle))
    return -1;

    // Convert to radians
    angle = (angle * kPi) / 180.0;
    distance = DistanceCalc(angle);
    return distance;
}
// Random number for enemy
int Initialize() {
    int enemy_position;
    srand (time(NULL));

    enemy_position = rand() % kMaxDist + KMinDist;
    cout << "The enemy is " << enemy_position << " feet away!" << endl;
    return enemy_position;
}

// this plays the game
int main(int number_killed) {
    int enemy, shots, hit;
    int distance;
    shots = kNumShells;
    enemy = Initialize();
    distance = 0;
    hit = 0;
    do {
        distance = CheckShot();
        if (distance == -1) {
            cout << "Enter numbers only..." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
    if (abs(enemy - distance) <= 1) {
        hit++;
        number_killed++;
        cout << "You hit him!" << endl;
        cout << "It took you " << kNumShells - shots + 1 << " shots." << endl;
        cout << "You have killed " << number_killed << " enemies." << endl;

    } else {
        shots--;
        number_killed = hit;
        if (distance > enemy) {
            cout << "You over shot by " << abs(enemy - distance) << endl;
        } else {
            cout << "You under shot by " << abs(enemy - distance) << endl;
        }
    }
    }  while ((shots > 0) && (!(hit)));
    if (shots == 0) {
    cout << "You have run out of ammo..." << endl;
    }
    return number_killed;
}
   // }
  //  while (shots && kNumShells == 10) {
 // cout << "Welcome to Artillery." << endl;
  //  } while (shots && kNumShells != 10) {
//  cout << "You killed " << number_killed << " of the enemy." << endl;
//}
 //   }
//}