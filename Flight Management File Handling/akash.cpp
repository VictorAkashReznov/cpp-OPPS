#include <bits/stdc++.h>
using namespace std;
class flight
{
private:
    string FlightNo, SRC, DEST;
    int seatNo;

public:
    flight(){};
    flight(string FlightNo, string SRC, string DEST, int seatNo)
    {
        this->FlightNo = FlightNo;
        this->SRC = SRC;
        this->DEST = DEST;
        this->seatNo = seatNo;
    }
    void AddToDb()
    {
        ofstream out;
        out.open("Flights.txt", ios::app);
        out << FlightNo << " : " << SRC << " : " << DEST << " : " << seatNo << endl;
    }
    int getSeats()
    {
        return seatNo;
    }
    string getFlightNo()
    {
        return FlightNo;
    }
    string getSRC()
    {
        return SRC;
    }
    string getDEST()
    {
        return DEST;
    }
    void reduceSeat()
    {
        seatNo--;
    }
};

class AdminPannel
{
public:
    flight retiveFlightDetail(string line)
    {
        stringstream ss(line);
        string word;
        vector<string> temp;
        while (ss >> word)
        {
            if (word != ":")
            {
                temp.push_back(word);
            }
        }
        flight f1(temp[0], temp[1], temp[2], stoi(temp[3]));
        return f1;
    }
    void FindFlight(string flightName)
    {
        ifstream in("Flights.txt");
        string line;
        while (getline(in, line))
        {
            int pos = line.find(flightName);
            if (pos != string::npos)
            {
                flight f1 = retiveFlightDetail(line);

                cout << "\t\t Flight Name : " << f1.getFlightNo() << endl;
                cout << "\t\t Flight source : " << f1.getSRC() << endl;
                cout << "\t\t Flight Destination : " << f1.getDEST() << endl;
                cout << "\t\t Seats Available : " << f1.getSeats() << endl;
                return;
            }
        }
        cout << "\t\tNo Flight Find\n";
    }
    void AddFlight()
    {

        string flightname, src, dest;
        cout << "\t\tEnter Flight Name\n";
        cin >> flightname;
        cout << "\t\tEnter Source city\n";
        cin >> src;
        cout << "\t\tEnter Destination city\n";
        cin >> dest;
        cout << "\t\tEnter Total Seats\n";
        int seat;
        cin >> seat;
        flight f1(flightname, src, dest, seat);
        f1.AddToDb();
        cout << "\t\tAdd Successful\n";
    }
    void RemoveFlight(string flightName)
    {
        ifstream in("Flights.txt");
        string line;

        ofstream out;
        out.open("temp.txt");
        while (getline(in, line))
        {
            int pos = line.find(flightName);
            if (pos == string::npos)
            {
                out << line;
            }
        }
        in.close();
        out.close();
        remove("Flights.txt");
        rename("temp.txt", "Flights.txt");
        cout << "\t\t Flight removed Successfully\n";
        return;
    }
    void BookTicket(string flightName)
    {
        ifstream in("Flights.txt");
        string line;
        ofstream out;
        out.open("temp.txt");
        flight A1;
        while (getline(in, line))
        {
            int pos = line.find(flightName);
            if (pos != string::npos)
            {
                A1 = retiveFlightDetail(line);
            }
            else
            {
                out << line;
            }
        }
        in.close();
        out.close();
        remove("Flights.txt");
        rename("temp.txt", "Flights.txt");

        if (A1.getSeats() > 0)
        {
            A1.reduceSeat();
            A1.AddToDb();
            cout << "\t\tSeat Booked Successfully\n";
        }
        else
        {
            cout << "\t\t no seat available\n";
        }
    }

public:
};
int main()
{
    bool b1 = true;
    AdminPannel p1;
    while (b1)
    {
        cout << "\t***************AirPort XYZ***********\n";
        cout << "\t\t1.Find Flight\n";
        cout << "\t\t2.Add Flight\n";
        cout << "\t\t3.Remove Flight\n";
        cout << "\t\t4.Book Ticket\n";
        cout << "\t\t5.Exit\n";
        int t;
        cin >> t;
        system("cls");
        if (t == 1)
        {
            string s1;
            cout << "\t\t Enter Flight No: \n";
            cin >> s1;
            p1.FindFlight(s1);
        }
        else if (t == 2)
        {
            cout << "\t\tEnter Flight Details \n";
            p1.AddFlight();
        }
        else if (t == 3)
        {
            string s1;
            cout << "\t\t Enter Flight No: \n";
            cin >> s1;
        }
        else if (t == 4)
        {
            string s1;
            cout << "\t\t Enter Flight No: \n";
            cin >> s1;
        }
        else
        {
            b1 = false;
            cout << "\t***************Thank You***********\n";
        }
    }

    return 0;
}