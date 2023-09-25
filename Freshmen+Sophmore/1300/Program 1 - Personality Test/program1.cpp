/*******************************************************************
	Title: 		program1.cpp
	Author: 	Mason Lauderdale
	Date:  		Feb 15, 2022.
	Purpose: 	Test user's personality with 12 questions.
********************************************************************/

#include <iostream> 
#include <iomanip>
using namespace std; 

int main() {

    // Personality Types
    int introvert = 0;
    int extrovert = 0;
    int positive = 0;
    int negative = 0;
    int silly = 0;
    int serious = 0;
    int spontaneous = 0;
    int planner = 0;

    char userChoice;
    bool execute = true; 

    while (execute == true) {
        // Home Screen
        cout << "\n\n\n";
        cout << setfill('-') << setw(40) << "\n";
        cout << setfill(' ')<< setw(27) << "Personality Test\n";
        cout << setfill('-') << setw(40) << "\n";
        cout << "\nYou will answer twelve questions that will indentify your personality type.\n\n";

        // Question 1
        cout << "\n1. When you are at a party you...\n";
        cout << "\tA. Like meeting tons of new people.\n"
        << "\tB. Only talk to your close friends.\n" 
        << "\tC. I'm too scared to go to parties.\n"
        << "\tD. Be the center of attention.\n\n";

        // Q1 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                extrovert += 1;
                break;
            case 'B':
                introvert += 1;
                break;
            case 'C':
                introvert += 2;
                break;
            case 'D':
                extrovert += 2;
                break;
        }

        // Question 2
        cout << "\n2. Someone accidently bumps into you and you fall to the ground! You...\n";
        cout << "\tA. Yell at them and tell them to watch where they are going or else!\n"
        << "\tB. Apologize and help them up.\n"
        << "\tC. You don't care, you have other things to do.\n"
        << "\tD. Offer to buy them a coffee to apologize.\n\n";

        // Q2 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                negative += 2;
                break;
            case 'B':
                positive +=1;
                break;
            case 'C':
                negative += 1;
                break;
            case 'D':
                positive += 2;
                break;
        }

        // Question 3
        cout << "\n3. When do your friends laugh at you?\n";
        cout << "\tA. When I say something serious, but they think i'm just playing.\n"
        << "\tB. When I tell them a good joke I made.\n"
        << "\tC. I never joke around, so they never laugh at me.\n"
        << "\tD. When I pull an elaborate prank on them.\n\n";

        // Q3 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                serious += 1;
                break;
            case 'B':
                silly +=1;
                break;
            case 'C':
                serious += 2;
                break;
            case 'D':
                silly += 2;
                break;
        }

        // Question 4
        cout << "\n4. When on vaction you...\n";
        cout << "\tA. Have an exact plan for every minute of the trip.\n"
        << "\tB. Just walk around and see what you find.\n"
        << "\tC. Look up popular spots before the trip and make a basic route.\n"
        << "\tD. It's vaction! Planning for the trip is work, just relax and do whatever you want.\n\n";

        // Q4 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                planner += 2;
                break;
            case 'B':
                spontaneous += 1;
                break;
            case 'C':
                planner += 1;
                break;
            case 'D':
                spontaneous += 2;
                break;
        }

        // Question 5
        cout << "\n5. When you have to make a speech infront of a group...\n";
        cout << "\tA. You talk infront of people everyday, it's a breeze!\n"
        << "\tB. Be super nervous every second leading up to the speech.\n"
        << "\tC. Know you're too scared to do it and just don't show up.\n"
        << "\tD. Be pumped you get the chance to speak infront of so many people!\n\n";

        // Q5 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                extrovert += 1;
                break;
            case 'B':
                introvert +=1;
                break;
            case 'C':
                introvert += 2;
                break;
            case 'D':
                extrovert += 2;
                break;
        }

        // Question 6
        cout << "\n6. You got a 60 on your test, your reaction is...\n";
        cout << "\tA. Who cares? It's just one test.\n"
        << "\tB. Blame the teacher and say it's unfair.\n"
        << "\tC. You tried your best, so you are sastisfied.\n"
        << "\tD. Be grumpy for the remainder of the day.\n\n";

        // Q6 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                positive += 1;
                break;
            case 'B':
                negative += 2;
                break;
            case 'C':
                positive += 2;
                break;
            case 'D':
                negative += 1;
                break;
        }

        // Question 7
        cout << "\n7. What kind of movies are your favorite?\n";
        cout << "\tA. You love to laugh, so always comedies!\n"
        << "\tB. A drama or documentary about the real world.\n"
        << "\tC. Adventure movie with some good humor.\n"
        << "\tD. A long, drawn out love story with a tragic ending.\n\n";

        // Q7 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                silly += 2;
                break;
            case 'B':
                serious += 2;
                break;
            case 'C':
                silly += 1;
                break;
            case 'D':
                serious += 1;
                break;
        }

        // Question 8 
        cout << "\n8. How do you feel about suprises?\n";
        cout << "\tA. You love any type of suprise!\n"
        << "\tB. Anything unexecpted is bad.\n"
        << "\tC. You enjoy suprises, as long as you are the one suprising someone else.\n\n";

        // Q8 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                spontaneous += 2;
                break;
            case 'B':
                serious += 2;
                break;
            case 'C':
                spontaneous += 1;
                break;
        }

        // Question 9
        cout << "\n9. During a gathering, your friends are talking about something you know nothing about! You...\n";
        cout << "\tA. Don't say anything and wait for the next subject.\n"
        << "\tB. Excuse yourself and go to the bathroom and wait a few minutes\n"
        << "\tC. Change the subject to something you know more about.\n"
        << "\tD. Ask tons questions to learn more about the subject.\n\n";

        // Q9 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                introvert += 1;
                break;
            case 'B':
                introvert += 2;
                break;
            case 'C':
                extrovert += 1;
                break;
            case 'D':
                extrovert += 2;
                break;
        }

        // Question 10
        cout << "\n10. Do you pay attention to the good or bad in people and life?\n";
        cout << "\tA. Look for the good.\n"
        << "\tB. Look for the flaws.\n"
        << "\tC. Always be positive, no matter the good or bad in the situation/people.\n"
        << "\tD. The world is doomed, there is no point looking in the good or bad.\n\n";

        // Q10 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                positive += 1;
                break;
            case 'B':
                negative +=1;
                break;
            case 'C':
                positive += 2;
                break;
            case 'D':
                negative += 2;
                break;

        }

        // Question 11
        cout << "\n11. How do you greet your friend?\n";
        cout << "\tA. Come up and say 'Hi'.\n"
        << "\tB. Run up and hug them.\n"
        << "\tC. Say 'Greetings' and shake their hand.\n"
        << "\tD. Sneak behind them and scare them!\n\n";

        // Q11 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                serious += 1;
                break;
            case 'B':
                silly += 1;
                break;
            case 'C':
                serious += 2;
                break;
            case 'D':
                silly += 2;
                break;
        }

        //Question 12
        cout << "\n12. How is your day laid out?\n";
        cout << "\tA. Just wake up and do your routine, don't think too much about it.\n"
        << "\tB. You have a caldenar with things to do.\n"
        << "\tC. Wake up and do whatever you feel like.\n"
        << "\tD. Follow your To-Do list exactly.\n\n"; 

        // Q12 Response + Handling
        cin >> userChoice;
        switch (userChoice) {
            case 'A':
                spontaneous += 1;
                break;
            case 'B':
                planner += 1;
                break;
            case 'C':
                spontaneous += 2;
                break;
            case 'D':
                planner += 2;
                break;
        }


        // Results 
        cout << "\n\n\n";
        cout << setfill('-') << setw(40) << "\n";
        cout << setfill(' ')<< setw(23) << "Results\n";
        cout << setfill('-') << setw(40) << "\n";

            // Introvert and Extrovert
        if (introvert > extrovert)
            cout << "You are more introverted rather than extroverted." << endl;
        else if (introvert < extrovert)
            cout << "You are more extroverted than you are introverted." << endl;
        else
            cout << "You are neither introverted nor extroverted." << endl;

            // Positive and Negative
        if (positive > negative)
            cout << "You are a postive person." << endl;
        else if (positive < negative)
            cout << "You are a negative person." << endl;
        else 
            cout << "You are neither positive nor negative." << endl;

            // Silly or Serious
        if (silly > serious)
            cout << "You are a silly person." << endl;
        else if (silly < serious)
            cout << "You are a serious person." << endl;
        else 
            cout << "You are neither more silly nor serious." << endl;
        
            // Spontaneous and Planner
        if (spontaneous > planner)
            cout << "You are a spontaneous person." << endl;
        else if (spontaneous < planner)
            cout << "You are more of a planner, rather than spontaneous." << endl;
        else 
            cout << "You are neither spontaneous nor a planner." << endl;

        // Continue or Exit While loop
        cout << "\n\n\nDo You want to take the test again? (y/n)\n";
        cin >> userChoice;

        if (userChoice == 'y')
            execute = true;
        else if (userChoice == 'n')
            execute = false;
    }
    return 0;
}