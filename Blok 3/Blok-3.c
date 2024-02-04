#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string.h>
#define DEFAULT_BUFLEN 4096            /// Makro, kde definujeme velkost prijimacieho buffera.

void primeText()                      /// Funkcia zisti prvociselne pozicie znakov
{
    int len, k=0;
    int podmienka;

    char vstup[50] = "XLOZGP.R.ACLHCOGAGTER";
    char vystup[50];

    len = strlen(vstup);

    for (int i = 2; i < len; i++)
    {
        podmienka = 0;

        for (int j = 2; j < len; j++)
        {
            if (i % j == 0)
                podmienka++;
        }

        if (podmienka == 1)
        {
            vystup[k] = vstup[i - 1];
            k++;
        }
    }
    printf("%s", vystup);
    //return vystup;
}

int computeSum()                                                   /// Funkcia na zistenie zvysku po deleni 5 cislom z ID.
{
    int ID[6] = {1,1,1,2,6,6};
    int sum = 0;
    int reminder;

    for (int i=0; i < 4; i++)
    {
        sum = sum + ID[i];
    }

    reminder = sum%6;

    return reminder + '0';
}

void Posielanie(int iResult, SOCKET ConnectSocket, char sendbuf[4096], FILE* subor)  /// sendbuf[4096] => Buffer (v zasade retazec), kam sa budu ukladat data, ktore chcete posielat.
{
    /// POSIELANIE ///

        //int X=0, Y=40;

        /* HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD point = {X,Y}; */

        iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);

        if (iResult == SOCKET_ERROR)
        {
            printf("send failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
        }

        printf("Bytes Sent: %d\n", iResult);                             /// Vypisanie poctu odoslanych dat.

        printf("%s\n", sendbuf);
        fprintf(subor, "User: %s\n", sendbuf);
}

void Prijimanie(int iResult, SOCKET ConnectSocket, FILE* subor)
{
    /// PRIJIMANIE ///

    int recvbuflen = DEFAULT_BUFLEN;
    char recvbuf[DEFAULT_BUFLEN];
    /*
    int X = 40, Y=10;

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point = {X, Y}; */
    //SetConsoleCursorPosition(console, point);

    //int len = strlen(recvbuf);

    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);             /// Funkcia na príjimanie.

    if ( iResult > 0 )
    {
        printf("Bytes received: %d\n\n", iResult);                    /// Prisli validne data, vypis poctu.
    }

    else if ( iResult == 0 )
    {
        printf("Connection closed\n");                              /// V tomto pripade server ukoncil komunikaciu.
    }

    else
    {
        printf("recv failed with error: %d\n", WSAGetLastError());  /// Ina chyba.
    }

    if (iResult == 132)
    {
        for (int i=0; i < 132; i++)
        {
            recvbuf[i] = recvbuf[i] ^ 55;
        }
    }

    printf("%s\n", recvbuf);
    fprintf(subor, "Morpheus: %s\n", recvbuf);
}

int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 10);
    SetConsoleOutputCP(CP_UTF8);

    FILE* subor;

    WSADATA wsaData;                                                         /// Struktura WSADATA pre pracu s Winsock.
    int iResult;

    /** Initialize Winsock **/

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);                          /// Zakladna inicializacia.

    if (iResult != 0)                                                        /// Kontrola, ci nestala chyba
    {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    struct addrinfo *result = NULL, *ptr = NULL;                             /// Struktura pre pracu s adresami.
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;                                         /// Pracujeme s protokolom TCP/IP.

    iResult = getaddrinfo("147.175.115.34", "777", &hints, &result);         /// Resolve the server address and port.
    if (iResult != 0)                                                        /// Kontrola, ci nenastala chyba.
    {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    else
        printf("getaddrinfo didn't fail...\n");

    SOCKET ConnectSocket = INVALID_SOCKET;                                    /// Vytvorenie socketu a pripojenie sa.

    /* Attempt to connect to the first address returned by
    the call to getaddrinfo */

    ptr = result;

    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol); /// Create a SOCKET for connecting to server => pokus o vytvorenie socketu.

    if (ConnectSocket == INVALID_SOCKET)                                       /// Kontrola, ci nenastala chyba.
    {
        printf("Error at socket(): %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    else
    {
        printf("Error at socket DIDN'T occur..\n");
    }

    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);   /// Connect to server. => pokus o pripojenie sa na server.

    if (iResult == SOCKET_ERROR)                                            /// Kontrola, ci nenastala chyba.
    {
        printf("Not connected to server\n");
    }

    else
    {
         printf("Connected to server!\n");
    }

    if (iResult == SOCKET_ERROR)                                            /// Osetrenie chyboveho stavu.
    {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
        WSACleanup();
        return 1;
    }

    Sleep(250);

    char Reminder = computeSum();

    primeText();

    char Odpoved[17][50] =
    {
        {"Hi"},                       /// Pozdrav
        {"111266"},                   /// ID
        {"What is it ?"},
        {"7545477"},
        {"753421"},
        {Reminder},
        {"333222111"},
        {"123"},
        {"ok"},
        {"48"},
        {"2"},
        {"E.T."},
        {"PRIMENUMBER"},
        {"LOG.CHAT"},                       /// "LOG.CHAT"
        {"Trinity"},
        {"DQPSK"},
        {"16"}
    };

    printf("Reminder is (%c)\n\n", Reminder);

    subor = fopen("C:\\Users\\endyg\\Desktop\\BLOK3\\output.txt", "w");

    for(int i=0; i < 17; i++)
    {
        Posielanie(iResult, ConnectSocket, Odpoved[i], subor);
        Prijimanie(iResult, ConnectSocket, subor);
    }

    closesocket(ConnectSocket);                                     /// Zatvorenie socketu.
    WSACleanup();
    fclose(subor);

    return 0;
}
