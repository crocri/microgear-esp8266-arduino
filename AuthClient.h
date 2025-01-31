/*
  MicroGear-Arduino-ESP8255 library
   NetPIE Project
   http://netpie.io
*/

#ifndef AUTHCLIENT_H
#define AUTHCLIENT_H

#include <ESP8266WiFi.h>
#include "Client.h"
#include "SHA1.h"
//#include "debug.h"

#define GEARAUTHPORT 8080
#define GEARAUTHSECUREPORT 8081

#define MAXVERIFIERSIZE         32
#define MAXGEARAUTHSIZE         32
#define TOKENSIZE               16
#define TOKENSECRETSIZE         32
#define MAXHEADERLINESIZE       350
#define MAXPAYLOADLINESIZE      350
#define NONCESIZE               16
#define MAXSIGNATUREBASELENGTH  512
#define _REQUESTTOKEN           1
#define _ACCESSTOKEN            2

class AuthClient {
    public:
        AuthClient(Client&);
        virtual ~AuthClient();

        static void randomString(char* ,int);
        void init(char*, char*, char*,unsigned long);
        bool connect(bool);
        char *authendpoint;
        void stop();
        void write_P(const char[]);
        void writeln_P(const char[]);
        void write(const char*);
        void writeln(const char*);		
        bool readln(char*, size_t);
        int getGearToken(char, char*, char*, char*, char*, char*, char*, char *, const char*, char*, char*);
    private:
        Client* client;
        char* appid;
        char* gearid;
        char* scope;
        bool securemode;
        void writeout(const char*, bool, bool);
        char* append(char*, const char*, char);
        char* append_P(char*, char*, char);
        char* encode(char*, char);
        char* encode(char*, const char*);
        char* strtail(char*);
        void strcat(char*, const char*);
        void addParam(char*, const char*, const char*, bool);
        unsigned long bootts;
};
#endif
