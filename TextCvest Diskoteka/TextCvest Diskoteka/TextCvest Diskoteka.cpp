#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

#define WRAP cout << endl
#define TIP  cout << "************" << endl
#define PLAYER_NAME cout << *name << ':' << ' '

inline void setName(string name);
void drawChurch();
void startScreen();
void createPlayer(string* name, int* age, char* gender);
void meetingWithNeighbor(string* name, int* age, char* gender, string* neighborName);

int main()
{
    srand((time(NULL)));

    string userName;
    int ageOfPlayer;
    char gender;

    string neighborName;

    startScreen();
    createPlayer(&userName, &ageOfPlayer, &gender);
    meetingWithNeighbor(&userName, &ageOfPlayer, &gender, &neighborName);

    WRAP;
    return 0;
}

inline void setName(string name)
{
    cout << name << ':' << ' ';
}

void drawChurch()
{
    const int HEIGHT = 35;

    string church[HEIGHT] = {
        "_____________________¶",
        "____________________¶¶¶",
        "_____________________¶",
        "____________________¶¶¶",
        "___________________¶¶_¶¶",
        "__________________¶¶___¶¶",
        "_________________¶¶_____¶¶",
        "________________¶¶_______¶¶",
        "_______________¶¶_________¶¶",
        "_______________¶___________¶",
        "_______________¶___________¶",
        "_______________¶___________¶",
        "_______________¶¶_________¶¶",
        "________________¶¶¶¶¶¶¶¶¶¶¶",
        "_________________¶¶¶¶¶¶¶¶¶",
        "________________¶_________¶",
        "________¶¶¶¶¶¶¶¶¶_________¶_______¶",
        "_______¶§§§§§§§§¶____¶____¶______¶§¶",
        "______¶§_§_§_§_§¶___¶¶¶___¶_____¶§¶§¶",
        "_____¶§_§_§_§_§_¶__¶_¶_¶__¶____¶§¶_¶§¶",
        "____¶___________¶_¶__¶__¶_¶___¶§¶___¶§¶",
        "___¶____________¶_¶__¶__¶_¶__¶§¶__§__¶§¶",
        "__¶_____________¶_¶__¶__¶_¶_¶§¶__§§§__¶§¶",
        "_¶______________¶_¶__¶__¶_¶¶§¶__§§§§§__¶§¶",
        "¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶__¶__¶_¶§¶__§§§§§§§__¶§¶",
        "_¶______________¶_¶__¶__¶_¶_¶_§§§§§§§§§__¶¶¶",
        "_¶__§§__§§__§§__¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶¶¶_§_¶¶¶",
        "_¶__§§__§§__§§_¶¶___________¶¶¶_______¶_§_¶",
        "_¶__§§__§§__¶¶¶_______________¶¶______¶_§_¶",
        "_¶__§§__§¶¶¶___¶¶¶¶¶____________¶¶____¶_§_¶",
        "_¶__§§¶¶¶___________¶¶¶¶__________¶¶__¶_§_¶",
        "_¶__¶¶__________________¶¶__________¶¶¶_§_¶",
        "_¶_¶______________________¶¶___________¶¶__¶",
        "¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____§§___§§§§§_§§§§§§§§§§§"
    };

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << church[i] << endl;
    }
}

void startScreen()
{
    cout << "WELCOME!\n";
    WRAP;
    cout << "This story about gay who lives in HAbbAr0VsK. \n";
    cout << "This is the city in Russia, famouse 46 President of The USA , which name is Miron Fedorovich was born there.\n";
    cout << "We gotta tell u an very exciting tale about person who recovored battle RAP in WorLd.\n";
    TIP;
    cout << "All your decisions will influence the future game.\n";
    TIP;
    WRAP;

    drawChurch();
}

void createPlayer(string *name, int *age, char *gender)
{
    string randNames[10] =
    {
        "Oxxxymiron",
        "MC Batman",
        "The Father of Kerambit",
        "John Cena",
        "Postman Goddan",
        "Drapa",
        "Post`roni4niy Zayac",
        "INSHALAH",
        "Pasha Tech"
    };

    bool choice{};
    int temp{0};

    cout << "Let's get acquainted! What is your name?\n";
    cout << "My name is: ";
    cin >> *name;
    cout << "Nice to meet you! You said " << *name << " , isn`t it?\n";
    TIP;
        cout << "1 - Yes / 0 - No\n";
    TIP;
    cin >> choice;

    TIP;
    cout << "Some names will influence the future rap Battles.\n";
    TIP;
    
    while (!choice)
    {
        if (temp >= 5)
        {
            *name = randNames[rand() % 10];
            break;
        }
        WRAP;
        cout << "Enter  your name: ";
        cin >> *name;
        cout << "You said " << *name << " , isn`t it?\n";
        cin >> choice;

        temp++;
    }

    cout << "How old are you?\n";
    PLAYER_NAME;
    cout << "I am ";
    cin >> *age;

    if (!*age)
    {
        system("color 16");
        WRAP;
        cout << "VcbO yasno Adminy 0 l`et!\n";
        WRAP;
        system("pause");
        exit(0);
    }

    cout << "What kind of sex partners do u prefer?";
    TIP;
        cout << "1 - Mens / 2 - Womans / 3 - Anime Girlz\n";
    TIP;
    cin >> *gender;

    if (*gender == '3')
    {
        WRAP;
        cout << "I have a SURPRIZE for YOU!\n";
        cout << "iuuqt://xxx.dbsuppoqpsowjefpt.dpn/wjefpt/tusbjhiu/uffo-qpqvmbs.iunm\n";
    }

    system("pause");
}

void meetingWithNeighbor(string* name, int* age, char* gender, string*  neighborName)
{
    const int NAMES = 5;
    string neighborsName[NAMES] =
    {
        "Sergey",
        "Noize MC",
        "ONGEL",
        "Danya Barans",
        "Shapik"
    };

    *neighborName = neighborsName [rand() % NAMES];

    WRAP;

    setName(*neighborName);
    cout << "Wake up bruh, today is very important day. We gotta go the our PTUniversity.\n";

    PLAYER_NAME;
    cout << "Aaargh, where am I?! :O";

    setName(*neighborName);
    cout << "V pizde, nahyu ti na pendoskom govorish, eblan?\n";


 }